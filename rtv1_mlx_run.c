/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:13:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/15 05:06:59 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	loop(t_global *global)
{
	mlx_hook(global->mlx->win, 2, 0, keyboard_key_press, global);
	mlx_hook(global->mlx->win, 4, 0, mouse_key_press, global);
	mlx_hook(global->mlx->win, 5, 0, mouse_key_release, global);
	mlx_hook(global->mlx->win, 6, 0, mouse_move, global);
	mlx_hook(global->mlx->win, 17, 0, close_window, global);
	mlx_loop(global->mlx->mlx);
}

void	draw(t_global *global)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	trace_rays(global->scene);
	final_processing(global->mlx, global->scene);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, IMG_INDT_W, IMG_INDT_H);
	gettimeofday(&end, NULL);
	count_frames(global->mlx, start, end);
	put_info_to_window(global);
	if (global->scene->in_motion_blur == TRUE) 
		keyboard_key_press(ARROW_LEFT, global);
}

void	update_info_only(t_global *global)
{
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, IMG_INDT_W, IMG_INDT_H);
	put_info_to_window(global);
}

void	put_info_to_window(t_global *global)
{
	put_scene_summary_1(global->scene, global->mlx);
	put_scene_summary_2(global->scene, global->mlx);
	put_scene_summary_3(global->scene, global->mlx);
	put_scene_summary_4(global->scene, global->mlx);
	put_status_1(global->scene, global->mlx);
	put_status_2(global->scene, global->mlx);
	put_status_3(global->scene, global->mlx);
	object_info_1(global->scene, global->mlx);
	light_info(global->scene, global->mlx);
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
	if (global->scene->show_help == TRUE)
		show_help(global);
}

void	count_frames(t_mlx *mlx, struct timeval start, struct timeval end)
{
	++mlx->frames;
	mlx->frame_time = (double)(end.tv_usec - start.tv_usec) / 1000 +
	(double)(end.tv_sec - start.tv_sec) * 1000;
}

void	show_help(t_global *global)
{
	draw_box(global->mlx, INFO_BOX_W, INFO_BOX_H);
	info_header_and_author(global->mlx);
	info_control_1(global->mlx);
	info_control_2(global->mlx);
	info_control_3(global->mlx);
	// info_control_4(global->mlx);
}

