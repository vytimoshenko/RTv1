/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_hooks_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:25:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 16:29:35 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		keyboard_key_press(int key, t_global *global)
{
	if (key == P)
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
	else if (key == J)
	{
		effect_anaglyph(global->scene, global->mlx);
		// update_interface_only(global);
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
	else if (key == O && global->scene->active_light != NOTHING_SELECTED)
	{
		change_light_intensity(global->scene, key);
		draw(global);
	}
	else if (key == PLUS || key == MINUS)
	{
		change_effect_grade(global->scene, key);
		update_interface_only(global);
	}
	else if (key == L || key == HOME || key == END)
	{
		change_light(global->scene, key);
		update_interface_only(global);
		return (0);
	}
	else if (key == M || key == HOME || key == END)
	{
		if (global->scene->active_object != NOTHING_SELECTED)
		{
			change_material(global->scene, key);
			draw(global);
		}
		else
		{
			change_material(global->scene, key);
			update_interface_only(global);
			return (0);
		}
	}
	if (key == ESC && (global->scene->active_light != NOTHING_SELECTED ||
	global->scene->active_material != NOTHING_SELECTED ||
	global->scene->show_help == TRUE || global->scene->show_info == TRUE ||
	global->scene->got_color == TRUE))
	{
		global->scene->active_light = NOTHING_SELECTED;
		global->scene->active_material = NOTHING_SELECTED;
		global->scene->show_help = FALSE;
		global->scene->show_info = FALSE;
		global->scene->got_color = FALSE;
		update_interface_only(global);
		return (0);
	}
	else if (key == ESC && global->scene->active_object != NOTHING_SELECTED)
		global->scene->active_object = NOTHING_SELECTED;
	else if (key == ESC && global->scene->effect != NO_EFFECT)
		global->scene->effect = NO_EFFECT;
	else if (key == Q || key == SPACE)
		keyboard_key_press_extra_1(key, global);
	else if (key == E)
	{
		change_effect(global->scene);
		update_interface_only(global);
	}
	else
		return (0);
	draw(global);
	return (0);
}

void	keyboard_key_press_extra_1(int key, t_global *global)
{
	if (key == Q)
		close_window(global);

	else if (key == SPACE)
		change_camera(global->scene);
}
