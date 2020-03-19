/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_color_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:14:17 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 19:28:08 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

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

t_color	effect_average(t_color color)
{
	int tmp;

	tmp = (color.r + color.g + color.b) / 3;
	color.r = tmp;
	color.g = tmp;
	color.b = tmp;
	return (color);
}

t_color	effect_grayscale(t_color color)
{
	int tmp;

	tmp = 0.2126 * color.r + 0.7152 * color.g + 0.0722 * color.b;
	color.r = tmp;
	color.g = tmp;
	color.b = tmp;
	return (color);
}

t_color	effect_negative(t_color color)
{
	color.r = 255 - color.r;
	color.g = 255 - color.g;
	color.b = 255 - color.b;
	return (color);
}

t_color	effect_cartoon(t_scene *scene, t_color color)
{
	color.r /= scene->k_cartoon;
	color.g /= scene->k_cartoon;
	color.b /= scene->k_cartoon;
	color.r *= scene->k_cartoon;
	color.g *= scene->k_cartoon;
	color.b *= scene->k_cartoon;
	return (color);
}

t_color	effect_depth(t_scene *scene, int i)
{
	double	tmp;
	t_color color;

	tmp = scene->depth_buffer[i] + 10;
	tmp = (int)(scene->k_depth_map / log(0.05 * (double)tmp));
	if (tmp > 255)
		tmp = 255;
	color.r = (int)tmp;
	color.g = (int)tmp;
	color.b = (int)tmp;
	color = effect_negative(color);
	return (color);
}
