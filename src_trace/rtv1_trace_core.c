/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:04:49 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:38:59 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

//NEED TO SPLIT
void	trace_pixel(t_scene *scene, t_vec cam, t_pix *pixel, int k)
{
	t_pnt		point;
	t_obj	close_obj;

	close_obj = get_intersection(scene->objs, cam, pixel->pos,
	(t_t_min_max){0, DRAW_DISTANCE_MIN, DRAW_DISTANCE_MAX});
	pixel->depth = pixel->depth == 0 ? close_obj.closest : pixel->depth;
	if (close_obj.closest == DRAW_DISTANCE_MAX && pixel->obj_id == EMPTY)
		pixel->obj_id = NOTHING_SELECTED;
	if (close_obj.closest == DRAW_DISTANCE_MAX)
		return ;
	if (pixel->obj_id == EMPTY)
		pixel->obj_id = close_obj.id;
	point.xyz = add(cam, mult_sv(close_obj.closest, pixel->pos));
	get_prop(scene, pixel->pos, &point, &close_obj);
	point.light = get_lightning(scene, point, mult_sv(-1.0, pixel->pos));
	point.final_clr = multiply_color(point.light, point.color);
	if (k == 0 || (point.refl <= 0 && point.trns <= 0))
	{
		pixel->color = point.final_clr;
		return ;
	}
	if (point.refl > 0)
	{
		pixel->pos = reflect_ray(mult_sv(-1.0, pixel->pos), point.n);
		trace_pixel(scene, point.xyz, pixel, k - 1);
		pixel->color = add_color(multiply_color(1.0 - point.refl,
		point.final_clr), multiply_color(point.refl, pixel->color));
	}
}

void	get_prop(t_scene *scene, t_vec pixel, t_pnt *point, t_obj *obj)
{
	get_normal(point, pixel, obj, scene->cams.arr[scene->act_cam]->pos);
	point->n = normalize(point->n);
	point->color = scene->mats.arr[obj->mat]->color;
	point->spec = scene->mats.arr[obj->mat]->spec;
	point->refl = scene->mats.arr[obj->mat]->refl;
	point->trns = scene->mats.arr[obj->mat]->
	transp;
	point->refr = scene->mats.arr[obj->mat]->refr;
}

void	get_normal(t_pnt *point, t_vec pixel, t_obj *obj, t_vec cam)
{
	double		m;
	double		k;
	t_vec	r;

	if (obj->type == OBJECT_TYPE_PLANE)
		point->n = dot(pixel, obj->pos) < 0 ? obj->pos :
		mult_sv(-1, obj->pos);
	else if (obj->type == OBJECT_TYPE_SPHERE)
		point->n = sub(point->xyz, obj->pos);
	else if (obj->type == OBJECT_TYPE_CYLINDER)
	{
		r = sub(cam, obj->pos);
		m = obj->closest * dot(pixel, obj->dir) + dot(r, obj->dir);
		point->n = sub(sub(point->xyz, obj->pos),
		mult_sv(m, obj->dir));
	}
	else if (obj->type == OBJECT_TYPE_CONE)
	{
		r = sub(cam, obj->pos);
		m = obj->closest * dot(pixel, obj->dir) + dot(r, obj->dir);
		k = obj->radius / m;
		point->n = sub(sub(point->xyz, obj->pos),
		mult_sv(m * (1 + k * k), obj->dir));
	}
}
