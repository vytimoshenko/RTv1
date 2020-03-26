/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_antialias_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:09:46 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/26 11:19:16 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	fill_aliasing_buffer(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pixel_buffer[i].aliasing = need_to_smooth(scene, i);
		if (!((i + 1) % ((int)IMG_SIZE_W)) || !((i + 2) % ((int)IMG_SIZE_W)))
		{
			i++;
			continue;
		}
		if (scene->pixel_buffer[i].aliasing)
			add_adjacent_pixels(scene, i);
	}
}

int		need_to_smooth(t_scene *scene, int i)
{
	int		t;
	t_color	diff;

	diff = get_channel_diff(scene->pixel_buffer[i].color,
	scene->pixel_buffer[i + 1].color);
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

	y = ANTIALIASING_OUTLINE_WIDTH;
	while (y >= -ANTIALIASING_OUTLINE_WIDTH)
	{
		i = pos - y * IMG_SIZE_W;
		x = ANTIALIASING_OUTLINE_WIDTH;
		while (x >= -ANTIALIASING_OUTLINE_WIDTH)
		{
			if (i - x > 0 && i - x < IMG_SIZE_W * IMG_SIZE_H)
				scene->pixel_buffer[i - x].aliasing = TRUE;
			x--;
		}
		y--;
	}
}

t_color	effect_outline(t_scene *scene, int i)
{
	if (scene->pixel_buffer[i].aliasing)
		return ((t_color){255, 255, 255});
	else
		return ((t_color){0, 0, 0});
}
