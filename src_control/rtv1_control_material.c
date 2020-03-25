/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_material.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:13:46 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/25 19:02:40 by mperseus         ###   ########.fr       */
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

	if (global->scene->active_mode == MODE_MATERIAL && x >= WIN_SIZE_W - 200 &&
	x < WIN_SIZE_W - 182 && y >= 283 && y < 301)
	{
		global->scene->material_source = global->scene->active_material;
		return ;
	}
	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return ;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	if (global->scene->pixel_buffer[i].object_id == NOTHING_SELECTED)
		return ;
	global->scene->material_source =
	global->scene->objects.array[global->scene->pixel_buffer[i].object_id]->material;
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
	if (global->scene->pixel_buffer[i].object_id == -1 || global->scene->
	objects.array[global->scene->pixel_buffer[i].object_id]->material ==
	global->scene->material_source)
	{
		global->scene->material_source = NOTHING_SELECTED;
		return (0);
	}
	global->scene->objects.array[global->scene->pixel_buffer[i].object_id]->material =
	global->scene->material_source;
	global->scene->material_source = NOTHING_SELECTED;
	system("afplay /System/Library/Sounds/Submarine.aiff");
	return (1);
}
