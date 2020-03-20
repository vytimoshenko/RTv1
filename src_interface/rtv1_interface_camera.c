/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 16:38:35 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"
#include "../rtv1_interface.h"

void	info_camera_1(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 80;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Camera:           #");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(scene->active_camera + 1));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
	"- position (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->position.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->position.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->position.z));
	free(str);
}

void	info_camera_2(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 80;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"- rotation (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->direction.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->direction.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->direction.z));
	free(str);
}
