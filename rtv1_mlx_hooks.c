/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:44:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/15 06:07:44 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		mouse_move(int x, int y, t_global *global)
{
	get_mouse_position(global->scene, x, y);
	update_info_only(global);
	return (0);
}

int		mouse_key_press(int key, int x, int y, t_global *global)
{
	if (key == LEFT_MOUSE_BUTTON)
	{
		if (!(select_object(x, y, global)))
			return (0);
	}
	else if (key == RIGHT_MOUSE_BUTTON)
	{
		pick_color(global->scene, x, y);
		update_info_only(global);
		return (0);
	}
	else if (key == MIDDLE_MOUSE_BUTTON)
	{
		get_material(x, y, global);
		return (0);
	}
	draw(global);
	return (0);
}

int		mouse_key_release(int key, int x, int y, t_global *global)
{
	if (key == MIDDLE_MOUSE_BUTTON && global->scene->material_source
	!= NOTHING_SELECTED)
	{
		if (apply_material(x, y, global))
			draw(global);
	}
	return (0);
}

int		keyboard_key_press(int key, t_global *global)
{
	if (key == Y)
	{
		update_info_only(global);
		save_screenshot(global->scene, global->mlx);
		return (0);
	}
	else if (key == U)
	{
		update_info_only(global);
		save_scene(global->scene, global->mlx);
		return (0);
	}
	else if (key == A || key == D || key == W || key == S || key == MORE ||
	key == LESS)
	{
		if (global->scene->active_light != NOTHING_SELECTED)
			rotate_light(global->scene, key);
		else if (global->scene->active_object != NOTHING_SELECTED)
			rotate_object(global->scene, key);
		else
			rotate_camera(global->scene, key);
	}
	else if (key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_DOWN
	|| key == ARROW_UP || key == PAGE_UP || key == PAGE_DOWN)
	{
		if (global->scene->active_light != NOTHING_SELECTED)
			move_light(global->scene, key);
		else if (global->scene->active_object != NOTHING_SELECTED)
			move_object(global->scene, key);
		else
			move_camera(global->scene, key);
	}
	else if (key == H)
		global->scene->show_help = global->scene->show_help ? 0 : 1;
	// else if (key == M)
	// 	global->scene->in_motion_blur = TRUE;
	else if (key == I)
		global->scene->anti_aliasing = global->scene->anti_aliasing == TRUE ?
		FALSE : TRUE;
	else if (key == PLUS || key == MINUS || key == O)
	{
		change_effect_grade(global->scene, key);
		change_light_intensity(global->scene, key);
	}
	else if (key == L || key == HOME || key == END)
		change_light(global->scene, key);
	// else if (key == M || key == HOME || key == END)
	// 	change_material(global->scene, key);
	else if (key == Q || key == ESC || key == SPACE || key == E)
		extra_keyboard_key_press(key, global);
	else
		return (0);
	draw(global);
	return (0);
}

void	extra_keyboard_key_press(int key, t_global *global)
{
	if (key == Q)
		close_window(global);
	else if (key == ESC && (global->scene->active_object != NOTHING_SELECTED ||
	global->scene->active_light != NOTHING_SELECTED ||
	global->scene->got_color == TRUE))
	{
		global->scene->active_object = NOTHING_SELECTED;
		global->scene->active_light = NOTHING_SELECTED;
		global->scene->got_color = FALSE;
	}
	else if (key == ESC && global->scene->effect != NO_EFFECT)
		global->scene->effect = NO_EFFECT;
	else if (key == SPACE)
		change_camera(global->scene);
	else if (key == E)
		change_effect(global->scene);
}

int		close_window(t_global *global)
{
	clean_mlx(global->mlx);
	IMG_Quit();
	SDL_Quit();
	exit(0);
}
