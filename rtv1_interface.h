/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 21:59:29 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_INTERFACE_H

# define RTV1_INTERFACE_H

# include "rtv1.h"

// # define WIN_SIZE_W						1916
// # define WIN_SIZE_H						1064
// # define IMG_SIZE_W						1536.0
// # define IMG_SIZE_H						1024.0
# define WIN_SIZE_W						1340
# define WIN_SIZE_H						808
# define IMG_SIZE_W						960.0
# define IMG_SIZE_H						768.0
# define IMG_INDT_W						10
# define IMG_INDT_H						10

# define TEXT_COLOR 					0xFFFFFF

# define HELP_BOX_W						1000
# define HELP_BOX_H						500

# define INFO_BOX_W						420
# define INFO_BOX_H						280

# define INFO_BOX_INDENTATION			30

# define MESSAGE_BOX_W					700
# define MESSAGE_BOX_H					80
# define MESSAGE_BOX_INDENTATION		10

void		show_interface_1(t_global *global);
void		show_interface_2(t_global *global);
void		show_scene_info(t_global *global);
void		show_help(t_mlx *mlx);

void		info_effect_1(t_scene *scene, t_mlx *mlx);
void		info_effect_2(t_scene *scene, t_mlx *mlx);
void		info_effect_3(t_scene *scene, t_mlx *mlx);
void		info_effect_4(t_scene *scene, t_mlx *mlx);

void		info_camera_1(t_scene *scene, t_mlx *mlx);
void		info_camera_2(t_scene *scene, t_mlx *mlx);

void		info_render_1(t_mlx *mlx);
void		info_render_2(t_mlx *mlx);

void		info_coordinates(t_scene *scene, t_mlx *mlx);
void		info_color(t_scene *scene, t_mlx *mlx);
void		info_color_sample(t_mlx *mlx, int color);
void		info_scene_file_name(t_scene *scene, t_mlx *mlx);
void		info_help(t_mlx *mlx);

void		info_light_1(t_scene *scene, t_mlx *mlx);
void		info_light_2(t_scene *scene, t_mlx *mlx);
void		info_light_3(t_scene *scene, t_mlx *mlx);
void		info_light_4(t_scene *scene, t_mlx *mlx);

void		info_object_1(t_scene *scene, t_mlx *mlx);
void		info_object_2(t_scene *scene, t_mlx *mlx);
void		info_object_3(t_scene *scene, t_mlx *mlx);
void		info_object_4(t_scene *scene, t_mlx *mlx);

void		info_material_1(t_scene *scene, t_mlx *mlx);
void		info_material_2(t_scene *scene, t_mlx *mlx);
void		info_material_3(t_scene *scene, t_mlx *mlx);
void		info_material_color_sample(t_mlx *mlx, int color);

void		info_scene_1(t_scene *scene, t_mlx *mlx);
void		info_scene_2(t_scene *scene, t_mlx *mlx);
void		info_scene_3(t_scene *scene, t_mlx *mlx);
void		info_scene_4(t_scene *scene, t_mlx *mlx);
void		info_scene_5(t_scene *scene, t_mlx *mlx);

void		info_header_and_author(t_mlx *mlx);
void		info_author(t_mlx *mlx);
void		info_control_1(t_mlx *mlx);
void		info_control_2(t_mlx *mlx);
void		info_control_3(t_mlx *mlx);

void		info_draw_box(t_mlx *mlx, int size_w, int size_h);
void		info_message_box(t_mlx *mlx, char *message_title,
			char *message_content);

#endif
