/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:04:49 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/03 23:16:42 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		get_color(t_objects objects, t_light_sources light_sources,
		t_vector camera, t_vector pixel, int reflection_depth, t_scene *scene,
		int x, int y)
{
	t_point		point;
	t_object	closest_object;
	t_vector	view;
	t_vector	reflect;
	t_color		reflected_color;

	closest_object = get_intersection(objects, camera,
	pixel, DRAW_DISTANCE_MIN, DRAW_DISTANCE_MAX);
	if (closest_object.closest == DRAW_DISTANCE_MAX)
		return ((t_color)BACKGROUND_COLOR);
	fill_object_buffer(scene, x, y, closest_object.id);
	point.xyz = add(camera, multiply_sv(closest_object.closest, pixel));
	if (closest_object.type == OBJECT_TYPE_PLANE)
		point.n = multiply_sv(-1, closest_object.center);
	else if (closest_object.type == OBJECT_TYPE_SPHERE)
		point.n = substract(point.xyz, closest_object.center);
	else if (closest_object.type == OBJECT_TYPE_CYLINDER)
		point.n = substract(point.xyz, closest_object.center);
	else if (closest_object.type == OBJECT_TYPE_CONE)
		point.n = substract(point.xyz, closest_object.center);
	point.n = normalize(point.n);
	point.color = closest_object.color;
	point.specular = closest_object.specular;
	point.reflective = closest_object.reflective;
	view = multiply_sv(-1.0, pixel);
	point.light = get_lightning(scene, point, view);
	point.final_color = multiply_color(point.light, point.color);
	if (reflection_depth == 0 || point.reflective <= 0)
		return (point.final_color);
	reflect = reflect_ray(view, point.n);
	reflected_color = get_color(objects, light_sources, point.xyz, reflect,
	reflection_depth - 1, scene, x, y);
	point.final_color = add_color(multiply_color(1.0 - point.reflective,
	point.final_color),
	multiply_color(point.reflective, reflected_color));
	return (point.final_color);
}

// t_point		get_point_properties(t_object *object)
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

t_object	get_intersection(t_objects objects, t_vector camera,
			t_vector pixel, double t_min, double t_max)
{
	int			i;
	t_object	closest_object;
	double		closest;

	i = -1;
	closest = t_max;
	closest_object.null = 0;
	while (++i < objects.quantity)
	{
		if (objects.array[i]->type == OBJECT_TYPE_PLANE)
			plane_intersection(objects.array[i], camera, pixel);
		else if (objects.array[i]->type == OBJECT_TYPE_SPHERE)
			sphere_intersection(objects.array[i], camera, pixel);
		else if (objects.array[i]->type == OBJECT_TYPE_CYLINDER)
			cylinder_intersection(objects.array[i], camera, pixel);
		else if (objects.array[i]->type == OBJECT_TYPE_CONE)
			cone_intersection(objects.array[i], camera, pixel);
		if (objects.array[i]->t1 >= t_min && objects.array[i]->t1 <=
		t_max && objects.array[i]->t1 < closest)
		{
			closest = objects.array[i]->t1;
			closest_object = *objects.array[i];
			closest_object.null = 1;
		}
		if (objects.array[i]->t2 >= t_min && objects.array[i]->t2 <=
		t_max && objects.array[i]->t2 < closest)
		{
			closest = objects.array[i]->t2;
			closest_object = *objects.array[i];
			closest_object.null = 1;
		}
	}
	closest_object.closest = closest;
	if (closest_object.null == 1)
		closest_object.null = 1;
	else
		closest_object.null = 0;
	return (closest_object);
}


