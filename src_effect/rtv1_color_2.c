/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_color_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:14:17 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 18:23:48 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_color	add_color(t_color c1, t_color c2)
{
	t_color result;

	if ((result.r = c1.r + c2.r) > 255)
		result.r = 255;
	if ((result.g = c1.g + c2.g) > 255)
		result.g = 255;
	if ((result.b = c1.b + c2.b) > 255)
		result.b = 255;
	return (result);
}

t_color	multiply_color(double k, t_color color)
{
	t_color result;

	if (k < 0)
		return (color);
	if ((result.r = k * color.r) > 255)
		result.r = 255;
	if ((result.g = k * color.g) > 255)
		result.g = 255;
	if ((result.b = k * color.b) > 255)
		result.b = 255;
	return (result);
}

t_color	mix_color(t_color c1, t_color c2)
{
	t_color result;

	if ((result.r = (c1.r + c2.r) / 2) > 255)
		result.r = 255;
	if ((result.g = (c1.g + c2.g) / 2) > 255)
		result.g = 255;
	if ((result.b = (c1.b + c2.b) / 2) > 255)
		result.b = 255;
	return (result);
}
