/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:04:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/03 23:08:33 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	plane_intersection(t_object *object, t_vector camera, t_vector pixel)
{
	double		t;
	t_vector	n;
	t_vector	x;
	
	n = object->center;
	x = substract(camera, n);
	double xdn = dot(x, n);
	double pdn = dot(pixel, n);
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

void	sphere_intersection(t_object *object, t_vector camera, t_vector pixel)
{
	t_vector	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	r = substract(camera, object->center);
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

void	cylinder_intersection(t_object *object, t_vector camera, t_vector pixel)
{
	t_vector	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	object->center = normalize(object->center);
	r = substract(camera, object->center);
	k1 = dot(pixel, pixel) - dot(pixel, object->center) * dot(pixel, object->center);
	k2 = 2 * dot(pixel, r) - 2 * dot(pixel, object->center) * dot(r, object->center);
	k3 = dot(r, r) - dot(r, object->center) * dot(r, object->center) - object->radius * object->radius;
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


void	cone_intersection(t_object *object, t_vector camera, t_vector pixel)
{
	t_vector	r;
	double		k1;
	double		k2;
	double		k3;
	double		d;

	object->center = normalize(object->center);
	r = substract(camera, object->center);
	k1 = dot(pixel, pixel) - (1 + object->k * object->k) * dot(pixel, object->center) * dot(pixel, object->center);
	k2 = 2 * dot(pixel, r) - 2 * (1 + object->k * object->k) * dot(pixel, object->center) * dot(r, object->center);
	k3 = dot(r, r) - (1 + object->k * object->k) * dot(r, object->center) * dot(r, object->center);
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
