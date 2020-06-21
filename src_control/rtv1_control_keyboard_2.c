/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_keyboard_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 23:09:56 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 12:34:32 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	move_item(t_global *global, int key)
{
	if (key == ARROW_LEFT || key == ARROW_RIGHT || key == ARROW_DOWN
	|| key == ARROW_UP || key == BRACKET_LEFT || key == BRACKET_RIGHT)
	{
		if (global->scene->act_mod == MODE_CAMERA)
			move_camera(global->scene, key);
		else if (global->scene->act_mod == MODE_LIGHT)
			move_light(global->scene, key);
		else if (global->scene->act_mod == MODE_OBJECT)
			move_object(global->scene, key);
		else
			return ;
		draw(global);
	}
}

void	rotate_item(t_global *global, int key)
{
	if (key == A || key == D || key == W || key == S || key == X ||
	key == Z)
	{
		if (global->scene->act_mod == MODE_CAMERA)
			rotate_camera(global->scene, key);
		else if (global->scene->act_mod == MODE_LIGHT)
			rotate_light(global->scene, key);
		else if (global->scene->act_mod == MODE_OBJECT)
			rotate_object(global->scene, key);
		else
			return ;
		draw(global);
	}
}

void	interface_actions(t_global *global, int key)
{
	if (key == H)
	{
		global->scene->show_help = global->scene->show_help ? FALSE : TRUE;
		global->scene->show_info = FALSE;
	}
	else if (key == I)
	{
		global->scene->show_info = global->scene->show_info ? FALSE : TRUE;
		global->scene->show_help = FALSE;
	}
	else if (key == Q)
		close_window(global);
	else
		return ;
	update_interface_only(global);
}

void	save_actions(t_global *global, int key)
{
	if (key == U)
	{
		global->scene->show_help = FALSE;
		global->scene->show_info = FALSE;
		update_interface_only(global);
		save_scene(global->scene, global->mlx);
		return ;
	}
	// else if (key == P)
	// {
	// 	global->scene->show_help = FALSE;
	// 	global->scene->show_info = FALSE;
	// 	update_interface_only(global);
	// 	save_screenshot(global->scene, global->mlx);
	// 	return;
	// }
	else
		return ;
	update_interface_only(global);
}
