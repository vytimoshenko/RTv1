/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:38:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/01 20:20:48 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	deg_to_rad(int degrees)
{
	return ((double)degrees * PI / 180.0);
}

int		unite_color_channels(t_color color)
{
	return (256 * 256 * color.r + 256 * color.g + color.b);
}

void	motion_blur(t_color *frame_buffer, t_color **motion_blur_frame_buffers)
{
	int i;
	int n;
	int sum_r;
	int sum_g;
	int sum_b;
	
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		n = -1;
		sum_r = 0;
		sum_g = 0;
		sum_b = 0;
		while (++n < MOTION_BLUR_BUFFERS)
		{
			sum_r += motion_blur_frame_buffers[n][i].r;
			sum_g += motion_blur_frame_buffers[n][i].g;
			sum_b += motion_blur_frame_buffers[n][i].b;
		}
		frame_buffer[i].r = (int)(sum_r / MOTION_BLUR_BUFFERS);
		frame_buffer[i].g = (int)(sum_g / MOTION_BLUR_BUFFERS);
		frame_buffer[i].b = (int)(sum_b / MOTION_BLUR_BUFFERS);
	}
}

t_color	split_color(int color)
{
	t_color result;

	result.r = color / 256 / 256;
    result.g = color / 256 % 256;
    result.b = color % 256;
	return (result);
}

t_color	add_color(t_color c1, t_color c2)
{
	t_color result;

	if ((result.r = c1.r + c2.r) > 255)
		result.r = 255;
	if ((result.g = c1.g + c2.g) > 255)
		result.g = 255;
	if ((result.b = c1.b + c2.b) > 255)
		result.b = 255;
	return (result);
}

t_color	multiply_color(double k, t_color color)
{
	t_color result;

	if (k < 0)
		return (color);
	if ((result.r = k * color.r) > 255)
		result.r = 255;
	if ((result.g = k * color.g) > 255)
		result.g = 255;
	if ((result.b = k * color.b) > 255)
		result.b = 255;
	return (result);
}
