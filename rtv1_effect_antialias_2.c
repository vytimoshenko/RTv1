/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_antialias_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:16:54 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/17 14:19:21 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	run_anti_aliasing(t_scene *scene)
{
	t_pixel		pixel;
	double		jitter[MULTI_SAMPLING_RATE];
	int			i;

	get_jitter(jitter);
	pixel.x = -IMG_SIZE_W / 2;
	while (++pixel.x <= IMG_SIZE_W / 2)
	{
		pixel.y = -IMG_SIZE_H / 2;
		while (++pixel.y <= IMG_SIZE_H / 2)
		{
			i = (int)(IMG_SIZE_W * (IMG_SIZE_H / 2 - pixel.y - 1) +
			IMG_SIZE_W / 2 + pixel.x);
			if (scene->aliasing_buffer[i])
			{
				get_multisample_color(scene, &pixel, jitter);
				fill_frame_buffer(scene, pixel);
			}
		}
	}
}

void	get_jitter(double *random)
{
	int i;

	srand(42);
	i = -1;
	while (++i < MULTI_SAMPLING_RATE)
	{
		random[i] = (rand() % 100 + 1.0) / 5000.0;
		if (i % 2)
			random[i] *= -1;
	}
}
