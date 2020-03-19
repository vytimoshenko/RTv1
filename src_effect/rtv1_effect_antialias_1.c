/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_antialias_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:09:46 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 13:12:29 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	fill_aliasing_buffer(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->aliasing_buffer[i] = need_to_smooth(scene, i);
		if (!((i + 1) % ((int)IMG_SIZE_W)) || !((i + 2) % ((int)IMG_SIZE_W)))
		{
			i += 4;
			continue;
		}
		if (scene->aliasing_buffer[i])
			add_adjacent_pixels(scene, i);
	}
	aliasing_buffer_rate(scene);
}

int		need_to_smooth(t_scene *scene, int i)
{
	int		t;
	t_color	diff;

	diff = get_channel_diff(scene->frame_buffer[i], scene->frame_buffer[i + 1]);
	t = ANTIALIASING_COLOR_THRESHOLD;
	if (diff.r >= t || diff.g >= t || diff.b >= t)
		return (1);
	else
		return (0);
}

void	add_adjacent_pixels(t_scene *scene, int pos)
{
	int	x;
	int	y;
	int	i;

	y = ANTIALIASING_ADJACENT_PIXELS;
	while (y >= -ANTIALIASING_ADJACENT_PIXELS)
	{
		i = pos - y * IMG_SIZE_W;
		x = ANTIALIASING_ADJACENT_PIXELS;
		while (x >= -ANTIALIASING_ADJACENT_PIXELS)
		{
			if (i - x > 0 && i - x < IMG_SIZE_W * IMG_SIZE_H)
				scene->aliasing_buffer[i - x] = TRUE;
			x--;
		}
		y--;
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

void	aliasing_buffer_rate(t_scene *scene)
{
	int	i;
	int	p;

	i = -1;
	p = 0;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		p = scene->aliasing_buffer[i] == TRUE ? p + 1 : p;
	scene->aliasing_rate = p / (IMG_SIZE_W * IMG_SIZE_H);
	printf("buffer: %d rate: %f\n", p, scene->aliasing_rate);
}
