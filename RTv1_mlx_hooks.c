/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:44:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/19 03:24:59 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

// int		mouse_move(int x, int y, t_global *global)
// {
// 	get_mouse_position(global->status, x, y);
// 	if (global->status->fractal_type == JULIA && !global->status->pause)
// 		set_julia(global->status, x, y);
// 	control_mouse_shift(global->status, x, y);
// 	if (global->status->middle_mouse_button)
// 		draw(global);
// 	else
// 		update_info_only(global);
// 	return (0);
// }

// int		mouse_key_press(int key, int x, int y, t_global *global)
// {
// 	if (key == MIDDLE_MOUSE_BUTTON)
// 		global->status->middle_mouse_button = 1;
// 	else if (key == MOUSE_SCROLL_UP || key == MOUSE_SCROLL_DOWN)
// 		control_mouse_zoom(global->status, x, y, key);
// 	else
// 		return (0);
// 	draw(global);
// 	return (0);
// }

// int		mouse_key_release(int key, int x, int y, t_global *global)
// {
// 	(void)x;
// 	(void)y;
// 	if (key == MIDDLE_MOUSE_BUTTON)
// 		global->status->middle_mouse_button = 0;
// 	return (0);
// }

int		keyboard_key_press(int key, t_global *global)
{
	if (key == ESC)
		close_window(global);
	// else if (key == SPACE)
	// 	global->status->pause = global->status->pause ? 0 : 1;
	// else if (key == RETURN)
	// 	control_type(global->status, global->mlx);
	// else if (key == C)
	// 	control_colors(global->status);
	// else if (key == H)
	// 	global->status->hide_info = global->status->hide_info ? 0 : 1;
	// else if (key == R)
	// {
	// 	reset_status(global->status);
	// 	reset_render_status(global->mlx);
	// }
	// else if (key == D)
	// 	control_device(global);
	// else if (key == LESS || key == MORE)
	// 	control_iteration(global->status, key);
	// else if (key == MINUS || key == PLUS)
	// 	control_zoom(global->status, key);
	// else if (key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_DOWN
	// || key == ARROW_UP)
	// 	control_shift(global->status, key);
	else
		return (0);
	draw(global);
	return (0);
}

int		close_window(t_global *global)
{
	clean_mlx(global->mlx);
	exit(0);
}
