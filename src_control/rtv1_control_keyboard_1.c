/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_keyboard_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:25:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/25 20:50:50 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	escape_key(t_global *global, int key)
{
	if (key == ESC)
	{
		global->scene->show_help = FALSE;
		global->scene->show_info = FALSE;
		global->scene->got_color = FALSE;
		if (global->scene->active_mode == MODE_OBJECT)
		{
			global->scene->active_mode = MODE_CAMERA;
			update_interface_and_frame(global);
		}
		if (global->scene->active_mode == MODE_EFFECT)
		{
			global->scene->active_mode = MODE_CAMERA;
			update_interface_and_frame(global);
		}
		else
		{
			global->scene->active_mode = MODE_CAMERA;
			update_interface_only(global);
		}
	}
}

void	change_mode_1(t_global *global, int key)
{
	if (key == L || key == M)
	{
		if (key == L && global->scene->active_mode != MODE_LIGHT)
			global->scene->active_mode = MODE_LIGHT;
		else if (key == L && global->scene->active_mode == MODE_LIGHT)
			global->scene->active_mode = MODE_CAMERA;
		else if (key == M && global->scene->active_mode != MODE_MATERIAL)
		{
			if (global->scene->active_mode == MODE_OBJECT)
			{
				global->scene->active_mode = MODE_MATERIAL;
				update_interface_and_frame(global);
				return ;
			}
			global->scene->active_mode = MODE_MATERIAL;
		}
		else if (key == M && global->scene->active_mode == MODE_MATERIAL)
			global->scene->active_mode = MODE_CAMERA;
		update_interface_only(global);
	}
}

void	change_mode_2(t_global *global, int key)
{
	if (key == O || key == E)
	{
		if (key == O && global->scene->active_mode != MODE_OBJECT)
			global->scene->active_mode = MODE_OBJECT;
		else if (key == O && global->scene->active_mode == MODE_OBJECT)
			global->scene->active_mode = MODE_CAMERA;
		else if (key == E && global->scene->active_mode != MODE_EFFECT)
			global->scene->active_mode = MODE_EFFECT;
		else if (key == E && global->scene->active_mode == MODE_EFFECT)
			global->scene->active_mode = MODE_CAMERA;
		update_interface_and_frame(global);
	}
}

void	change_item(t_global *global, int key)
{
	if (key == LESS || key == MORE)
	{
		if (global->scene->active_mode == MODE_CAMERA)
		{
			change_camera(global->scene, key);
			draw(global);
			return ;
		}
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
			update_interface_and_frame(global);
	}
}

void	change_grade(t_global *global, int key)
{
	if (key == PLUS || key == MINUS || key == B)
	{
		if (global->scene->active_mode == MODE_LIGHT)
			change_light_intensity(global->scene, key);
		else if (global->scene->active_mode == MODE_EFFECT)
		{
			change_effect_grade(global->scene, key);
			update_interface_and_frame(global);
			return ;
		}
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
