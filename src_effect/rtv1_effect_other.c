/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_anaglyph.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:14:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/25 20:41:38 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

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
	color.r = (int)tmp;
	color.g = (int)tmp;
	color.b = (int)tmp;
	color = to_negative(color);
	return (color);
}

void effect_anaglyph(t_scene *scene)
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
