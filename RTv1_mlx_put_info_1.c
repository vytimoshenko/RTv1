/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_put_info_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:05:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/24 02:04:08 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	put_status_1(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 440;
	pos_y = 70;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y, TEXT_COLOR,
	"STATUS");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Cameras total:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(status->cameras.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"Current camera: #");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 50, TEXT_COLOR,
	str = ft_itoa(status->current_camera + 1));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 70, TEXT_COLOR,
	"x:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 70, TEXT_COLOR,
	str = ft_itoa(status->cameras.array[status->current_camera]->x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 90, TEXT_COLOR,
	"y:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 90, TEXT_COLOR,
	str = ft_itoa(status->cameras.array[status->current_camera]->y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 110, TEXT_COLOR,
	"z:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 110, TEXT_COLOR,
	str = ft_itoa(status->cameras.array[status->current_camera]->z));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 140, TEXT_COLOR,
	"Light sources:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 140, TEXT_COLOR,
	str = ft_itoa(status->light_sources.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 170, TEXT_COLOR,
	"Spheres total:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 170, TEXT_COLOR,
	str = ft_itoa(status->spheres.quantity));
	free(str);
}

// void	put_status_3(t_status *status, t_mlx *mlx)
// {
// 	int		pos_x;
// 	int		pos_y;
// 	char	*str;

// 	pos_x = WIN_SIZE_W - 440;
// 	pos_y = 70;
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 140, TEXT_COLOR,
// 	"Iterations:");
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 140, TEXT_COLOR,
// 	str = ft_itoa(status->iter));
// 	free(str);
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 170, TEXT_COLOR,
// 	"Color:");
// 	if (status->color_theme == 0)
// 		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 170, TEXT_COLOR,
// 		"Theme #1");
// 	else if (status->color_theme == 1)
// 		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 170, TEXT_COLOR,
// 		"Theme #2");
// 	else if (status->color_theme == 2)
// 		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 170, TEXT_COLOR,
// 		"Theme #3");
// 	else if (status->color_theme == 3)
// 		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 170, TEXT_COLOR,
// 		"Theme #4");
// }

// void	put_status_4(t_status *status, t_mlx *mlx)
// {
// 	int		pos_x;
// 	int		pos_y;

// 	pos_x = WIN_SIZE_W - 440;
// 	pos_y = 70;
// 	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 200, TEXT_COLOR,
// 	"Device:");
// 	if (status->device == 0)
// 		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 200, TEXT_COLOR,
// 		"CPU");
// 	if (status->device == 1)
// 		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 200, TEXT_COLOR,
// 		"GPU");
// }

void	put_status_5(t_status *status, t_mlx *mlx)
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
}
