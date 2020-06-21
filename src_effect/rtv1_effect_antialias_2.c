/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_antialias_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:16:54 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:28:22 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	run_antialiasing(t_scene *scene)
{
	int			i;
	double		jitter[MULTI_SAMPLING_RATE];
	t_pix		pixel;

	get_jitter(jitter);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		if (scene->pixel_buffer[i].aliasing)
		{
			pixel.x = scene->pixel_buffer[i].x;
			pixel.y = scene->pixel_buffer[i].y;
			get_multisample_color(scene, &pixel, jitter);
			scene->pixel_buffer[i].color = pixel.color;
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

void	get_multisample_color(t_scene *scene, t_pix *pixel, double *jitter)
{
	int			i;
	t_vec	sum;
	t_vec	tmp;

	sum = (t_vec){0, 0, 0};
	i = -1;
	tmp.z = scene->cams.arr[scene->act_cam]->pos.z;
	while (++i < MULTI_SAMPLING_RATE)
	{
		tmp.x = 0;
		tmp.y = 0;
		pixel->color = (t_clr){0, 0, 0};
		get_pixel_viewport_coordinates(scene, pixel);
		tmp.x = jitter[i] + scene->cams.arr[scene->act_cam]->
		pos.x;
		tmp.y = jitter[i] + scene->cams.arr[scene->act_cam]->
		pos.y;
		trace_pixel(scene, tmp, pixel, REFLECTION_DEPTH);
		sum.x += pixel->color.r;
		sum.y += pixel->color.g;
		sum.z += pixel->color.b;
	}
	pixel->color.r = (sum.x / (MULTI_SAMPLING_RATE));
	pixel->color.g = (sum.y / (MULTI_SAMPLING_RATE));
	pixel->color.b = (sum.z / (MULTI_SAMPLING_RATE));
}
