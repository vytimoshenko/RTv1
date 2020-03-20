/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_final_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:22:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 18:25:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_color		pixel_post_processing(t_scene *scene, int i, t_color color)
{
	if (scene->active_object != NOTHING_SELECTED)
		color = shade_unselesected(scene, i, color);
	if (scene->effect == EFFECT_GRAYSCALE)
		color = effect_grayscale(color);
	else if (scene->effect == EFFECT_NEGATIVE)
		color = effect_negative(color);
	else if (scene->effect == EFFECT_CARTOON)
		color = effect_cartoon(scene, color);
	else if (scene->effect == EFFECT_OUTLINE)
		color = effect_outline(scene, i);
	else if (scene->effect == EFFECT_DEPTH)
		color = effect_depth(scene, i);
	return (color);
}

t_color	shade_unselesected(t_scene *scene, int i, t_color color)
{
	if (scene->object_buffer[i] != scene->active_object)
		return (multiply_color(SHADE_UNSELECTED, color));
	else
		return (color);
}

t_color	effect_outline(t_scene *scene, int i)
{
	if (scene->aliasing_buffer[i])
		return ((t_color){255, 255, 255});
	else
		return ((t_color){0, 0, 0});
}
