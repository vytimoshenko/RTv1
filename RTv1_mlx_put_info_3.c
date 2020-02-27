/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_put_info_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 00:36:31 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	put_control_keys(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 700;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 110, pos_y, TEXT_COLOR,
	"CONTROL");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Select object:  left mouse button");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"Unselect:       ESC");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"Move object:    arrows/+/-");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
	"Rotate object:  W/A/S/D/</>");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
	"Change camera:  space");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 160, TEXT_COLOR,
	"Change effect:  E/ESC");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 190, TEXT_COLOR,
	"Reset:          R");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 230, TEXT_COLOR,
	"Exit:           Q");
}

void	put_render_info_1(t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 1080;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 110, pos_y, TEXT_COLOR,
	"RENDER");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Resolition:          x      pixels");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 160, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_W));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 230, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_H));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"Pixels:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 160, pos_y + 50, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_W * IMG_SIZE_H));
	free(str);
}

void	put_render_info_2(t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 1080;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"Frames:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 160, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(mlx->frames));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
	"Frame time:          ms");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 160, pos_y + 100, TEXT_COLOR,
	str = ft_itoa(mlx->frame_time));
	free(str);
}

void	put_bottom_line(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = 20;
	pos_y = WIN_SIZE_H - 30;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR, "X:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 20, pos_y, TEXT_COLOR,
	str = ft_itoa(status->x_mouse_position));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 80, pos_y, TEXT_COLOR, "Y:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y, TEXT_COLOR,
	str = ft_itoa(status->y_mouse_position));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 200, pos_y, TEXT_COLOR,
	"scene file opened:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 390, pos_y, TEXT_COLOR,
	status->file_name_with_path);
}
