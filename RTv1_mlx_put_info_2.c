/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_put_info_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:27:57 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/18 00:16:00 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

// void	put_open_cl_info(t_open_cl *open_cl, t_mlx *mlx)
// {
// 	int		pos_x;
// 	int		pos_y;
// 	char	*str;

// 	pos_x = WIN_SIZE_W - 440;
// 	pos_y = 370;
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y, TEXT_COLOR,
// 	"DEVICE");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
// 	open_cl->device_name);
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
// 	"   cores x     MHz");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
// 	str = ft_itoa((int)(open_cl->device_comp_units)));
// 	free(str);
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x + 110, pos_y + 50, TEXT_COLOR,
// 	str = ft_itoa((int)(open_cl->device_frequency)));
// 	free(str);
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
// 	"OpenCL ver.:");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y + 80, TEXT_COLOR,
// 	open_cl->driver_ver);
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 110, TEXT_COLOR,
// 	"Execution time:       ms");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 110, TEXT_COLOR,
// 	str = ft_itoa(open_cl->execution_time));
// 	free(str);
// }

void	put_render_info_1(t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 440;
	pos_y = 580;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y, TEXT_COLOR,
	"RENDER");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Resolition:            x      pixels");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_W));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 250, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_H));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"Pixels total:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 50, TEXT_COLOR,
	str = ft_itoa(IMG_SIZE_W * IMG_SIZE_H));
	free(str);
}

void	put_render_info_2(t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 440;
	pos_y = 580;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"Frames:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(mlx->frames));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
	"Frame time:           ms");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 100, TEXT_COLOR,
	str = ft_itoa(mlx->frame_time));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 120, TEXT_COLOR,
	"FPS:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 120, TEXT_COLOR,
	str = ft_itoa(mlx->fps));
	free(str);
}

// void	put_control_keys_1(t_status *status, t_mlx *mlx)
// {
// 	int pos_x;
// 	int pos_y;

// 	pos_x = WIN_SIZE_W - 440;
// 	pos_y = 800;
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y, TEXT_COLOR,
// 	"CONTROL");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
// 	"Type:             return");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
// 	"Move:             arrows");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
// 	"                  middle mouse button");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 110, TEXT_COLOR,
// 	"Zoom:             +/-");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
// 	"                  mouse wheel scroll");
// 	if (status->fractal_type == JULIA)
// 		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 160, TEXT_COLOR,
// 		"Constant:         hold space and move mouse");
// 	else
// 		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 160, TEXT_COLOR,
// 		"Constant:         not available");
// }

// void	put_control_keys_2(t_mlx *mlx)
// {
// 	int pos_x;
// 	int pos_y;

// 	pos_x = WIN_SIZE_W - 440;
// 	pos_y = 800;
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 190, TEXT_COLOR,
// 	"Iterations:       </>");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 220, TEXT_COLOR,
// 	"Color:            C");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 250, TEXT_COLOR,
// 	"Hide info:        H");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 280, TEXT_COLOR,
// 	"Device:           D");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 310, TEXT_COLOR,
// 	"Reset:            R");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 340, TEXT_COLOR,
// 	"Exit:             ESC");
// }
