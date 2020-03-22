/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_keyboard.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:25:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/22 20:21:42 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		keyboard_key_press(int key, t_global *global)
{
	if (key == ESC || key == L || key == M || key == O || key == E)
	{
		change_mode(global->scene, key);
		if (key == L || key == M)
		{
			update_interface_only(global);
			return (0);
		}
	}
	else if (key == LESS || key == MORE)
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
		if (global->scene->active_mode != MODE_CAMERA &&
		global->scene->active_mode != MODE_OBJECT &&
		global->scene->active_mode != MODE_EFFECT)
		{
			update_interface_only(global);
			return (0);
		}
	}
	else if (key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_DOWN
	|| key == ARROW_UP || key == BRACKET_LEFT || key == BRACKET_RIGHT)
	{
		if (global->scene->active_mode == MODE_CAMERA)
			move_camera(global->scene, key);
		else if (global->scene->active_mode == MODE_LIGHT)
			move_light(global->scene, key);
		else if (global->scene->active_mode == MODE_OBJECT)
			move_object(global->scene, key);
	}
	else if (key == A || key == D || key == W || key == S || key == X ||
	key == Z)
	{
		if (global->scene->active_mode == MODE_CAMERA)
			rotate_camera(global->scene, key);
		else if (global->scene->active_mode == MODE_LIGHT)
			rotate_light(global->scene, key);
		else if (global->scene->active_mode == MODE_OBJECT)
			rotate_object(global->scene, key);
	}
	else if (key == PLUS || key == MINUS)
	{
		if (global->scene->active_mode == MODE_LIGHT)
			change_light_intensity(global->scene, key);
		else if (global->scene->active_mode == MODE_EFFECT)
			change_effect_grade(global->scene, key);
	}
	else if (key == P)
	{
		update_interface_only(global);
		save_screenshot(global->scene, global->mlx);
		return (0);
	}
	else if (key == U)
	{
		update_interface_only(global);
		save_scene(global->scene, global->mlx);
		return (0);
	}
	else if (key == H)
	{
		global->scene->show_help = global->scene->show_help ? FALSE : TRUE;
		global->scene->show_info = FALSE;
		update_interface_only(global);
		return (0);
	}
	else if (key == I)
	{
		global->scene->show_info = global->scene->show_info ? FALSE : TRUE;
		global->scene->show_help = FALSE;
		update_interface_only(global);
		return (0);
	}
	else if (key == T)
		global->scene->antialiasing = global->scene->antialiasing == TRUE ?
		FALSE : TRUE;
	else if (key == Q)
		close_window(global);
	else
		return (0);
	draw(global);
	return (0);
}

void	change_mode(t_scene *scene, int key)
{
	if (key == ESC)
		scene->active_mode = MODE_CAMERA;
	else if (key == L && scene->active_mode != MODE_LIGHT)
		scene->active_mode = MODE_LIGHT;
	else if (key == L && scene->active_mode == MODE_LIGHT)
		scene->active_mode = MODE_CAMERA;
	else if (key == M && scene->active_mode != MODE_MATERIAL)
		scene->active_mode = MODE_MATERIAL;
	else if (key == M && scene->active_mode == MODE_MATERIAL)
		scene->active_mode = MODE_CAMERA;
	else if (key == O && scene->active_mode != MODE_OBJECT)
		scene->active_mode = MODE_OBJECT;
	else if (key == O && scene->active_mode == MODE_OBJECT)
		scene->active_mode = MODE_CAMERA;
	else if (key == E && scene->active_mode != MODE_EFFECT)
		scene->active_mode = MODE_EFFECT;
	else if (key == E && scene->active_mode == MODE_EFFECT)
		scene->active_mode = MODE_CAMERA;
}
