/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:04:49 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/02 18:15:36 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		get_color(t_spheres spheres, t_light_sources light_sources,
		t_vector camera, t_vector pixel, int reflection_depth, t_scene *scene,
		int x, int y)
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
	fill_object_buffer(scene, x, y, closest_sphere.id);
	point.xyz = add(camera, multiply_sv(closest_sphere.closest, pixel));
	if (closest_sphere.type == OBJECT_TYPE_PLANE)
		point.n = multiply_sv(-1, closest_sphere.center);
	else if (closest_sphere.type == OBJECT_TYPE_SPHERE)
		point.n = substract(point.xyz, closest_sphere.center);
	else if (closest_sphere.type == OBJECT_TYPE_CYLINDER)
		point.n = substract(point.xyz, closest_sphere.center);
	else if (closest_sphere.type == OBJECT_TYPE_CONE)
		point.n = substract(point.xyz, closest_sphere.center);
	point.n = normalize(point.n);
	point.color = closest_sphere.color;
	point.specular = closest_sphere.specular;
	point.reflective = closest_sphere.reflective;
	view = multiply_sv(-1.0, pixel);
	point.light = get_lightning(scene, point, view);
	point.final_color = multiply_color(point.light, point.color);
	if (reflection_depth == 0 || point.reflective <= 0)
		return (point.final_color);
	reflect = reflect_ray(view, point.n);
	reflected_color = get_color(spheres, light_sources, point.xyz, reflect,
	reflection_depth - 1, scene, x, y);
	point.final_color = add_color(multiply_color(1.0 - point.reflective,
	point.final_color),
	multiply_color(point.reflective, reflected_color));
	return (point.final_color);
}

// t_point		get_point_properties(t_sphere *object)
// {

// }

void		fill_object_buffer(t_scene *scene, int x, int y, int id)
{
	int	i;

	x = IMG_SIZE_W / 2 + x;
	y = IMG_SIZE_H / 2 - y;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	if (i > 0 && scene->got_object[i] == FALSE)
	{
		scene->object_buffer[i] = id;
		scene->got_object[i] = TRUE;
	}
}

t_sphere	get_intersection(t_spheres spheres, t_vector camera,
			t_vector pixel, double t_min, double t_max)
{
	int			i;
	t_sphere	closest_sphere;
	double		closest;

	i = -1;
	closest = t_max;
	closest_sphere.null = 0;
	while (++i < spheres.quantity)
	{
		if (spheres.array[i]->type == OBJECT_TYPE_PLANE)
			plane_intersection(spheres.array[i], camera, pixel);
		else if (spheres.array[i]->type == OBJECT_TYPE_SPHERE)
			sphere_intersection(spheres.array[i], camera, pixel);
		else if (spheres.array[i]->type == OBJECT_TYPE_CYLINDER)
			cylinder_intersection(spheres.array[i], camera, pixel);
		else if (spheres.array[i]->type == OBJECT_TYPE_CONE)
			cone_intersection(spheres.array[i], camera, pixel);
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

void	plane_intersection(t_sphere *sphere, t_vector camera, t_vector pixel)
{
	double t;
	t_vector n;
	t_vector x;
	
	n = sphere->center;
	x = substract(camera, n);
	double xdn = dot(x, n);
	double pdn = dot(pixel, n);
	if (!pdn)
	{
		sphere->t1 = -1;
		sphere->t2 = -1;
	}
	if ((t = -xdn / pdn) > 0)
	{
		sphere->t1 = t;
		sphere->t2 = t;
	}
	else
	{
		sphere->t1 = -1;
		sphere->t2 = -1;
	}
}

void	sphere_intersection(t_sphere *sphere, t_vector camera, t_vector pixel)
{
	t_vector	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	r = substract(camera, sphere->center);
	k1 = dot(pixel, pixel);
	k2 = 2 * dot(pixel, r);
	k3 = dot(r, r) - sphere->radius * sphere->radius;
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
	{
		sphere->t1 = -1;
		sphere->t2 = -1;
		return ;
	}
	sphere->t1 = (-k2 + sqrt(d)) / (2 * k1);
	sphere->t2 = (-k2 - sqrt(d)) / (2 * k1);
}

void	cylinder_intersection(t_sphere *sphere, t_vector camera, t_vector pixel)
{
	t_vector	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	sphere->center = normalize(sphere->center);
	r = substract(camera, sphere->center);
	k1 = dot(pixel, pixel) - dot(pixel, sphere->center) * dot(pixel, sphere->center);
	k2 = 2 * dot(pixel, r) - 2 * dot(pixel, sphere->center) * dot(r, sphere->center);
	k3 = dot(r, r) - dot(r, sphere->center) * dot(r, sphere->center) - sphere->radius * sphere->radius;
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
	{
		sphere->t1 = -1;
		sphere->t2 = -1;
		return ;
	}
	sphere->t1 = (-k2 + sqrt(d)) / (2 * k1);
	sphere->t2 = (-k2 - sqrt(d)) / (2 * k1);
}


void	cone_intersection(t_sphere *sphere, t_vector camera, t_vector pixel)
{
	t_vector	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	// sphere->center = normalize(sphere->center);
	r = substract(camera, sphere->center);
	k1 = dot(pixel, pixel) - (1 + sphere->k * sphere->k) * dot(pixel, sphere->center) * dot(pixel, sphere->center);
	k2 = 2 * dot(pixel, r) - (1 + sphere->k * sphere->k) * dot(pixel, sphere->center) * dot(r, sphere->center);
	k3 = dot(r, r) - (1 + sphere->k * sphere->k) * dot(r, sphere->center) * dot(r, sphere->center);
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
	{
		sphere->t1 = -1;
		sphere->t2 = -1;
		return ;
	}
	sphere->t1 = (-k2 + sqrt(d)) / (2 * k1);
	sphere->t2 = (-k2 - sqrt(d)) / (2 * k1);
}
