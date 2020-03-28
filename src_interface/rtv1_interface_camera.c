/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/28 21:28:23 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	info_camera(t_scene *scene, t_mlx *mlx)
{
	int	x;
	int	y;

	x = WIN_SIZE_W - 350;
	y = 30;
	info_camera_1(scene, mlx, x, y);
	info_camera_2(scene, mlx, x, y);
}

void	info_camera_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 110, y, TEXT_COLOR, "CAMERA #");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR,
	str = ft_itoa(scene->active_camera + 1));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"- position (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->position.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->position.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->position.z));
	free(str);
}

void	info_camera_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"- rotation (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->direction.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->direction.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->active_camera]->direction.z));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 90, TEXT_COLOR, "Antialiasing:");
	if (scene->antialiasing == TRUE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 90, TEXT_COLOR, "on");
	else if (scene->antialiasing == FALSE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 90, TEXT_COLOR, "off");
}
