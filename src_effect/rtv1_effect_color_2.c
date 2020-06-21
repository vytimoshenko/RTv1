/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_color_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 07:14:17 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:23:04 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

t_clr	add_color(t_clr c1, t_clr c2)
{
	t_clr result;

	result.r = c1.r + c2.r > 255 ? 255 : c1.r + c2.r;
	result.g = c1.g + c2.g > 255 ? 255 : c1.g + c2.g;
	result.b = c1.b + c2.b > 255 ? 255 : c1.b + c2.b;
	return (result);
}

t_clr	multiply_color(double k, t_clr color)
{
	t_clr result;

	if (k < 0)
		return (color);
	result.r = k * color.r > 255 ? 255 : k * color.r;
	result.g = k * color.g > 255 ? 255 : k * color.g;
	result.b = k * color.b > 255 ? 255 : k * color.b;
	return (result);
}

t_clr	mix_color(t_clr c1, t_clr c2)
{
	t_clr result;

	result.r = (c1.r + c2.r) / 2;
	result.g = (c1.g + c2.g) / 2;
	result.b = (c1.b + c2.b) / 2;
	return (result);
}
