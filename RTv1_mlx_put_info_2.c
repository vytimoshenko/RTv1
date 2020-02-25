/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_put_info_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/25 20:54:22 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	put_render_info_1(t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 1080;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 90, pos_y, TEXT_COLOR,
	"RENDER");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Resolition:       x      pixels");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_W));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 200, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_H));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"Pixels:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 50, TEXT_COLOR,
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
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(mlx->frames));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
	"Frame time:       ms");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 100, TEXT_COLOR,
	str = ft_itoa(mlx->frame_time));
	free(str);
}

void	put_control_keys_1(t_status *status, t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 650;
	(void)status;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 90, pos_y, TEXT_COLOR,
	"CONTROL");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Move object:   return");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
	"Change camera: space");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"Rotate camera: arrows");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
	"               middle mouse button");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
	"Zoom:             +/-");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 160, TEXT_COLOR,
	"               mouse wheel scroll");
}

void	put_control_keys_2(t_mlx *mlx)
{
	int pos_x;
	int pos_y;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 650;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 190, TEXT_COLOR,
	"Iterations:       </>");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 220, TEXT_COLOR,
	"Color:            C");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 250, TEXT_COLOR,
	"Hide info:        H");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 310, TEXT_COLOR,
	"Reset:            R");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 340, TEXT_COLOR,
	"Exit:          ESC");
}
