/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_anaglyph.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:14:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/16 08:17:06 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void get_final_anaglyph(t_scene *scene, t_mlx *mlx)
{
	int i;
	
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->anaglyph_left_buffer[i] = scene->frame_buffer[i];
	scene->cameras.array[scene->active_camera]->position.x += 1;
	// scene->cameras.array[scene->active_camera]->direction.y += 1;
	// get_sin_cos(scene->cameras.array[scene->active_camera]);
	trace_rays(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->anaglyph_right_buffer[i] = scene->frame_buffer[i];
	clean_frame_buffer(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i].r = (effect_average(scene->anaglyph_left_buffer[i])).r;
	// i = -1;
	// while (++i < IMG_SIZE_W * IMG_SIZE_H)
	// 	scene->frame_buffer[i].g = scene->anaglyph_right_buffer[i].g;
	// i = -1;
	// while (++i < IMG_SIZE_W * IMG_SIZE_H)
	// 	scene->frame_buffer[i].g = (effect_average(scene->anaglyph_right_buffer[i])).g;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i].b = (effect_average(scene->anaglyph_right_buffer[i])).b;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->data[i] = unite_color_channels(scene->frame_buffer[i]);
}
