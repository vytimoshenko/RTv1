/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_color_effects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:14:17 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/06 07:16:58 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

t_color	effect_cartoon(t_color color)
{
	color.r /= 16;
	color.g /= 16;
	color.b /= 16;
	color.r *= 16;
	color.g *= 16;
	color.b *= 16;
	return (color);
}

t_color	effect_depth(t_scene *scene, int i)
{
	double  tmp;
	t_color color;
	
	tmp = scene->depth_buffer[i];
	tmp = (int)(scene->depth_map_k / log(0.05 * (double)tmp));
	if (tmp > 255)
		tmp = 255;
	color.r = (int)tmp;
	color.g = (int)tmp;
	color.b = (int)tmp;
	color = effect_negative(color);
	return (color);
}
