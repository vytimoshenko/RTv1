/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_final_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:22:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/05 20:45:49 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		pixel_post_processing(t_scene *scene, int i, t_color color)
{
	if (scene->active_object != NO_OBJECT_SELECTED && scene->in_motion_blur == FALSE)
		color = shade_unselesected(scene, i, color);
	if (scene->effect == EFFECT_DEPTH_MAP)
		color = effect_depth(scene, i);
	// else if (scene->effect == EFFECT_FOG)
	// 	color = effect_fog(scene, i, color);
	else if (scene->effect == EFFECT_CARTOON)
		color = effect_cartoon(color);
	else if (scene->effect == EFFECT_OUTLINE_MAP)
		color = effect_outline(scene, i);
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

t_color	effect_depth(t_scene *scene, int i)
{
	double		tmp;
	t_color	color;
	
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

// t_color	effect_fog(t_scene *scene, int i, t_color color)
// {
// 	// int		tmp;
// 	t_color	fog;
// 	// double		fog_rate;
	
// 	// fog_rate = fog.r / 10.0;
// 	color = multiply_color(0.4, color);
// 	fog = effect_depth(scene, i);
// 	color = mix_color(color, fog);

// 	// tmp = scene->depth_buffer[i];
// 	// tmp = (int)(scene->depth_map_k / log(0.05 * (double)tmp));


// 	return (color);
// }

t_color	effect_outline(t_scene *scene, int i)
{
	if (scene->aliasing_buffer[i])
		return ((t_color){255, 255, 255});
	else
		return ((t_color){0, 0, 0});
}