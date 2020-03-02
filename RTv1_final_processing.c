/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_final_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:22:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/01 22:48:02 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		pixel_post_processing(t_scene *scene, int i, t_color color)
{
	if (scene->active_object != NO_OBJECT_SELECTED && scene->in_motion_blur == FALSE)
		color = shade_unselesected(scene, i, color);
	if (scene->effect == EFFECT_CARTOON)
		color = effect_cartoon(color);
	else if (scene->effect == EFFECT_GRAYSCALE)
		color = effect_grayscale(color);
	else if (scene->effect == EFFECT_NEGATIVE)
		color = effect_negative(color);
	else if (scene->effect == EFFECT_RED_CHANNEL)
	{
		color.g = 0;
		color.b = 0;
	}
	else if (scene->effect == EFFECT_GREEN_CHANNEL)
	{
		color.r = 0;
		color.b = 0;
	}
	else if (scene->effect == EFFECT_BLUE_CHANNEL)
	{
		color.r = 0;
		color.g = 0;
	}
	return (color);
}

t_color	shade_unselesected(t_scene *scene, int i, t_color color)
{
	if (scene->object_buffer[i] != scene->active_object)
		return (multiply_color(SHADE_UNSELECTED, color));
	else
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
