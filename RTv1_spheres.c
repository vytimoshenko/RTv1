/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 00:17:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/25 02:15:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_color		get_color(t_spheres	spheres, t_light_sources light_sources,
		t_vector camera, t_vector pixel, int reflection_depth)
{
	t_point		point;
	t_sphere	closest_sphere;
	t_vector	view;
	t_vector	reflect;
	t_color		reflected_color;
	t_color		background_color;

	background_color = (t_color)BACKGROUND_COLOR;
	closest_sphere = find_closest_intersection(spheres, camera,
	pixel, DRAW_DISTANCE_MIN, DRAW_DISTANCE_MAX);
	if (closest_sphere.closest == DRAW_DISTANCE_MAX)
		return (background_color);
	point.xyz = add(camera, multiply(closest_sphere.closest, pixel));
	point.normal = substract(point.xyz, closest_sphere.center);
	point.normal = multiply(1.0 / length(point.normal), point.normal);
	point.color = closest_sphere.color;
	point.specular = closest_sphere.specular;
	point.reflective = closest_sphere.reflective;
	view = multiply(-1.0, pixel);
	point.light = get_lightning(point, light_sources, view, spheres);
	point.final_color = multiply_color(point.light, point.color);
	if (reflection_depth == 0 || point.reflective <= 0)
		return (point.final_color);
	reflect = reflect_ray(view, point.normal);
	reflected_color = get_color(spheres, light_sources, point.xyz, reflect,
	reflection_depth - 1);
	point.final_color = add_color(multiply_color(1.0 - point.reflective, point.final_color),
	multiply_color(point.reflective, reflected_color));
	return (point.final_color);
}

t_sphere	find_closest_intersection(t_spheres	spheres,
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

void	sphere_intersection(t_sphere *sphere, t_vector camera, t_vector pixel)
{	
	t_vector    ray;
	double      k1;
	double      k2;
	double      k3;
	double      discriminant;
	
	ray = substract(camera, sphere->center);
	k1 = dot(pixel, pixel);
	k2 = 2 * dot(ray, pixel);
	k3 = dot(ray, ray) - sphere->radius * sphere->radius;
	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
	{
		sphere->t1 = -1;
		sphere->t2 = -1;
		return;
	}
	sphere->t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
	sphere->t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
}

double	get_lightning(t_point point, t_light_sources light_sources,
t_vector pixel, t_spheres spheres)
{
	int         i;
	double      intensity;
	t_vector    light;
	t_sphere 	shadow_sphere;
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
				light = substract(light_sources.array[i]->position, point.xyz);
				t_max = 1;
			}
			else if (light_sources.array[i]->type == LIGHT_TYPE_DIRECTIONAL)
			{
				light = light_sources.array[i]->direction;
				t_max = DRAW_DISTANCE_MAX;
			}
			shadow_sphere = find_closest_intersection(spheres, point.xyz, light, 0.000001, t_max);
			if (shadow_sphere.null)
				continue;
			intensity += light_sources.array[i]->intensity *
			diffuse_light(point.normal, light);
			if (point.specular)
				intensity += light_sources.array[i]->intensity *
				reflection_light(point.normal, light, pixel, point.specular);
		}
	}
	return (intensity);
}

double	diffuse_light(t_vector normal, t_vector light)
{
	double	normal_dot_light;

	normal_dot_light = dot(normal, light);
	if (normal_dot_light > 0)
		return (normal_dot_light / (length(normal) * length(light)));
	else
		return (0);
}

double	reflection_light(t_vector normal, t_vector light, t_vector pixel,
		double specular)
{
	double		reflect_dot_pixel;
	t_vector	reflect;

	reflect = reflect_ray(light, normal);
	reflect_dot_pixel = dot(reflect, pixel);
	if (reflect_dot_pixel > 0)
		return (pow(reflect_dot_pixel / (length(reflect) * length(pixel)),
		specular));
	else
		return (0);
}

t_vector	reflect_ray(t_vector ray, t_vector normal)
{
	return(substract(multiply(2 * dot(ray, normal), normal), ray));
}