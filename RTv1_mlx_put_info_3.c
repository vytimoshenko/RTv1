/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_put_info_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/08 06:54:09 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	put_control_keys_1(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 710;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 115, pos_y, TEXT_COLOR,
	"CONTROL");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Select:         left mouse button");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"Unselect:       ESC");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"Move:           arrows/PgUp/PgDown");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
	"Rotate:         W/A/S/D/</>");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
	"Change camera:  space");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 150, TEXT_COLOR,
	"Change light:   L, Home/End");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 180, TEXT_COLOR,
	"Change effect:  E/ESC");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 210, TEXT_COLOR,
	"Apply material: middle mouse button");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 240, TEXT_COLOR,
	"Material edit:  M");
}

void	put_control_keys_2(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 710;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 270, TEXT_COLOR,
	"Antialiasing:   I");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 300, TEXT_COLOR,
	"Pick color:     right mouse button");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 330, TEXT_COLOR,
	"Reset:          R");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 360, TEXT_COLOR,
	"Exit:           Q");
}

void	put_render_info_1(t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 1100;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 115, pos_y, TEXT_COLOR,
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
	pos_y = 1100;
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

