/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_material.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:25:35 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/15 07:42:57 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	material_info(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;
    int     i;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 520;
	if (scene->active_material != NOTHING_SELECTED)
	{
        i = scene->active_material;
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
		"Material:         #");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 100, TEXT_COLOR,
		str = ft_itoa(i));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 100, TEXT_COLOR,
		scene->materials.array[i]->name);
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 120, TEXT_COLOR,
		"- color (RGB):");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 120, TEXT_COLOR,
		str = ft_itoa(scene->materials.array[i]->color.r));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 120, TEXT_COLOR,
		str = ft_itoa(scene->materials.array[i]->color.g));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 120, TEXT_COLOR,
		str = ft_itoa(scene->materials.array[i]->color.b));
		free(str);
		put_material_color_sample(mlx, unite_color_channels(scene->materials.array[i]->color));
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 140, TEXT_COLOR,
		"- specular:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 140, TEXT_COLOR,
		str = ft_itoa(scene->materials.array[i]->specular));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 160, TEXT_COLOR,
		"- reflective(x10):");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 160, TEXT_COLOR,
		str = ft_itoa(10 * scene->materials.array[i]->reflective));
		free(str);
	}
}
