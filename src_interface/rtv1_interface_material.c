/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_material.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:25:35 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 23:31:36 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	info_material(t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;

	x = WIN_SIZE_W - 350;
	y = 320;
	info_material_1(scene, mlx, x, y);
	info_material_2(scene, mlx, x, y);
	info_material_3(scene, mlx, x, y);
}

void	info_material_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;
	char	*str;

	x = WIN_SIZE_W - 350;
	y = 320;
	if (scene->active_material != NOTHING_SELECTED)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 80, y + 70, TEXT_COLOR,
	"MATERIAL CONTROL");
		i = scene->active_material;
	}
	else
		i = scene->objects.array[scene->active_object]->material;
	mlx_string_put(mlx->mlx, mlx->win, x, y + 100, TEXT_COLOR,
	"Material:         #");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 100, TEXT_COLOR,
	str = ft_itoa(i));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 210, y + 100, TEXT_COLOR,
	scene->materials.array[i]->name);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 130, TEXT_COLOR,
	"- color (RGB):");
}

void	info_material_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;
	char	*str;

	if (scene->active_material != NOTHING_SELECTED)
		i = scene->active_material;
	else
		i = scene->objects.array[scene->active_object]->material;
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 130, TEXT_COLOR,
	str = ft_itoa(scene->materials.array[i]->color.r));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 130, TEXT_COLOR,
	str = ft_itoa(scene->materials.array[i]->color.g));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 130, TEXT_COLOR,
	str = ft_itoa(scene->materials.array[i]->color.b));
	free(str);
}

void	info_material_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	int		i;
	char	*str;

	if (scene->active_material != NOTHING_SELECTED)
		i = scene->active_material;
	else
		i = scene->objects.array[scene->active_object]->material;
	info_material_color_sample(mlx,
	unite_color_channels(scene->materials.array[i]->color),
	WIN_SIZE_W - 200, 452);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 150, TEXT_COLOR,
	"- specular:");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 150, TEXT_COLOR,
	str = ft_itoa(scene->materials.array[i]->specular));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x, y + 170, TEXT_COLOR,
	"- reflective (x10):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 170, TEXT_COLOR,
	str = ft_itoa(10 * scene->materials.array[i]->reflective));
	free(str);
}

void	info_material_color_sample(t_mlx *mlx, int color, int x, int y)
{
	int		x_rect;
	int		y_rect;

	y_rect = -1;
	while (++y_rect < 18)
	{
		x_rect = -1;
		while (++x_rect < 18)
			mlx_pixel_put(mlx->mlx, mlx->win, x_rect + x, y_rect + y, color);
	}
}
