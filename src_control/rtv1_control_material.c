/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_material.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:13:46 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 16:06:25 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	change_material(t_scene *scene, int key)
{
	if (key == M)
	{
		if (scene->active_material == NOTHING_SELECTED)
		{
			scene->active_material = 0;
			scene->active_light = NOTHING_SELECTED;
			scene->active_object = NOTHING_SELECTED;
		}
		else
			scene->active_material = NOTHING_SELECTED;
	}
	else if (scene->active_material != NOTHING_SELECTED)
	{
        if (key == HOME && scene->active_material != scene->materials.quantity - 1)
			scene->active_material++;
		else if (key == HOME && scene->active_material == scene->materials.quantity - 1)
			scene->active_material = 0;
		else if (key == END && scene->active_material != 0)
			scene->active_material--;
		else if (key == END && scene->active_material == 0)
			scene->active_material = scene->materials.quantity - 1;
	}
}
