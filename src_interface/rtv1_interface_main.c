/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:48:22 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/22 19:20:10 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	show_interface_1(t_global *global)
{
	info_camera(global->scene, global->mlx);
	info_render(global->mlx);
	info_coordinates(global->scene, global->mlx);
	if (global->scene->got_color == TRUE)
		info_color(global->scene, global->mlx);
	info_scene_file_name(global->scene, global->mlx);
    info_help_string(global->mlx);
}

void	show_interface_2(t_global *global)
{
    if (global->scene->active_mode == MODE_LIGHT)
		info_light(global->scene, global->mlx);
	if (global->scene->active_mode == MODE_MATERIAL)
        info_material(global->scene, global->mlx);
    if (global->scene->active_mode == MODE_OBJECT)
	{
        info_object(global->scene, global->mlx);
        info_material(global->scene, global->mlx);
    }
	if (global->scene->active_mode == MODE_EFFECT)
        info_effect(global->scene, global->mlx);
	if (global->scene->show_info == TRUE)
	{
		info_draw_box(global->mlx, INFO_BOX_W, INFO_BOX_H);
		info_scene(global->scene, global->mlx);
	}
    if (global->scene->show_help == TRUE)
		show_help(global->mlx);
}

void	show_help(t_mlx *mlx)
{
	info_draw_box(mlx, HELP_BOX_W, HELP_BOX_H);
	info_header_and_author(mlx);
	info_control_1(mlx);
	info_control_2(mlx);
	info_control_3(mlx);
}
