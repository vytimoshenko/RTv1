/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_color_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:19:30 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 11:26:16 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_color	to_grayscale(t_color color)
{
	int tmp;

	tmp = 0.2126 * color.r + 0.7152 * color.g + 0.0722 * color.b;
	color.r = tmp;
	color.g = tmp;
	color.b = tmp;
	return (color);
}

t_color	to_negative(t_color color)
{
	color.r = 255 - color.r;
	color.g = 255 - color.g;
	color.b = 255 - color.b;
	return (color);
}

t_color	to_cartoon(t_scene *scene, t_color color)
{
	color.r /= scene->k_cartoon;
	color.g /= scene->k_cartoon;
	color.b /= scene->k_cartoon;
	color.r *= scene->k_cartoon;
	color.g *= scene->k_cartoon;
	color.b *= scene->k_cartoon;
	return (color);
}