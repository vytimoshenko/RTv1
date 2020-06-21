/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_material.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:13:46 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:49:54 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	change_material(t_scene *scene, int key)
{
	if (key == MORE && scene->act_mat != scene->mats.quant - 1)
		scene->act_mat++;
	else if (key == MORE && scene->act_mat ==
	scene->mats.quant - 1)
		scene->act_mat = 0;
	else if (key == LESS && scene->act_mat != 0)
		scene->act_mat--;
	else if (key == LESS && scene->act_mat == 0)
		scene->act_mat = scene->mats.quant - 1;
}

void	get_material(int x, int y, t_global *global)
{
	int	i;

	if (global->scene->act_mod == MODE_MATERIAL && x >= WIN_SIZE_W - 200 &&
	x < WIN_SIZE_W - 182 && y >= 283 && y < 301)
	{
		global->scene->mat_source = global->scene->act_mat;
		return ;
	}
	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return ;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	if (global->scene->pixel_buffer[i].obj_id == NOTHING_SELECTED)
		return ;
	global->scene->mat_source =
	global->scene->objs.arr[global->scene->pixel_buffer[i].obj_id]->
	mat;
}

int		apply_material(int x, int y, t_global *global)
{
	int	i;

	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
	{
		global->scene->mat_source = NOTHING_SELECTED;
		return (0);
	}
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	if (global->scene->pixel_buffer[i].obj_id == -1 || global->scene->
	objs.arr[global->scene->pixel_buffer[i].obj_id]->mat ==
	global->scene->mat_source)
	{
		global->scene->mat_source = NOTHING_SELECTED;
		return (0);
	}
	global->scene->objs.arr[global->scene->pixel_buffer[i].obj_id]->
	mat = global->scene->mat_source;
	global->scene->mat_source = NOTHING_SELECTED;
	system("afplay /System/Library/Sounds/Submarine.aiff");
	return (1);
}
