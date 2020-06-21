/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:14:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 10:56:22 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

t_color	shade_unselesected(t_scene *scene, int i, t_color color)
{
	if (scene->pixel_buffer[i].object_id != scene->active_object)
		return (multiply_color(SHADE_UNSELECTED, color));
	else
		return (color);
}

t_color	effect_depth(t_scene *scene, int i)
{
	double	tmp;
	t_color color;

	tmp = scene->pixel_buffer[i].depth + 10;
	tmp = (int)(scene->k_depth_map / log(0.05 * (double)tmp));
	if (tmp > 255)
		tmp = 255;
	color.r = (unsigned char)tmp;
	color.g = (unsigned char)tmp;
	color.b = (unsigned char)tmp;
	color = to_negative(color);
	return (color);
}

void	effect_anaglyph(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->pixel_buffer[i].anaglyph = scene->pixel_buffer[i].color;
	scene->cameras.array[scene->active_camera]->position.x += 1;
	trace_rays(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pixel_buffer[i].frame.r = (average_color_channels(scene->
		pixel_buffer[i].anaglyph)).r;
		scene->pixel_buffer[i].frame.g = 0;
		scene->pixel_buffer[i].frame.b = (average_color_channels(scene->
		pixel_buffer[i].color)).b;
	}
}
