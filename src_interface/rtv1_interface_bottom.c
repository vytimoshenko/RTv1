/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_bottom.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 03:37:02 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 16:33:49 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1_interface.h"

void	info_coordinates(t_scene *scene, t_mlx *mlx)
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

void	info_color(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = 230;
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
	info_color_sample(mlx, unite_color_channels(scene->picked_color));
}

void	info_color_sample(t_mlx *mlx, int color)
{
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;

	pos_x = 200;
	pos_y = WIN_SIZE_H - 27;
	y = -1;
	while (++y < 18)
	{
		x = -1;
		while (++x < 18)
			mlx_pixel_put(mlx->mlx, mlx->win, pos_x + x, pos_y + y, color);
	}
}

void	info_scene_file_name(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = 80;
	pos_y = WIN_SIZE_H - 30;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 370, pos_y, TEXT_COLOR,
	scene->file_name_with_path);
}

void	info_help(t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = WIN_SIZE_W - 300;
	pos_y = WIN_SIZE_H - 55;
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"<< PRESS H FOR HELP >>");
}
