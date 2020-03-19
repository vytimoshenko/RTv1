/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:37:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 13:25:14 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

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

void	change_camera(t_scene *scene)
{
	if (scene->active_camera != scene->cameras.quantity - 1)
		scene->active_camera++;
	else
		scene->active_camera = 0;
	get_sin_cos(scene->cameras.array[scene->active_camera]);
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
		if (key == MINUS && scene->depth_map_k < DEPTH_MAP_MAX)
			scene->depth_map_k *= DEPTH_MAP_INCREMENT;
		else if (key == PLUS && scene->depth_map_k > DEPTH_MAP_MIN)
			scene->depth_map_k /= DEPTH_MAP_INCREMENT;
	}
	else if (scene->effect == EFFECT_PIXELATION)
	{
		if (key == MINUS && scene->pixelation_k > PIXELATION_MIN)
			scene->pixelation_k /= PIXELATION_INCREMENT;
		else if (key == PLUS && scene->pixelation_k < PIXELATION_MAX)
			scene->pixelation_k *= PIXELATION_INCREMENT;
	}
}

void	pick_color(t_scene *scene, int x, int y)
{
	int	i;

	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	scene->picked_color = scene->frame_buffer[i];
	scene->got_color = 1;
	system("afplay /System/Library/Sounds/Tink.aiff");
}
