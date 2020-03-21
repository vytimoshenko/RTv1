/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 00:31:45 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 23:31:13 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	info_header_and_author(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = (WIN_SIZE_W - HELP_BOX_W) / 2 + INFO_BOX_INDENTATION + 400;
	pos_y = (WIN_SIZE_H - HELP_BOX_H) / 2 + INFO_BOX_INDENTATION;
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"-= RTv1 =-");
    mlx_string_put(mlx->mlx, mlx->win, pos_x - 60, pos_y + 20, TEXT_COLOR,
	"basic raytracing render");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 50, pos_y + 440, TEXT_COLOR,
	"Developed by mperseus in 21 School, Moscow, 2020");
}

void	info_control_1(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = (WIN_SIZE_W - HELP_BOX_W) / 2 + INFO_BOX_INDENTATION;
	pos_y = (WIN_SIZE_H - HELP_BOX_H) / 2 + INFO_BOX_INDENTATION + 70;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"              GENERAL");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Select:              left mouse button");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"Unselect:            ESC");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"Move:                arrows/PgUp/PgDown");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
	"Rotate:              W/A/S/D/</>");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
	"Change camera:       Home/End");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 160, TEXT_COLOR,
	"Reset:               R");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 190, TEXT_COLOR,
	"Help:                H");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 220, TEXT_COLOR,
	"Exit:                Q");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 260, TEXT_COLOR,
	"          POST PROCESSING");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 290, TEXT_COLOR,
	"Antialiasing on/off: I");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 310, TEXT_COLOR,
	"Change effect:       E");
}

void	info_control_2(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = (WIN_SIZE_W - HELP_BOX_W) / 2 + INFO_BOX_INDENTATION;
	pos_y = (WIN_SIZE_H - HELP_BOX_H) / 2 + INFO_BOX_INDENTATION;
    (void)mlx;

}

void	info_control_3(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = (WIN_SIZE_W - HELP_BOX_W) / 2 + INFO_BOX_INDENTATION + 500;
	pos_y = (WIN_SIZE_H - HELP_BOX_H) / 2 + INFO_BOX_INDENTATION + 70;
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"                LIGHT");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Light source control mode:  L");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"Change light source:        Home/End");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 70, TEXT_COLOR,
	"Turn on/off light source:   O");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 90, TEXT_COLOR,
	"Light source intensity:     +/-");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
	"                MATERIALS");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 160, TEXT_COLOR,
	"Material control mode:      M");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 220, TEXT_COLOR,
	"Apply material:             middle mouse button");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 250, TEXT_COLOR,
	"Material edit:              M");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 300, TEXT_COLOR,
	"Pick color:     right mouse button");
}
