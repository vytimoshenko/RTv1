/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_material.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:13:46 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 13:25:21 by mperseus         ###   ########.fr       */
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

// void	change_material_reflective(t_scene *scene, int key)
// {
// 	int i;

// 	i = scene->active_material;
// 	if (scene->active_material != NOTHING_SELECTED)
// 	{
// 		if (key == MINUS && scene->materials.array[i]->intensity >
// 		material_INTENSITY_MIN + material_INTENSITY_INCREMENT)
// 			scene->materials.array[i]->intensity -= material_INTENSITY_INCREMENT;
// 		else if (key == PLUS && scene->materials.array[i]->intensity <
// 		material_INTENSITY_MAX)
// 			scene->materials.array[i]->intensity += material_INTENSITY_INCREMENT;
// 		if (key == O && scene->materials.array[i]->off == TRUE)
// 			scene->materials.array[i]->off = FALSE;
// 		else if (key == O && scene->materials.array[i]->off == FALSE)
// 			scene->materials.array[i]->off = TRUE;
// 	}
// }