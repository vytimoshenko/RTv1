/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:22:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 11:27:54 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void		final_processing(t_mlx *mlx, t_scene *scene)
{
	int	i;

	fill_aliasing_buffer(scene);
	if (scene->antialiasing == TRUE)
		run_antialiasing(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i] = pixel_post_processing(scene, i,
		scene->frame_buffer[i]);
	if (scene->effect == EFFECT_PIXELATION)
		effect_pixelation(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->data[i] = unite_color_channels(scene->frame_buffer[i]);
}

t_color		pixel_post_processing(t_scene *scene, int i, t_color color)
{
	if (scene->active_object != NOTHING_SELECTED)
		color = shade_unselesected(scene, i, color);
	if (scene->effect == EFFECT_GRAYSCALE)
		color = to_grayscale(color);
	else if (scene->effect == EFFECT_NEGATIVE)
		color = to_negative(color);
	else if (scene->effect == EFFECT_CARTOON)
		color = to_cartoon(scene, color);
	else if (scene->effect == EFFECT_OUTLINE)
		color = effect_outline(scene, i);
	else if (scene->effect == EFFECT_DEPTH)
		color = effect_depth(scene, i);
	return (color);
}
