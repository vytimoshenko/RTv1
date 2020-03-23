/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_material.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:13:46 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/23 17:07:32 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	change_material(t_scene *scene, int key)
{
	if (key == MORE && scene->active_material != scene->materials.quantity - 1)
		scene->active_material++;
	else if (key == MORE && scene->active_material == scene->materials.quantity - 1)
		scene->active_material = 0;
	else if (key == LESS && scene->active_material != 0)
		scene->active_material--;
	else if (key == LESS && scene->active_material == 0)
		scene->active_material = scene->materials.quantity - 1;
}

void	get_material(int x, int y, t_global *global)
{
	int	i;

	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x >= WIN_SIZE_W - 200 && x < WIN_SIZE_W - 182 && y >= 217 && y < 235)
	{
		global->scene->material_source = global->scene->active_material;
		return ;
	}
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return ;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	global->scene->material_source =
	global->scene->objects.array[global->scene->object_buffer[i]]->material;
}

int		apply_material(int x, int y, t_global *global)
{
	int	i;

	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
	{
		global->scene->material_source = NOTHING_SELECTED;
		return (0);
	}
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	if (global->scene->object_buffer[i] == -1)
	{
		global->scene->material_source = NOTHING_SELECTED;
		return (0);
	}
	global->scene->objects.array[global->scene->object_buffer[i]]->material =
	global->scene->material_source;
	global->scene->material_source = NOTHING_SELECTED;
	system("afplay /System/Library/Sounds/Submarine.aiff");
	return (1);
}