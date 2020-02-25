/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:17:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/26 01:34:33 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_color		get_color(t_spheres	spheres, t_light_sources light_sources,
		t_vector camera, t_vector pixel, int reflection_depth, t_status *status, int x, int y)
{
	t_point		point;
	t_sphere	closest_sphere;
	t_vector	view;
	t_vector	reflect;
	t_color		reflected_color;

	closest_sphere = get_intersection(spheres, camera,
	pixel, DRAW_DISTANCE_MIN, DRAW_DISTANCE_MAX);
	if (closest_sphere.closest == DRAW_DISTANCE_MAX)
		return ((t_color)BACKGROUND_COLOR);
	fill_object_buffer(status, x, y, closest_sphere.id);
	point.xyz = add(camera, multiply_sv(closest_sphere.closest, pixel));
	point.n = substract(point.xyz, closest_sphere.center);
	point.n = multiply_sv(1.0 / length(point.n), point.n);
	point.color = closest_sphere.color;
	point.specular = closest_sphere.specular;
	point.reflective = closest_sphere.reflective;
	view = multiply_sv(-1.0, pixel);
	point.light = get_lightning(point, light_sources, view, spheres);
	point.final_color = multiply_color(point.light, point.color);
	if (reflection_depth == 0 || point.reflective <= 0)
		return (point.final_color);
	reflect = reflect_ray(view, point.n);
	reflected_color = get_color(spheres, light_sources, point.xyz, reflect,
	reflection_depth - 1, status, x, y);
	point.final_color = add_color(multiply_color(1.0 - point.reflective, point.final_color),
	multiply_color(point.reflective, reflected_color));
	return (point.final_color);
}

void		fill_object_buffer(t_status *status, int x, int y, int id)
{
	int	i;
	
	x = IMG_SIZE_W / 2 + x;
	y = IMG_SIZE_H / 2 - y;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	if (i > 0 && status->got_object[i] == FALSE)
	{
		status->object_buffer[i] = id;
		status->got_object[i] = TRUE;
	}
}

t_sphere	get_intersection(t_spheres	spheres,
		t_vector camera, t_vector viewport_pixel, double t_min, double t_max)
{
	int			i;
	t_sphere	closest_sphere;
	double 		closest;

	i = -1;
	closest = t_max;
	closest_sphere.null = 0;
	while (++i < spheres.quantity)
	{
		sphere_intersection(spheres.array[i], camera, viewport_pixel);
		if (spheres.array[i]->t1 >= t_min && spheres.array[i]->t1 <=
		t_max && spheres.array[i]->t1 < closest)
		{
			closest = spheres.array[i]->t1;
			closest_sphere = *spheres.array[i];
			closest_sphere.null = 1;
		}
		if (spheres.array[i]->t2 >= t_min && spheres.array[i]->t2 <=
		t_max && spheres.array[i]->t2 < closest)
		{
			closest = spheres.array[i]->t2;
			closest_sphere = *spheres.array[i];
			closest_sphere.null = 1;
		}
	}
	closest_sphere.closest = closest;
	if (closest_sphere.null == 1)
		closest_sphere.null = 1;
	else
		closest_sphere.null = 0;
	return (closest_sphere);
}

void	sphere_intersection(t_sphere *sphere, t_vector camera, t_vector p)
{	
	t_vector    r;
	double      k1;
	double      k2;
	double      k3;
	double      d;
	
	r = substract(camera, sphere->center);
	k1 = dot(p, p);
	k2 = 2 * dot(r, p);
	k3 = dot(r, r) - sphere->radius * sphere->radius;
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
	{
		sphere->t1 = -1;
		sphere->t2 = -1;
		return;
	}
	sphere->t1 = (-k2 + sqrt(d)) / (2 * k1);
	sphere->t2 = (-k2 - sqrt(d)) / (2 * k1);
}

double	get_lightning(t_point point, t_light_sources light_sources,
t_vector pixel, t_spheres spheres)
{
	int         i;
	double      intensity;
	t_vector    l;
	t_sphere 	shadow;
	double 		t_max;

	intensity = 0.0;
	i = -1;
	while (++i < light_sources.quantity)
	{
		if (light_sources.array[i]->type == LIGHT_TYPE_AMBIENT)
			intensity += light_sources.array[i]->intensity;
		else
		{
			if (light_sources.array[i]->type == LIGHT_TYPE_POINT)
			{
				l = substract(light_sources.array[i]->position, point.xyz);
				t_max = 1;
			}
			else if (light_sources.array[i]->type == LIGHT_TYPE_DIRECTIONAL)
			{
				l = light_sources.array[i]->direction;
				t_max = DRAW_DISTANCE_MAX;
			}
			shadow = get_intersection(spheres, point.xyz, l, 0.000001, t_max);
			if (shadow.null)
				continue;
			intensity += light_sources.array[i]->intensity *
			diffuse(point.n, l);
			if (point.specular)
				intensity += light_sources.array[i]->intensity *
				specular(point.n, l, pixel, point.specular);
		}
	}
	return (intensity);
}

double	diffuse(t_vector n, t_vector l)
{
	double	ndl;

	ndl = dot(n, l);
	if (ndl > 0)
		return (ndl / (length(n) * length(l)));
	else
		return (0);
}

double	specular(t_vector n, t_vector l, t_vector p, double s)
{
	t_vector	r;
	double		rdp;

	r = reflect_ray(l, n);
	rdp = dot(r, p);
	if (rdp > 0)
		return (pow(rdp / (length(r) * length(p)), s));
	else
		return (0);
}

t_vector	reflect_ray(t_vector r, t_vector n)
{
	return (substract(multiply_sv(2.0 * dot(r, n), n), r));
}
