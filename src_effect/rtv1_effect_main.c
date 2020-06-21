/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:22:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:23:04 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void		final_processing(t_mlx *mlx, t_scene *scene)
{
	int	i;

	if (scene->antialiasing == TRUE && scene->act_mod != MODE_EFFECT)
		run_antialiasing(scene);
	if (scene->act_mod == MODE_EFFECT &&
	scene->act_eff == EFFECT_PIXELATION)
		effect_pixelation(scene);
	else if (scene->act_mod == MODE_EFFECT &&
	scene->act_eff == EFFECT_ANAGLYPH)
		effect_anaglyph(scene);
	else
	{
		i = -1;
		while (++i < IMG_SIZE_W * IMG_SIZE_H)
			scene->pixel_buffer[i].frame = pixel_post_processing(scene, i,
			scene->pixel_buffer[i].color);
	}
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->data[i] = unite_color_channels(scene->pixel_buffer[i].frame);
}

t_clr		pixel_post_processing(t_scene *scene, int i, t_clr color)
{
	if (scene->act_mod == MODE_OBJECT)
		color = shade_unselesected(scene, i, color);
	else if (scene->act_mod == MODE_EFFECT)
	{
		if (scene->act_eff == EFFECT_GRAYSCALE)
			color = to_grayscale(color);
		else if (scene->act_eff == EFFECT_NEGATIVE)
			color = to_negative(color);
		else if (scene->act_eff == EFFECT_CARTOON)
			color = to_cartoon(scene, color);
		else if (scene->act_eff == EFFECT_OUTLINE)
			color = effect_outline(scene, i);
		else if (scene->act_eff == EFFECT_DEPTH)
			color = effect_depth(scene, i);
	}
	return (color);
}
