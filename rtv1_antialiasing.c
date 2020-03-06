/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_antialiasing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:09:46 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/07 01:54:55 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	fill_aliasing_buffer(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->aliasing_buffer[i] = need_to_smooth(scene, i);
		if (scene->aliasing_buffer[i])
		{
			scene->aliasing_buffer[i - 2] = 1;
			scene->aliasing_buffer[i - 1] = 1;
			scene->aliasing_buffer[i + 1] = 1;
			scene->aliasing_buffer[i + 2] = 1;
			if (i - 2 - IMG_SIZE_W > 0)
			{
				scene->aliasing_buffer[i - 2 - (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i - 1 - (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i - (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + 1 - (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + 2 - (int)IMG_SIZE_W] = 1;
			}
			if (i + 2 + IMG_SIZE_W < IMG_SIZE_W * IMG_SIZE_H)
			{
				scene->aliasing_buffer[i - 2 + (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i - 1 + (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + 1 + (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + 2 + (int)IMG_SIZE_W] = 1;
			}
			i++;
		}
	}
}

int	need_to_smooth(t_scene *scene, int i)
{
	t_color	diff;

	if (i == 0)
		return (0);
	diff = get_channel_diff(scene->frame_buffer[i], scene->frame_buffer[i - 1]);
	if (diff.r > 16 || diff.g > 16 || diff.b > 16)
		return (1);
	else
		return (0);
}

t_color	get_channel_diff(t_color c1, t_color c2)
{
	t_color	diff;

	diff.r = abs((c1.r - c2.r));
	diff.g = abs((c1.g - c2.g));
	diff.b = abs((c1.b - c2.b));
	return (diff);
}

void	anti_aliasing(t_scene *scene, t_pixel *pixel, double *jitter)
{
	int			i;
	t_color		sum;
	t_vector	tmp;

	sum = (t_color){0, 0, 0};
	i = -1;
	tmp.z = scene->cameras.array[scene->cameras.current]->position.z;
	while (++i < MULTI_SAMPLING_RATE)
	{
		tmp.x = 0;
		tmp.y = 0;
		pixel->color = scene->background;
		get_pixel_position(scene, pixel);
		tmp.x = jitter[i] + scene->cameras.array[scene->cameras.current]->position.x;
		tmp.y = jitter[i] + scene->cameras.array[scene->cameras.current]->position.y;
		get_pixel_color(scene, tmp, pixel, REFLECTION_DEPTH);
		sum.r += pixel->color.r;
		sum.g += pixel->color.g;
		sum.b += pixel->color.b;
	}
	pixel->color.r = (int)(sum.r / (MULTI_SAMPLING_RATE));
	pixel->color.g = (int)(sum.g / (MULTI_SAMPLING_RATE));
	pixel->color.b = (int)(sum.b / (MULTI_SAMPLING_RATE));
}

void	get_jitter(double *random)
{
    int i;

	srand(79);
    i = -1;
	for (i = 1; i <= MULTI_SAMPLING_RATE; i++)
	{
    	random[i] = (rand() % 100 + 1.0) / 5000.0;
		if (i % 2)
        	random[i] *= -1;
		// printf("%f\n", random[i]);
 	}
}