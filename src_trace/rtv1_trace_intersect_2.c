/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_intersect_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:04:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:27:11 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	plane(t_obj *object, t_vec camera, t_vec pixel)
{
	double		t;
	t_vec	x;
	double		xdn;
	double		pdn;

	x = sub(camera, object->pos);
	xdn = dot(x, object->pos);
	pdn = dot(pixel, object->pos);
	if (!pdn)
	{
		object->t1 = -1;
		object->t2 = -1;
	}
	if ((t = -xdn / pdn) > 0)
	{
		object->t1 = t;
		object->t2 = t;
	}
	else
	{
		object->t1 = -1;
		object->t2 = -1;
	}
}

void	sphere(t_obj *object, t_vec camera, t_vec pixel)
{
	t_vec	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	r = sub(camera, object->pos);
	k1 = dot(pixel, pixel);
	k2 = 2 * dot(pixel, r);
	k3 = dot(r, r) - object->radius * object->radius;
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
	{
		object->t1 = -1;
		object->t2 = -1;
		return ;
	}
	object->t1 = (-k2 + sqrt(d)) / (2 * k1);
	object->t2 = (-k2 - sqrt(d)) / (2 * k1);
}

void	cylinder(t_obj *object, t_vec camera, t_vec pixel)
{
	t_vec	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	r = sub(camera, object->pos);
	k1 = dot(pixel, pixel) - dot(pixel, object->dir) *
	dot(pixel, object->dir);
	k2 = 2 * (dot(pixel, r) - dot(pixel, object->dir) *
	dot(r, object->dir));
	k3 = dot(r, r) - dot(r, object->dir) * dot(r, object->dir) -
	object->radius * object->radius;
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
	{
		object->t1 = -1;
		object->t2 = -1;
		return ;
	}
	object->t1 = (-k2 + sqrt(d)) / (2 * k1);
	object->t2 = (-k2 - sqrt(d)) / (2 * k1);
}

void	cone(t_obj *object, t_vec camera, t_vec pixel)
{
	t_vec	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;
	double		k;

	r = sub(camera, object->pos);
	k = tan(deg_to_rad(object->radius / 2));
	k1 = dot(pixel, pixel) - (1 + k * k) * dot(pixel, object->dir) *
	dot(pixel, object->dir);
	k2 = 2 * (dot(pixel, r) - (1 + k * k) * dot(pixel, object->dir) *
	dot(r, object->dir));
	k3 = dot(r, r) - (1 + k * k) * dot(r, object->dir) * dot(r, object->dir);
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
	{
		object->t1 = -1;
		object->t2 = -1;
		return ;
	}
	object->t1 = (-k2 + sqrt(d)) / (2 * k1);
	object->t2 = (-k2 - sqrt(d)) / (2 * k1);
}
