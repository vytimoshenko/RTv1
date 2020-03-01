/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:12:27 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/01 17:56:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		dot(t_vector v1, t_vector v2)
{
	return ((double)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

double		length(t_vector v)
{
	return ((double)sqrt(dot(v, v)));
}

t_vector	normalize(t_vector v)
{
	return ((multiply_sv(1.0 / length(v), v)));
}

t_vector	add(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vector	substract(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vector	multiply_sv(double k, t_vector v)
{
	t_vector result;

	result.x = k * v.x;
	result.y = k * v.y;
	result.z = k * v.z;
	return (result);
}
