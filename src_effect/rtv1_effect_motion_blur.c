/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_motion_blur.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 13:17:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 13:19:41 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

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
