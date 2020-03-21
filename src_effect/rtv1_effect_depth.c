/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_depth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 10:45:25 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 11:26:40 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void    init_depth_buffers(t_scene *scene)
{
	if (!(scene->depth_buffer = (double *)malloc(sizeof(double)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	if (!(scene->got_depth = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_depth_buffers(scene);
}

void	clean_depth_buffers(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->depth_buffer[i] = NOTHING_SELECTED;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->got_depth[i] = FALSE;
}

void	fill_depth_buffer(t_scene *scene, t_pixel pixel, double close)
{
	int	i;

	pixel.x = IMG_SIZE_W / 2 + pixel.x;
	pixel.y = IMG_SIZE_H / 2 - pixel.y;
	i = (int)(IMG_SIZE_W * (pixel.y - 1) + pixel.x);
	if (i > 0 && scene->got_depth[i] == FALSE)
	{
		scene->depth_buffer[i] = close;
		scene->got_depth[i] = TRUE;
	}
}

t_color	effect_depth(t_scene *scene, int i)
{
	double	tmp;
	t_color color;

	tmp = scene->depth_buffer[i] + 10;
	tmp = (int)(scene->k_depth_map / log(0.05 * (double)tmp));
	if (tmp > 255)
		tmp = 255;
	color.r = (int)tmp;
	color.g = (int)tmp;
	color.b = (int)tmp;
	color = to_negative(color);
	return (color);
}
