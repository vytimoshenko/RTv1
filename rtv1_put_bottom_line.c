/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_put_bottom_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 03:37:02 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/09 00:21:58 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	put_coordinates(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = 20;
	pos_y = WIN_SIZE_H - 30;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR, "X:      Y:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 20, pos_y, TEXT_COLOR,
	str = ft_itoa(scene->x_mouse_position));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y, TEXT_COLOR,
	str = ft_itoa(scene->y_mouse_position));
	free(str);
}

void	put_color(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = 250;
	pos_y = WIN_SIZE_H - 30;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"R:     G:     B:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 20, pos_y, TEXT_COLOR,
	str = ft_itoa(scene->picked_color.r));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 90, pos_y, TEXT_COLOR,
	str = ft_itoa(scene->picked_color.g));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 160, pos_y, TEXT_COLOR,
	str = ft_itoa(scene->picked_color.b));
	free(str);
	put_color_sample(mlx, unite_color_channels(scene->picked_color));
}

void	put_color_sample(t_mlx *mlx, int color)
{
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;

	pos_x = 220;
	pos_y = WIN_SIZE_H - 27;
	y = -1;
	while (++y < 18)
	{
		x = -1;
		while (++x < 18)
			mlx_pixel_put(mlx->mlx, mlx->win, pos_x + x, pos_y + y, color);
	}
}

void	put_scene_file_name(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = 20;
	pos_y = WIN_SIZE_H - 30;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 480, pos_y, TEXT_COLOR,
	"scene file opened:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 670, pos_y, TEXT_COLOR,
	scene->file_name_with_path);
    // mlx_string_put(mlx->mlx, mlx->win, WIN_SIZE_W - 700, WIN_SIZE_H - 30,
	// TEXT_COLOR, "file saved:");
	// mlx_string_put(mlx->mlx, mlx->win, WIN_SIZE_W - 580, WIN_SIZE_H - 30,
	// TEXT_COLOR, file_name);
	// free(file_name);
}
