/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_color_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:14:17 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/28 21:27:40 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

t_color	add_color(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r + c2.r > 255 ? 255 : c1.r + c2.r;
	result.g = c1.g + c2.g > 255 ? 255 : c1.g + c2.g;
	result.b = c1.b + c2.b > 255 ? 255 : c1.b + c2.b;
	return (result);
}

t_color	multiply_color(double k, t_color color)
{
	t_color result;

	if (k < 0)
		return (color);
	result.r = k * color.r > 255 ? 255 : k * color.r;
	result.g = k * color.g > 255 ? 255 : k * color.g;
	result.b = k * color.b > 255 ? 255 : k * color.b;
	return (result);
}

t_color	mix_color(t_color c1, t_color c2)
{
	t_color result;

	result.r = (c1.r + c2.r) / 2;
	result.g = (c1.g + c2.g) / 2;
	result.b = (c1.b + c2.b) / 2;
	return (result);
}
