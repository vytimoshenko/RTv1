/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_hooks_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:44:00 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 13:25:25 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		mouse_move(int x, int y, t_global *global)
{
	get_mouse_position(global->scene, x, y);
	update_interface_only(global);
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
		update_interface_only(global);
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

int		close_window(t_global *global)
{
	clean_mlx(global->mlx);
	IMG_Quit();
	SDL_Quit();
	exit(0);
}
