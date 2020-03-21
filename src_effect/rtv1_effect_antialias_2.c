/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_antialias_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:16:54 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 10:53:18 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	run_antialiasing(t_scene *scene)
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

void	get_multisample_color(t_scene *scene, t_pixel *pixel, double *jitter)
{
	int			i;
	t_color		sum;
	t_vector	tmp;

	sum = (t_color){0, 0, 0};
	i = -1;
	tmp.z = scene->cameras.array[scene->active_camera]->position.z;
	while (++i < MULTI_SAMPLING_RATE)
	{
		tmp.x = 0;
		tmp.y = 0;
		pixel->color = scene->background;
		get_pixel_position(scene, pixel);
		tmp.x = jitter[i] + scene->cameras.array[scene->active_camera]->
		position.x;
		tmp.y = jitter[i] + scene->cameras.array[scene->active_camera]->
		position.y;
		get_pixel_color(scene, tmp, pixel, REFLECTION_DEPTH);
		sum.r += pixel->color.r;
		sum.g += pixel->color.g;
		sum.b += pixel->color.b;
	}
	pixel->color.r = (int)(sum.r / (MULTI_SAMPLING_RATE));
	pixel->color.g = (int)(sum.g / (MULTI_SAMPLING_RATE));
	pixel->color.b = (int)(sum.b / (MULTI_SAMPLING_RATE));
}

t_color	effect_outline(t_scene *scene, int i)
{
	if (scene->aliasing_buffer[i])
		return ((t_color){255, 255, 255});
	else
		return ((t_color){0, 0, 0});
}
