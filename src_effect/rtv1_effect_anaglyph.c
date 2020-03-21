/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_anaglyph.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:14:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 10:32:44 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void    init_anaglyph_buffers(t_scene *scene)
{
	if (!(scene->anaglyph_left_buffer = (t_color *)ft_memalloc(sizeof(t_color)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	if (!(scene->anaglyph_right_buffer = (t_color *)ft_memalloc(sizeof(t_color)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_anaglyph_buffers(scene);
}

void	clean_anaglyph_buffers(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->anaglyph_left_buffer[i] = (t_color){0, 0, 0};
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->anaglyph_right_buffer[i] = (t_color){0, 0, 0};
}

void effect_anaglyph(t_scene *scene, t_mlx *mlx)
{
	int i;
	
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->anaglyph_left_buffer[i] = scene->frame_buffer[i];
	scene->cameras.array[scene->active_camera]->position.x += 1;
	trace_rays(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->anaglyph_right_buffer[i] = scene->frame_buffer[i];
	clean_frame_buffer(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i].r = (average_color_channels(scene->
		anaglyph_left_buffer[i])).r;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i].b = (average_color_channels(scene->
		anaglyph_right_buffer[i])).b;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->data[i] = unite_color_channels(scene->frame_buffer[i]);
}
