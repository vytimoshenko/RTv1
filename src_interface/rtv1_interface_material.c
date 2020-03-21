/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_material.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:25:35 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 19:39:07 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"
#include "../rtv1_interface.h"

void	info_material_1(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	int		i;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	i = scene->objects.array[scene->active_object]->material;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
	"Material:         #");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 100, TEXT_COLOR,
	str = ft_itoa(i));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 100, TEXT_COLOR,
	scene->materials.array[i]->name);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
	"- color (RGB):");
}

void	info_material_2(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	int		i;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	i = scene->objects.array[scene->active_object]->material;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 130, TEXT_COLOR,
	str = ft_itoa(scene->materials.array[i]->color.r));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 130, TEXT_COLOR,
	str = ft_itoa(scene->materials.array[i]->color.g));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 130, TEXT_COLOR,
	str = ft_itoa(scene->materials.array[i]->color.b));
	free(str);
}

void	info_material_3(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	int		i;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	i = scene->objects.array[scene->active_object]->material;
	info_material_color_sample(mlx,
	unite_color_channels(scene->materials.array[i]->color));
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 150, TEXT_COLOR,
	"- specular:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 150, TEXT_COLOR,
	str = ft_itoa(scene->materials.array[i]->specular));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 170, TEXT_COLOR,
	"- reflective (x10):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 170, TEXT_COLOR,
	str = ft_itoa(10 * scene->materials.array[i]->reflective));
	free(str);
}

void	info_material_color_sample(t_mlx *mlx, int color)
{
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;

	pos_x = WIN_SIZE_W - 200;
	pos_y = 452;
	y = -1;
	while (++y < 18)
	{
		x = -1;
		while (++x < 18)
			mlx_pixel_put(mlx->mlx, mlx->win, pos_x + x, pos_y + y, color);
	}
}
