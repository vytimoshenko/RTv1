/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 11:05:18 by vitaly            #+#    #+#             */
/*   Updated: 2020/06/21 11:05:20 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	info_scene(t_scene *scene, t_mlx *mlx)
{
	int	x;
	int	y;

	x = (WIN_SIZE_W - INFO_BOX_W) / 2 + INFO_BOX_INDENTATION;
	y = (WIN_SIZE_H - INFO_BOX_H) / 2 + INFO_BOX_INDENTATION;
	info_scene_1(scene, mlx, x, y);
	info_scene_2(scene, mlx, x, y);
	info_scene_3(scene, mlx, x, y);
	info_scene_4(scene, mlx, x, y);
}

void	info_scene_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 120, y - 20, TEXT_COLOR,
	"SCENE SUMMARY");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 20, TEXT_COLOR,
	"Scene:");
	mlx_string_put(mlx->mlx, mlx->win, x + 80, y + 20, TEXT_COLOR,
	scene->name);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 40, TEXT_COLOR,
	"Author:");
	mlx_string_put(mlx->mlx, mlx->win, x + 80, y + 40, TEXT_COLOR,
	scene->author);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 80, TEXT_COLOR,
	"Cameras:");
	mlx_string_put(mlx->mlx, mlx->win, x + 150, y + 80, TEXT_COLOR,
	str = ft_itoa(scene->cameras.quantity));
	free(str);
}

void	info_scene_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x, y + 110, TEXT_COLOR,
	"Light sources:");
	mlx_string_put(mlx->mlx, mlx->win, x + 150, y + 110, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 130, TEXT_COLOR,
	"- ambient:");
	mlx_string_put(mlx->mlx, mlx->win, x + 150, y + 130, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity_ambient));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 150, TEXT_COLOR,
	"- directional:");
	mlx_string_put(mlx->mlx, mlx->win, x + 150, y + 150, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity_directional));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 170, TEXT_COLOR,
	"- point:");
	mlx_string_put(mlx->mlx, mlx->win, x + 150, y + 170, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity_point));
	free(str);
}

void	info_scene_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 220, y + 80, TEXT_COLOR,
	"Materials:");
	mlx_string_put(mlx->mlx, mlx->win, x + 350, y + 80, TEXT_COLOR,
	str = ft_itoa(scene->materials.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 220, y + 110, TEXT_COLOR,
	"Objects:");
	mlx_string_put(mlx->mlx, mlx->win, x + 350, y + 110, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 220, y + 130, TEXT_COLOR,
	"- planes:");
	mlx_string_put(mlx->mlx, mlx->win, x + 350, y + 130, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity_planes));
	free(str);
}

void	info_scene_4(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 220, y + 150, TEXT_COLOR,
	"- spheres:");
	mlx_string_put(mlx->mlx, mlx->win, x + 350, y + 150, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity_spheres));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 220, y + 170, TEXT_COLOR,
	"- cones:");
	mlx_string_put(mlx->mlx, mlx->win, x + 350, y + 170, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity_cones));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 220, y + 190, TEXT_COLOR,
	"- cylinders:");
	mlx_string_put(mlx->mlx, mlx->win, x + 350, y + 190, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity_cylinders));
	free(str);
}
