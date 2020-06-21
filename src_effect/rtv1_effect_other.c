/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:14:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 14:50:11 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

t_clr	shade_unselesected(t_scene *scene, int i, t_clr color)
{
	if (scene->pix_buff[i].obj_id != scene->act_obj)
		return (multiply_color(SHADE_UNSELECTED, color));
	else
		return (color);
}

t_clr	effect_depth(t_scene *scene, int i)
{
	double	tmp;
	t_clr	color;

	tmp = scene->pix_buff[i].depth + 10;
	tmp = (int)(scene->k_depth_map / log(0.05 * (double)tmp));
	if (tmp > 255)
		tmp = 255;
	color.r = (unsigned char)tmp;
	color.g = (unsigned char)tmp;
	color.b = (unsigned char)tmp;
	color = to_negative(color);
	return (color);
}

void	effect_anaglyph(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->pix_buff[i].anaglyph = scene->pix_buff[i].color;
	scene->cams.arr[scene->act_cam]->pos.x += 1;
	trace_rays(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pix_buff[i].frame.r = (average_color_channels(scene->
		pix_buff[i].anaglyph)).r;
		scene->pix_buff[i].frame.g = 0;
		scene->pix_buff[i].frame.b = (average_color_channels(scene->
		pix_buff[i].color)).b;
	}
}
