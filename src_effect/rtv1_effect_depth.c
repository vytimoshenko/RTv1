/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_depth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 10:45:25 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/25 15:20:20 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_color	effect_depth(t_scene *scene, int i)
{
	double	tmp;
	t_color color;

	tmp = scene->pixel_buffer[i].depth + 10;
	tmp = (int)(scene->k_depth_map / log(0.05 * (double)tmp));
	if (tmp > 255)
		tmp = 255;
	color.r = (int)tmp;
	color.g = (int)tmp;
	color.b = (int)tmp;
	color = to_negative(color);
	return (color);
}
