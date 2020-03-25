/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:13:43 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/25 19:22:07 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

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
	show_interface(global);
}

void	count_frames(t_mlx *mlx, struct timeval start, struct timeval end)
{
	++mlx->frames;
	mlx->frame_time = (double)(end.tv_usec - start.tv_usec) / 1000 +
	(double)(end.tv_sec - start.tv_sec) * 1000;
}

void	update_interface_only(t_global *global)
{
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, IMG_INDT_W, IMG_INDT_H);
	show_interface(global);
}

void	update_interface_and_frame(t_global *global)
{
	mlx_clear_window(global->mlx->mlx, global->mlx->win);
	final_processing(global->mlx, global->scene);
	mlx_put_image_to_window(global->mlx->mlx, global->mlx->win,
	global->mlx->img, IMG_INDT_W, IMG_INDT_H);
	show_interface(global);
}

void	put_error_pn(char *str)
{
	ft_putstr(PROGRAM_NAME);
	ft_putstr(": ");
	ft_putendl(str);
	exit(1);
}
