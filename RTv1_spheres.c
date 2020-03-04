/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:04:49 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/04 03:02:07 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		get_pixel_color(t_scene *scene, t_vector camera, t_pixel *pixel, int k)
{
	t_point		point;
	t_object	closest_object;

	closest_object = get_intersection(scene->objects, camera, pixel->position,
	DRAW_DISTANCE_MIN, DRAW_DISTANCE_MAX);
	if (closest_object.closest == DRAW_DISTANCE_MAX)
		return ((t_color)BACKGROUND_COLOR);
	fill_object_buffer(scene, *pixel, closest_object.id);
	point.xyz = add(camera, multiply_sv(closest_object.closest, pixel->position));
	get_point_properties(&point, &closest_object);
	point.light = get_lightning(scene, point, multiply_sv(-1.0, pixel->position));
	point.final_color = multiply_color(point.light, point.color);
	if (k == 0 || point.reflective <= 0)
		return (point.final_color);
	pixel->position = reflect_ray(multiply_sv(-1.0, pixel->position), point.n);
	pixel->color = get_pixel_color(scene, point.xyz, pixel, k - 1);
	point.final_color = add_color(multiply_color(1.0 - point.reflective,
	point.final_color), multiply_color(point.reflective, pixel->color));
	return (point.final_color);
}

void		get_point_properties(t_point *point, t_object *object)
{
	get_normal(point, object);
	point->n = normalize(point->n);
	point->color = object->color;
	point->specular = object->specular;
	point->reflective = object->reflective;
}

void		get_normal(t_point *point, t_object *object)
{
	if (object->type == OBJECT_TYPE_PLANE)
		point->n = multiply_sv(-1, object->center);
	else if (object->type == OBJECT_TYPE_SPHERE)
		point->n = substract(point->xyz, object->center);
	else if (object->type == OBJECT_TYPE_CYLINDER)
		point->n = substract(point->xyz, object->center);
	else if (object->type == OBJECT_TYPE_CONE)
		point->n = substract(point->xyz, object->center);
}

void		fill_object_buffer(t_scene *scene, t_pixel pixel, int id)
{
	int	i;

	pixel.x = IMG_SIZE_W / 2 + pixel.x;
	pixel.y = IMG_SIZE_H / 2 - pixel.y;
	i = (int)(IMG_SIZE_W * (pixel.y - 1) + pixel.x);
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
		select_object_function(objects.array[i], camera, pixel);
		// get_closest_object(objects.array[i]);
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

void	select_object_function(t_object *object, t_vector camera, t_vector pixel)
{
	if (object->type == OBJECT_TYPE_PLANE)
		plane(object, camera, pixel);
	else if (object->type == OBJECT_TYPE_SPHERE)
		sphere(object, camera, pixel);
	else if (object->type == OBJECT_TYPE_CYLINDER)
		cylinder(object, camera, pixel);
	else if (object->type == OBJECT_TYPE_CONE)
		cone(object, camera, pixel);
}

// void	get_closest_object(t_object *object, t_object *closest_object)
// {
// 	if (object->t1 >= t_min && objects->t1 <=
// 		t_max && objects.array[i]->t1 < closest)
// 		{
// 			closest = objects.array[i]->t1;
// 			closest_object = *objects.array[i];
// 			closest_object.null = 1;
// 		}
// 	if (object->t2 >= t_min && object->t2 <=
// 	t_max && objects.array[i]->t2 < closest)
// 	{
// 		closest = objects.array[i]->t2;
// 		closest_object = *objects.array[i];
// 		closest_object.null = 1;
// 	}
// }
