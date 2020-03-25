/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_selection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 10:58:58 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/25 14:20:17 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void    init_pixel_buffer(t_scene *scene)
{
	if (!(scene->pixel_buffer = (t_pixel *)ft_memalloc(sizeof(t_pixel)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
}

void    clean_pixel_buffer(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		ft_memset(&scene->pixel_buffer[i], 0, sizeof(t_pixel));
}

void    init_object_buffers(t_scene *scene)
{
	if (!(scene->object_buffer = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	if (!(scene->got_object = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_object_buffers(scene);
}

void	clean_object_buffers(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->object_buffer[i] = NOTHING_SELECTED;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->got_object[i] = FALSE;
}

void	fill_object_buffers(t_scene *scene, t_pixel pixel, int id)
{
	int	i;

	pixel.x = IMG_SIZE_W / 2 + pixel.x;
	pixel.y = IMG_SIZE_H / 2 - pixel.y;
	i = (int)(IMG_SIZE_W * (pixel.y) + pixel.x);
	if (i > 0 && scene->got_object[i] == FALSE)
	{
		scene->object_buffer[i] = id;
		scene->got_object[i] = TRUE;
	}
}

t_color	shade_unselesected(t_scene *scene, int i, t_color color)
{
	if (scene->object_buffer[i] != scene->active_object)
		return (multiply_color(SHADE_UNSELECTED, color));
	else
		return (color);
}
