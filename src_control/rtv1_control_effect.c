/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_effect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 16:56:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/22 18:42:46 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	change_effect(t_scene *scene, int key)
{
    if (key == MORE && scene->active_effect != EFFECTS_QUANTITY - 1)
        scene->active_effect++;
    else if (key == MORE && scene->active_effect == EFFECTS_QUANTITY - 1)
        scene->active_effect = 0;
    else if (key == LESS && scene->active_effect != 0)
        scene->active_effect--;
    else if (key == LESS && scene->active_effect == 0)
        scene->active_effect = EFFECTS_QUANTITY - 1;
}

void	change_effect_grade(t_scene *scene, int key)
{
	if (scene->active_effect == EFFECT_CARTOON)
	{
		if (key == MINUS && scene->k_cartoon > CARTOON_MIN)
			scene->k_cartoon /= CARTOON_INCREMENT;
		else if (key == PLUS && scene->k_cartoon < CARTOON_MAX)
			scene->k_cartoon *= CARTOON_INCREMENT;
	}
	else if (scene->active_effect == EFFECT_PIXELATION)
	{
		if (key == MINUS && scene->k_pixelation > PIXELATION_MIN)
			scene->k_pixelation /= PIXELATION_INCREMENT;
		else if (key == PLUS && scene->k_pixelation < PIXELATION_MAX)
			scene->k_pixelation *= PIXELATION_INCREMENT;
	}
	else if (scene->active_effect == EFFECT_DEPTH)
	{
		if (key == MINUS && scene->k_depth_map > DEPTH_MAP_MIN)
			scene->k_depth_map /= DEPTH_MAP_INCREMENT;
		else if (key == PLUS && scene->k_depth_map < DEPTH_MAP_MAX)
			scene->k_depth_map *= DEPTH_MAP_INCREMENT;
	}
}
