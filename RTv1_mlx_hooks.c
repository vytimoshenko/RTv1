/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:44:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 01:28:35 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int		mouse_move(int x, int y, t_global *global)
{
	get_mouse_position(global->status, x, y);
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
	else
		return (0);
	draw(global);
	return (0);
}

int		keyboard_key_press(int key, t_global *global)
{
	if (key == Q || key == ESC || key == SPACE || key == E)
		extra_keyboard_key_press(key, global);
	else if (key == A || key == D || key == W || key == S || key == MORE ||
	key == LESS)
	{
		if (global->status->active_object == NO_OBJECT_SELECTED)
			rotate_camera(global->status, key);
		// else
		// 	rotate_object(global->status, key);
	}
	else if (key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_DOWN
	|| key == ARROW_UP || key == MINUS || key == PLUS)
	{
		if (global->status->active_object == NO_OBJECT_SELECTED)
			move_camera(global->status, key);
		else
			move_object(global->status, key);
	}
	else
		return (0);
	draw(global);
	return (0);
}

void	extra_keyboard_key_press(int key, t_global *global)
{
	if (key == Q)
		close_window(global);
	else if (key == ESC && global->status->active_object != NO_OBJECT_SELECTED)
		global->status->active_object = NO_OBJECT_SELECTED;
	else if (key == ESC && global->status->effect != NO_EFFECT)
		global->status->effect = NO_EFFECT;
	else if (key == SPACE)
		change_camera(global->status);
	else if (key == E)
		change_effect(global->status);
}

int		close_window(t_global *global)
{
	clean_mlx(global->mlx);
	exit(0);
}
