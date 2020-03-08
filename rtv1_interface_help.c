/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 00:31:45 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/09 01:59:50 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	info_control_1(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2 + MESSAGE_BOX_IDNT;
	pos_y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2 + MESSAGE_BOX_IDNT;
    mlx_string_put(mlx->mlx, mlx->win, pos_x + 400, pos_y, TEXT_COLOR,
	"RTv1 CONTROL");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 40, TEXT_COLOR,
	"Select:                     left mouse button");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
	"Unselect:                   ESC");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 90, TEXT_COLOR,
	"Move:                       arrows / PgUp / PgDown");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 110, TEXT_COLOR,
	"Rotate:                     W / A / S / D / < / >");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 140, TEXT_COLOR,
	"Change camera:              Home/End");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 170, TEXT_COLOR,
	"Light source control mode:  L");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 200, TEXT_COLOR,
	"Change light source:        Home/End");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 200, TEXT_COLOR,
	"Turn on/off light source:   O");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 200, TEXT_COLOR,
	"Light source intensity:     + / -");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 230, TEXT_COLOR,
	"Change effect:              E/ESC");
}

void	info_control_2(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2 + MESSAGE_BOX_IDNT;
	pos_y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2 + MESSAGE_BOX_IDNT;
	// mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 220, TEXT_COLOR,
	// "Apply material: middle mouse button");
	// mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 250, TEXT_COLOR,
	// "Material edit:  M");
    // mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 270, TEXT_COLOR,
	// "Antialiasing:   I");
	// mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 300, TEXT_COLOR,
	// "Pick color:     right mouse button");
	// mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 330, TEXT_COLOR,
	// "Reset:          R");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 360, TEXT_COLOR,
	"Exit:           Q");
}

void	info_control_3(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2 + MESSAGE_BOX_IDNT + 500;
	pos_y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2 + MESSAGE_BOX_IDNT;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 40, TEXT_COLOR,
	"Select:         left mouse button");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
	"Unselect:       ESC");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 90, TEXT_COLOR,
	"Move:           arrows/PgUp/PgDown");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 110, TEXT_COLOR,
	"Rotate:         W/A/S/D/</>");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 140, TEXT_COLOR,
	"Change camera:  space");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 160, TEXT_COLOR,
	"Change light:   L, Home/End");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 190, TEXT_COLOR,
	"Change effect:  E/ESC");
}

void	info_control_4(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2 + MESSAGE_BOX_IDNT + 500;
	pos_y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2 + MESSAGE_BOX_IDNT;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 330, TEXT_COLOR,
	"Reset:          R");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 360, TEXT_COLOR,
	"Exit:           Q");
}

void	info_author(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2 + MESSAGE_BOX_IDNT + 450;
	pos_y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2 + MESSAGE_BOX_IDNT + 440;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"Developed in 21 School by mperseus, Moscow, 2020");
}