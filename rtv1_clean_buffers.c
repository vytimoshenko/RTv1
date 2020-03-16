/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_clean_buffers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 06:42:59 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/16 09:07:14 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    clean_frame_buffer(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i] = (t_color){0, 0, 0};
}

void	clean_object_buffer(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->object_buffer[i] = NOTHING_SELECTED;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->got_object[i] = FALSE;
}

void    clean_depth_buffer(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->depth_buffer[i] = NOTHING_SELECTED;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->got_depth[i] = FALSE;
}

void    clean_aliasing_buffer(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->aliasing_buffer[i] = FALSE;
}

void    clean_anaglyph_buffers(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->anaglyph_left_buffer[i] = (t_color){0, 0, 0};
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->anaglyph_right_buffer[i] = (t_color){0, 0, 0};
}
