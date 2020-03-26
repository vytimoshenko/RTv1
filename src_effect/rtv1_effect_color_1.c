/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_color_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:38:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/26 19:09:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		unite_color_channels(t_color color)
{
	return (256 * 256 * color.r + 256 * color.g + color.b);
}

t_color	average_color_channels(t_color color)
{
	int tmp;

	tmp = (color.r + color.g + color.b) / 3;
	color.r = tmp;
	color.g = tmp;
	color.b = tmp;
	return (color);
}

t_color	split_color(int color)
{
	t_color result;

	result.r = color & 0xFF0000;
	result.g = color & 0x00FF00;
	result.b = color & 0x0000FF;
	return (result);
}

t_color	get_channel_diff(t_color c1, t_color c2)
{
	t_color	diff;

	diff.r = abs((c1.r - c2.r));
	diff.g = abs((c1.g - c2.g));
	diff.b = abs((c1.b - c2.b));
	return (diff);
}
