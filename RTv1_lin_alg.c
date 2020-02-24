/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_lin_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:12:27 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/24 21:51:59 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

double      dot(t_vector v1, t_vector v2)
{
	return ((double)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

double      length(t_vector v1)
{
	return ((double)sqrt(dot(v1, v1)));
}

t_vector    multiply(double k, t_vector v)
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

t_vector    add(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_color    add_color(t_color c1, t_color c2)
{
	t_color result;

	// if ((result.r = c1.r + c2.r) > 255)
	// 	result.r = 255;
	// if ((result.g = c1.g + c2.g) > 255)
	// 	result.g = 255;
	// if ((result.b = c1.b + c2.b) > 255)
	// 	result.b = 255;
	result.r = c1.r + c2.r;
	result.g = c1.g + c2.g;
	result.b = c1.b + c2.b;

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

t_color    multiply_color(double k, t_color color)
{
	t_color result;

	if ((result.r = k * color.r) > 255)
		result.r = 255;
	if ((result.g = k * color.g) > 255)
		result.g = 255;
	if ((result.b = k * color.b) > 255)
		result.b = 255;
	return (result);
}

int		unite_color_channels(t_color color)
{
	return (256 * 256 * color.r + 256 * color.g + color.b);
}
