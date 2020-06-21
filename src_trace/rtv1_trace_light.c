/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:13:20 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:48:56 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

double		get_lightning(t_scene *scene, t_pnt point, t_vec pixel)
{
	int		i;
	double	tmp;
	double	intensity;

	intensity = 0;
	i = -1;
	while (++i < scene->lights.quant)
	{
		if (scene->lights.arr[i]->off == FALSE)
		{
			if (scene->lights.arr[i]->type == LIGHT_TYPE_AMBIENT)
				intensity += scene->lights.arr[i]->intens;
			else if ((tmp = diffuse_and_specular_light(scene, point, pixel, i))
			!= -1)
				intensity += tmp;
		}
	}
	return (intensity);
}

double		diffuse_and_specular_light(t_scene *scene, t_pnt point,
			t_vec pixel, int i)
{
	t_vec	l;
	t_obj	shadow;
	double		t_max;
	double		intensity;

	if (scene->lights.arr[i]->type == LIGHT_TYPE_POINT)
	{
		l = sub(scene->lights.arr[i]->pos, point.xyz);
		t_max = 1;
	}
	else
	{
		l = scene->lights.arr[i]->pos;
		t_max = DRAW_DISTANCE_MAX;
	}
	shadow = get_intersection(scene->objs, point.xyz, l,
	(t_t_min_max){0, 0.000001, t_max});
//  Be sure to ensure that the ray intersects at a distance less than the light source distance
	// if (dot(normalize(l), normalize(point.n)) < 0.0)
	// 	shadow.null = 1;
	// if (shadow.t1 > length(l) || shadow.t2 > length(l))
	// 	shadow.null = 1;
	if (shadow.null /*&& shadow.t1 < length(l) && shadow.t2 < length(l)*/)
		return (-1);
	intensity = scene->lights.arr[i]->intens * diffuse(point.n, l);
	if (point.spec)
		intensity += scene->lights.arr[i]->intens *
		specular(point.n, l, pixel, point.spec);
	return (intensity);
}

double		diffuse(t_vec n, t_vec l)
{
	double	ndl;

	ndl = dot(n, l);
	if (ndl > 0)
		return (ndl / (length(n) * length(l)));
	else
		return (0);
}

double		specular(t_vec n, t_vec l, t_vec p, double s)
{
	t_vec	r;
	double		rdp;

	r = reflect_ray(l, n);
	rdp = dot(r, p);
	if (rdp > 0)
		return (pow(rdp / (length(r) * length(p)), s));
	else
		return (0);
}

t_vec	reflect_ray(t_vec r, t_vec n)
{
	return (sub(mult_sv(2.0 * dot(r, n), n), r));
}
