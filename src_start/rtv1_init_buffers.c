/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_init_buffers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 06:40:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 22:26:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void    init_frame_buffer(t_scene *scene)
{
	if (!(scene->frame_buffer = (t_color *)ft_memalloc(sizeof(t_color)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
}

void    init_object_buffer(t_scene *scene)
{
	if (!(scene->object_buffer = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	if (!(scene->got_object = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_object_buffer(scene);
}

void    init_depth_buffer(t_scene *scene)
{
	if (!(scene->depth_buffer = (double *)malloc(sizeof(double)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	if (!(scene->got_depth = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_depth_buffer(scene);
}

void    init_aliasing_buffer(t_scene *scene)
{
	if (!(scene->aliasing_buffer = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_aliasing_buffer(scene);
}

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
