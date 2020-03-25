/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_pixelation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 12:55:58 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/25 18:45:21 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	effect_pixelation(t_scene *scene)
{
	int		x;
	int		y;
	int		pitch;
	t_color	color;

	y = 0;
	while (y < IMG_SIZE_H / scene->k_pixelation)
	{
		x = 0;
		while (x < IMG_SIZE_W / scene->k_pixelation)
		{
			pitch = x * scene->k_pixelation + y * IMG_SIZE_W *
			scene->k_pixelation;
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
	while (y < scene->k_pixelation)
	{
		i = pitch + y * IMG_SIZE_W - 1;
		while (i++ < pitch + y * IMG_SIZE_W - 1 + scene->k_pixelation)
		{
			color_r += scene->pixel_buffer[i].color.r;
			color_g += scene->pixel_buffer[i].color.g;
			color_b += scene->pixel_buffer[i].color.b;
		}
		y++;
	}
	color_r /= scene->k_pixelation * scene->k_pixelation;
	color_g /= scene->k_pixelation * scene->k_pixelation;
	color_b /= scene->k_pixelation * scene->k_pixelation;
	return ((t_color){color_r, color_g, color_b});
}

void	draw_macro_pixel(t_scene *scene, t_color color, int pitch)
{
	int i;
	int y;

	y = 0;
	while (y < scene->k_pixelation)
	{
		i = pitch + y * IMG_SIZE_W - 1;
		while (i++ < pitch + y * IMG_SIZE_W - 1 + scene->k_pixelation)
			scene->pixel_buffer[i].frame = color;
		y++;
	}
}
