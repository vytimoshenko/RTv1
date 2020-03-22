/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_keyboard_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:25:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/22 23:18:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	change_mode(t_global *global, int key)
{
	if (key == ESC || key == L || key == M || key == O || key == E)
	{
		if (key == ESC)
			global->scene->active_mode = MODE_CAMERA;
		else if (key == L && global->scene->active_mode != MODE_LIGHT)
			global->scene->active_mode = MODE_LIGHT;
		else if (key == L && global->scene->active_mode == MODE_LIGHT)
			global->scene->active_mode = MODE_CAMERA;
		else if (key == M && global->scene->active_mode != MODE_MATERIAL)
			global->scene->active_mode = MODE_MATERIAL;
		else if (key == M && global->scene->active_mode == MODE_MATERIAL)
			global->scene->active_mode = MODE_CAMERA;
		else if (key == O && global->scene->active_mode != MODE_OBJECT)
			global->scene->active_mode = MODE_OBJECT;
		else if (key == O && global->scene->active_mode == MODE_OBJECT)
			global->scene->active_mode = MODE_CAMERA;
		else if (key == E && global->scene->active_mode != MODE_EFFECT)
			global->scene->active_mode = MODE_EFFECT;
		else if (key == E && global->scene->active_mode == MODE_EFFECT)
			global->scene->active_mode = MODE_CAMERA;
		if (key == L || key == M)
			update_interface_only(global);
		else
			draw(global);
	}
}

void	change_item(t_global *global, int key)
{
	if (key == LESS || key == MORE)
	{
		if (global->scene->active_mode == MODE_CAMERA)
			change_camera(global->scene, key);
		else if (global->scene->active_mode == MODE_LIGHT)
			change_light(global->scene, key);
		else if (global->scene->active_mode == MODE_OBJECT)
			change_object(global->scene, key);
		else if (global->scene->active_mode == MODE_MATERIAL)
			change_material(global->scene, key);
		else if (global->scene->active_mode == MODE_EFFECT)
			change_effect(global->scene, key);
		if (global->scene->active_mode == MODE_LIGHT ||
		global->scene->active_mode == MODE_MATERIAL)
			update_interface_only(global);
		else
			draw(global);
	}
}

void	change_grade(t_global *global, int key)
{
	if (key == PLUS || key == MINUS)
	{
		if (global->scene->active_mode == MODE_LIGHT)
			change_light_intensity(global->scene, key);
		else if (global->scene->active_mode == MODE_EFFECT)
			change_effect_grade(global->scene, key);
		else
			return;
		draw(global);
	}
	else if (key == T)
	{
		global->scene->antialiasing = global->scene->antialiasing == TRUE ?
		FALSE : TRUE;
		if (global->scene->active_mode != MODE_EFFECT)
			draw(global);
	}
}
