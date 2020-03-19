/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:04:49 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 13:07:16 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	get_pixel_color(t_scene *scene, t_vector camera, t_pixel *pixel, int k)
{
	t_point		point;
	t_object	close_object;

	close_object = get_intersection(scene->objects, camera, pixel->pos,
	(t_t_min_max){0, DRAW_DISTANCE_MIN, DRAW_DISTANCE_MAX});
	fill_depth_buffer(scene, *pixel, close_object.closest);
	if (close_object.closest == DRAW_DISTANCE_MAX)
		return ;
	fill_object_buffer(scene, *pixel, close_object.id);
	point.xyz = add(camera, multiply_sv(close_object.closest, pixel->pos));
	get_point_properties(scene, &point, &close_object);
	point.light = get_lightning(scene, point, multiply_sv(-1.0, pixel->pos));
	point.final_color = multiply_color(point.light, point.color);
	if (k == 0 || (point.reflective <= 0 && point.transparency <= 0))
	{
		pixel->color = point.final_color;
		return ;
	}
	if (point.reflective > 0)
	{
		pixel->pos = reflect_ray(multiply_sv(-1.0, pixel->pos), point.n);
		get_pixel_color(scene, point.xyz, pixel, k - 1);
		pixel->color = add_color(multiply_color(1.0 - point.reflective,
		point.final_color), multiply_color(point.reflective, pixel->color));
	}
}

void	get_point_properties(t_scene *scene, t_point *point, t_object *object)
{
	get_normal(point, object);
	point->n = normalize(point->n);
	point->color = scene->materials.array[object->material]->color;
	point->specular = scene->materials.array[object->material]->specular;
	point->reflective = scene->materials.array[object->material]->reflective;
	point->transparency = scene->materials.array[object->material]->
	transparency;
	point->refractive = scene->materials.array[object->material]->refractive;
}

void	get_normal(t_point *point, t_object *object)
{
	if (object->type == OBJECT_TYPE_PLANE)
		point->n = multiply_sv(-1, object->position);
	else if (object->type == OBJECT_TYPE_SPHERE)
		point->n = substract(point->xyz, object->position);
	else if (object->type == OBJECT_TYPE_CYLINDER)
		point->n = substract(point->xyz, object->position);
	else if (object->type == OBJECT_TYPE_CONE)
		point->n = substract(point->xyz, object->position);
}

void	fill_depth_buffer(t_scene *scene, t_pixel pixel, double close)
{
	int	i;

	pixel.x = IMG_SIZE_W / 2 + pixel.x;
	pixel.y = IMG_SIZE_H / 2 - pixel.y;
	i = (int)(IMG_SIZE_W * (pixel.y - 1) + pixel.x);
	if (i > 0 && scene->got_depth[i] == FALSE)
	{
		scene->depth_buffer[i] = close;
		scene->got_depth[i] = TRUE;
	}
}

void	fill_object_buffer(t_scene *scene, t_pixel pixel, int id)
{
	int	i;

	pixel.x = IMG_SIZE_W / 2 + pixel.x - 1;
	pixel.y = IMG_SIZE_H / 2 - pixel.y + 1;
	i = (int)(IMG_SIZE_W * (pixel.y - 1) + pixel.x);
	if (i > 0 && scene->got_object[i] == FALSE)
	{
		scene->object_buffer[i] = id;
		scene->got_object[i] = TRUE;
	}
}
