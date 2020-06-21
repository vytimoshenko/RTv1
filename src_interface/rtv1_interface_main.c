/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 10:59:59 by vitaly            #+#    #+#             */
/*   Updated: 2020/06/21 11:15:24 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	show_interface(t_global *global)
{
	info_camera(global->scene, global->mlx);
	if (global->scene->active_mode == MODE_LIGHT)
		info_light(global->scene, global->mlx);
	else if (global->scene->active_mode == MODE_MATERIAL)
		info_material(global->scene, global->mlx);
	else if (global->scene->active_mode == MODE_OBJECT)
	{
		info_object(global->scene, global->mlx);
		info_material(global->scene, global->mlx);
	}
	info_effect(global->scene, global->mlx);
	info_render(global->mlx);
	info_coordinates(global->scene, global->mlx);
	if (global->scene->got_color == TRUE)
		info_color(global->scene, global->mlx);
	info_scene_file_name(global->scene, global->mlx);
	info_help_string(global->mlx);
	if (global->scene->show_info == TRUE)
	{
		info_draw_box(global->mlx, INFO_BOX_W, INFO_BOX_H);
		info_scene(global->scene, global->mlx);
	}
	else if (global->scene->show_help == TRUE)
		show_help(global->mlx);
}
