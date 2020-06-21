/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_color_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:38:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:23:04 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

int		unite_color_channels(t_clr color)
{
	return (256 * 256 * color.r + 256 * color.g + color.b);
}

t_clr	average_color_channels(t_clr color)
{
	int tmp;

	tmp = (color.r + color.g + color.b) / 3;
	color.r = tmp;
	color.g = tmp;
	color.b = tmp;
	return (color);
}

t_clr	split_color(int color)
{
	t_clr result;

	result.r = (unsigned char)(color & 0xFF0000);
	result.g = (unsigned char)(color & 0x00FF00);
	result.b = (unsigned char)(color & 0x0000FF);
	return (result);
}

t_clr	get_channel_diff(t_clr c1, t_clr c2)
{
	t_clr	diff;

	diff.r = abs((c1.r - c2.r));
	diff.g = abs((c1.g - c2.g));
	diff.b = abs((c1.b - c2.b));
	return (diff);
}
