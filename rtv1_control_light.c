/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:33:55 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/08 01:04:45 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	change_light(t_scene *scene, int key)
{
	if (key == L)
	{
		if (scene->active_light == NOTHING_SELECTED)
		{
			scene->active_light = 0;
			scene->active_object = NOTHING_SELECTED;
		}
		else
			scene->active_light = NOTHING_SELECTED;
	}
	else if (scene->active_light != NOTHING_SELECTED)
	{
		if (key == HOME && scene->active_light != scene->lights.quantity - 1)
			scene->active_light++;
		else if (key == HOME && scene->active_light == scene->lights.quantity - 1)
			scene->active_light = 0;
		else if (key == END && scene->active_light != 0)
			scene->active_light--;
		else if (key == END && scene->active_light == 0)
			scene->active_light = scene->lights.quantity - 1;
	}
}

void	change_light_intensity(t_scene *scene, int key)
{
	if (scene->active_light != NOTHING_SELECTED)
	{
		if (key == MINUS && scene->lights.array[scene->active_light]->intensity
		> LIGHT_INTENSITY_MIN + LIGHT_INTENSITY_INCREMENT)
			scene->lights.array[scene->active_light]->intensity -=
			LIGHT_INTENSITY_INCREMENT;
		else if (key == PLUS && scene->lights.array[scene->active_light]->intensity
		< LIGHT_INTENSITY_MAX)
			scene->lights.array[scene->active_light]->intensity +=
			LIGHT_INTENSITY_INCREMENT;
		if (key == O && scene->lights.array[scene->active_light]->off == TRUE)
			scene->lights.array[scene->active_light]->off = FALSE;
		else if (key == O && scene->lights.array[scene->active_light]->off == FALSE)
			scene->lights.array[scene->active_light]->off = TRUE;
	}
}