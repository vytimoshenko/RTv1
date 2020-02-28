/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_run.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:13:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 04:02:06 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	loop(t_global *global)
{
	mlx_hook(global->mlx->win, 2, 0, keyboard_key_press, global);
	mlx_hook(global->mlx->win, 4, 0, mouse_key_press, global);
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
	get_image(global->scene, global->mlx);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, IMG_INDT_W, IMG_INDT_H);
	gettimeofday(&end, NULL);
	count_frames(global->mlx, start, end);
	if (!(global->scene->hide_info))
		put_info_to_window(global);
}

void	update_info_only(t_global *global)
{
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, IMG_INDT_W, IMG_INDT_H);
	if (!(global->scene->hide_info))
		put_info_to_window(global);
}

void	put_info_to_window(t_global *global)
{
	put_scene_summary_1(global->scene, global->mlx);
	put_scene_summary_2(global->scene, global->mlx);
	put_scene_summary_3(global->scene, global->mlx);
	put_scene_summary_4(global->scene, global->mlx);
	put_scene_1(global->scene, global->mlx);
	put_scene_2(global->scene, global->mlx);
	put_scene_3(global->scene, global->mlx);
	put_scene_4(global->scene, global->mlx);
	put_scene_5(global->scene, global->mlx);
	put_scene_6(global->scene, global->mlx);
	put_control_keys(global->mlx);
	put_render_info_1(global->mlx);
	put_render_info_2(global->mlx);
	put_bottom_line(global->scene, global->mlx);
}

void	count_frames(t_mlx *mlx, struct timeval start, struct timeval end)
{
	++mlx->frames;
	mlx->frame_time = (double)(end.tv_usec - start.tv_usec) / 1000 +
	(double)(end.tv_sec - start.tv_sec) * 1000;
}
