/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_pixelation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:55:58 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/16 16:30:31 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	effect_pixelation(t_scene *scene)
{
	int		x;
	int		y;
	int		pitch;
	t_color	color;

	y = 0;
	while (y < IMG_SIZE_H / scene->pixelation_k)
	{
		x = 0;
		while (x < IMG_SIZE_W / scene->pixelation_k)
		{
			pitch = x * scene->pixelation_k + y * IMG_SIZE_W *
			scene->pixelation_k;
			color = get_average_color(scene, pitch);
			draw_macro_pixel(scene, color, pitch);
			x++;
		}
		y++;
	}
}

t_color	get_average_color(t_scene *scene, int pitch)
{
	int		i;
	int		y;
	long	color_r;
	long	color_g;
	long	color_b;

	color_r = 0;
	color_g = 0;
	color_b = 0;
	y = 0;
	while (y < scene->pixelation_k)
	{
		i = pitch + y * IMG_SIZE_W - 1;
		while (i++ < pitch + y * IMG_SIZE_W - 1 + scene->pixelation_k)
		{
			color_r += scene->frame_buffer[i].r;
			color_g += scene->frame_buffer[i].g;
			color_b += scene->frame_buffer[i].b;
		}
		y++;
	}
	color_r /= scene->pixelation_k * scene->pixelation_k;
	color_g /= scene->pixelation_k * scene->pixelation_k;
	color_b /= scene->pixelation_k * scene->pixelation_k;
	return ((t_color){color_r, color_g, color_b});
}

void	draw_macro_pixel(t_scene *scene, t_color color, int pitch)
{
	int i;
	int y;

	y = 0;
	while (y < scene->pixelation_k)
	{
		i = pitch + y * IMG_SIZE_W - 1;
		while (i++ < pitch + y * IMG_SIZE_W - 1 + scene->pixelation_k)
			scene->frame_buffer[i] = color;
		y++;
	}
}
