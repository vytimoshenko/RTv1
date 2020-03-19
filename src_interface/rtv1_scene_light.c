/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_scene_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:40:47 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 20:54:48 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	light_info(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 300;
	if (scene->active_light != NOTHING_SELECTED)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 90, pos_y - 30, TEXT_COLOR,
		"LIGHT CONTROL");
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
		"Light source:     #");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		str = ft_itoa(scene->active_light));
		free(str);
		if (scene->lights.array[scene->active_light]->type ==
		LIGHT_TYPE_AMBIENT)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y, TEXT_COLOR,
			"Ambient");
		else if (scene->lights.array[scene->active_light]->type ==
		LIGHT_TYPE_DIRECTIONAL)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y, TEXT_COLOR,
			"Directional");
		else if (scene->lights.array[scene->active_light]->type ==
		LIGHT_TYPE_POINT)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y, TEXT_COLOR,
			"Point");
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
		"- switch:");
		if (scene->lights.array[scene->active_light]->off == FALSE)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
			"on");
		if (scene->lights.array[scene->active_light]->off == TRUE)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
			"off");
	}
}

void	put_status_5a(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 300;
	if (scene->active_light != NOTHING_SELECTED)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
		"- intensity (x10):");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 50, TEXT_COLOR,
		str = ft_itoa(10 * scene->lights.array[scene->active_light]->intensity));
		free(str);
		if (scene->lights.array[scene->active_light]->type ==
		LIGHT_TYPE_POINT)
		{
			mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 70, TEXT_COLOR,
			"- position (XYZ):");
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 70, TEXT_COLOR,
			str = ft_itoa(scene->lights.array[scene->active_light]->position.x));
			free(str);
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 70, TEXT_COLOR,
			str = ft_itoa(scene->lights.array[scene->active_light]->position.y));
			free(str);
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 70, TEXT_COLOR,
			str = ft_itoa(scene->lights.array[scene->active_light]->position.z));
			free(str);
		}
		if (scene->lights.array[scene->active_light]->type ==
		LIGHT_TYPE_DIRECTIONAL)
		{
			mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 70, TEXT_COLOR,
			"- direction (XYZ):");
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 70, TEXT_COLOR,
			str = ft_itoa(scene->lights.array[scene->active_light]->direction.x));
			free(str);
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 70, TEXT_COLOR,
			str = ft_itoa(scene->lights.array[scene->active_light]->direction.y));
			free(str);
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 70, TEXT_COLOR,
			str = ft_itoa(scene->lights.array[scene->active_light]->direction.z));
			free(str);
		}
	}
}
