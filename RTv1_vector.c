/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:12:27 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/25 04:26:14 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

double		deg_to_rad(int degrees)
{
	return ((double)degrees * PI / 180.0);
}

double      dot(t_vector v1, t_vector v2)
{
	return ((double)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

double      length(t_vector v1)
{
	return ((double)sqrt(dot(v1, v1)));
}

t_vector    add(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vector    substract(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vector    multiply_sv(double k, t_vector v)
{
	t_vector result;
	
	result.x = k * v.x;
	result.y = k * v.y;
	result.z = k * v.z;
	return (result);
}

t_vector    multiply_mv(t_matrix m, t_vector v)
{
	t_vector result;
	
	result.x = m.a[0] * v.x + m.a[1] * v.y + m.a[2] * v.z;
	result.y = m.b[0] * v.x + m.b[1] * v.y + m.b[2] * v.z;
	result.z = m.c[0] * v.x + m.c[1] * v.y + m.c[2] * v.z;
	return (result);
}
