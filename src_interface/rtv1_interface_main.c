/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 14:48:22 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 20:20:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	show_interface(t_global *global)
{
	put_effect_1(global->scene, global->mlx);
	put_effect_2(global->scene, global->mlx);
	put_effect_3(global->scene, global->mlx);
	put_camera_1(global->scene, global->mlx);
	put_camera_2(global->scene, global->mlx);
    
	object_info_1(global->scene, global->mlx);
	light_info(global->scene, global->mlx);
	material_info(global->scene, global->mlx);
	put_status_5(global->scene, global->mlx);
	put_status_5a(global->scene, global->mlx);
	put_status_6(global->scene, global->mlx);
	info_render_1(global->mlx);
	info_render_2(global->mlx);
	info_help(global->mlx);
	put_coordinates(global->scene, global->mlx);
	if (global->scene->got_color == TRUE)
		put_color(global->scene, global->mlx);
	put_scene_file_name(global->scene, global->mlx);
	if (global->scene->show_info == TRUE)
        show_scene_info(global);
    if (global->scene->show_help == TRUE)
		show_help(global);
}