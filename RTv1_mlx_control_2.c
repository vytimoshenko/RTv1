/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_control_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 01:08:23 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/05 03:31:58 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_mouse_position(t_scene *scene, int x, int y)
{
	scene->x_mouse_position = x - IMG_SIZE_W / 2 - IMG_INDT_W;
	scene->y_mouse_position = IMG_SIZE_H / 2 - y + IMG_INDT_H;
	if (x < IMG_INDT_W || y < IMG_INDT_H || x > IMG_INDT_W + IMG_SIZE_W ||
	y > IMG_INDT_H + IMG_SIZE_H)
	{
		scene->x_mouse_position = 0;
		scene->y_mouse_position = 0;
	}
}

int		select_object(int x, int y, t_global *global)
{
	int	i;
	int object_id;

	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return (-1);
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	object_id = global->scene->object_buffer[i];
	if (global->scene->active_object == object_id)
		return (0);
	else
	{
		global->scene->active_object = object_id;
		return (1);
	}
}

void	change_camera(t_scene *scene)
{
	if (scene->current_camera != scene->cameras_quantity - 1)
		scene->current_camera++;
	else
		scene->current_camera = 0;
	get_sin_cos(scene->cameras[scene->current_camera]);
}

void	change_effect(t_scene *scene)
{
	if (scene->effect != EFFECTS_QUANTITY)
		scene->effect++;
	else
		scene->effect = NO_EFFECT;
}

void	change_effect_grade(t_scene *scene, int key)
{
	if (scene->effect == EFFECT_DEPTH_MAP || scene->effect == EFFECT_FOG)
	{
		if (key == HOME  && scene->depth_map_k < DEPTH_MAP_MAX)
			scene->depth_map_k *= DEPTH_MAP_INCREMENT;
		else if (key == END && scene->depth_map_k > DEPTH_MAP_MIN)
			scene->depth_map_k /= DEPTH_MAP_INCREMENT;
	}
}
