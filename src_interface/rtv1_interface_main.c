/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:48:22 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 15:54:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"
#include "../rtv1_interface.h"

void	show_interface_1(t_global *global)
{
	info_effect_1(global->scene, global->mlx);
	info_effect_2(global->scene, global->mlx);
	info_effect_3(global->scene, global->mlx);
	info_camera_1(global->scene, global->mlx);
	info_camera_2(global->scene, global->mlx);
	info_render_1(global->mlx);
	info_render_2(global->mlx);
	info_coordinates(global->scene, global->mlx);
	if (global->scene->got_color == TRUE)
		info_color(global->scene, global->mlx);
	info_scene_file_name(global->scene, global->mlx);
    info_help(global->mlx);
}

void	show_interface_2(t_global *global)
{
    if (global->scene->active_light != NOTHING_SELECTED)
    {
        info_light_1(global->scene, global->mlx);
        info_light_2(global->scene, global->mlx);
        info_light_3(global->scene, global->mlx);
        info_light_4(global->scene, global->mlx);
    }
	if (global->scene->active_material != NOTHING_SELECTED)
	{
        info_material_1(global->scene, global->mlx);
        info_material_2(global->scene, global->mlx);
        info_material_3(global->scene, global->mlx);
    }
    if (global->scene->active_object != NOTHING_SELECTED)
	{
        info_object_1(global->scene, global->mlx);
        info_object_2(global->scene, global->mlx);
        info_object_3(global->scene, global->mlx);
        info_object_4(global->scene, global->mlx);
        info_material_1(global->scene, global->mlx);
        info_material_2(global->scene, global->mlx);
        info_material_3(global->scene, global->mlx);
    }
	if (global->scene->show_info == TRUE)
        show_scene_info(global);
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

void	show_scene_info(t_global *global)
{
	info_draw_box(global->mlx, INFO_BOX_W, INFO_BOX_H);
	info_scene_1(global->scene, global->mlx);
	info_scene_2(global->scene, global->mlx);
	info_scene_3(global->scene, global->mlx);
	info_scene_4(global->scene, global->mlx);
	info_scene_5(global->scene, global->mlx);
}
