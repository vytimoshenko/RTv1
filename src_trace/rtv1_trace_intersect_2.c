/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_intersect_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:04:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/14 19:01:53 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	plane(t_object *object, t_vector camera, t_vector pixel)
{
	double		t;
	t_vector	x;
	double		xdn;
	double		pdn;

	x = substract(camera, object->position);
	xdn = dot(x, object->position);
	pdn = dot(pixel, object->position);
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

void	sphere(t_object *object, t_vector camera, t_vector pixel)
{
	t_vector	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	r = substract(camera, object->position);
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

void	cylinder(t_object *object, t_vector camera, t_vector pixel)
{
	t_vector	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	r = substract(camera, object->position);
	k1 = dot(pixel, pixel) - dot(pixel, object->direction) *
	dot(pixel, object->direction);
	k2 = 2 * (dot(pixel, r) - dot(pixel, object->direction) *
	dot(r, object->direction));
	k3 = dot(r, r) - dot(r, object->direction) * dot(r, object->direction) -
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

void	cone(t_object *object, t_vector camera, t_vector pixel)
{
	t_vector	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	r = substract(camera, object->position);
	double k = tan(deg_to_rad(object->radius / 2));
	k1 = dot(pixel, pixel) - (1 + k * k) * dot(pixel, object->direction) *
	dot(pixel, object->direction);
	k2 = 2 * (dot(pixel, r) - (1 + k * k) * dot(pixel, object->direction) *
	dot(r, object->direction));
	k3 = dot(r, r) - (1 + k * k) * dot(r, object->direction) * dot(r, object->direction);
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
