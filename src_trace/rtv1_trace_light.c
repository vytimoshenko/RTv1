/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:13:20 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/28 21:31:31 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

double		get_lightning(t_scene *scene, t_point point, t_vector pixel)
{
	int		i;
	double	tmp;
	double	intensity;

	intensity = 0;
	i = -1;
	while (++i < scene->lights.quantity)
	{
		if (scene->lights.array[i]->off == FALSE)
		{
			if (scene->lights.array[i]->type == LIGHT_TYPE_AMBIENT)
				intensity += scene->lights.array[i]->intensity;
			else if ((tmp = diffuse_and_specular_light(scene, point, pixel, i))
			!= -1)
				intensity += tmp;
		}
	}
	return (intensity);
}

double		diffuse_and_specular_light(t_scene *scene, t_point point,
			t_vector pixel, int i)
{
	t_vector	l;
	t_object	shadow;
	double		t_max;
	double		intensity;

	if (scene->lights.array[i]->type == LIGHT_TYPE_POINT)
	{
		l = substract(scene->lights.array[i]->position, point.xyz);
		t_max = 1;
	}
	else
	{
		l = scene->lights.array[i]->position;
		t_max = DRAW_DISTANCE_MAX;
	}
	shadow = get_intersection(scene->objects, point.xyz, l,
	(t_t_min_max){0, 0.000001, t_max});
//  Be sure to ensure that the ray intersects at a distance less than the light source distance
	// if (dot(normalize(l), normalize(point.n)) < 0.0)
	// 	shadow.null = 1;
	// if (shadow.t1 > length(l) || shadow.t2 > length(l))
	// 	shadow.null = 1;
	if (shadow.null /*&& shadow.t1 < length(l) && shadow.t2 < length(l)*/)
		return (-1);
	intensity = scene->lights.array[i]->intensity * diffuse(point.n, l);
	if (point.specular)
		intensity += scene->lights.array[i]->intensity *
		specular(point.n, l, pixel, point.specular);
	return (intensity);
}

double		diffuse(t_vector n, t_vector l)
{
	double	ndl;

	ndl = dot(n, l);
	if (ndl > 0)
		return (ndl / (length(n) * length(l)));
	else
		return (0);
}

double		specular(t_vector n, t_vector l, t_vector p, double s)
{
	t_vector	r;
	double		rdp;

	r = reflect_ray(l, n);
	rdp = dot(r, p);
	if (rdp > 0)
		return (pow(rdp / (length(r) * length(p)), s));
	else
		return (0);
}

t_vector	reflect_ray(t_vector r, t_vector n)
{
	return (substract(multiply_sv(2.0 * dot(r, n), n), r));
}
