/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 20:37:07 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	put_effect_1(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 50;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 125, pos_y - 30, TEXT_COLOR,
	"STATUS");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"Effect:");
	if (scene->effect == NO_EFFECT)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"-");
	else if (scene->effect == EFFECT_GRAYSCALE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Grayscale");
	else if (scene->effect == EFFECT_NEGATIVE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Negative");
}

void	put_effect_2(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 50;
	if (scene->effect == EFFECT_CARTOON)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y, TEXT_COLOR,
		str = ft_itoa(scene->k_cartoon));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 120, pos_y, TEXT_COLOR,
		"x1/    Cartoon");
	}
	else if (scene->effect == EFFECT_PIXELATION)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y, TEXT_COLOR,
		str = ft_itoa(scene->k_pixelation));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 140, pos_y, TEXT_COLOR,
		"x    Pixelation");
	}
}

void	put_effect_3(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 50;
	if (scene->effect == EFFECT_DEPTH)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y, TEXT_COLOR,
		str = ft_itoa(scene->k_depth_map));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 120, pos_y, TEXT_COLOR,
		"x1/    Depth");
	}
	else if (scene->effect == EFFECT_OUTLINE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Outline");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Antialiasing:");
	if (scene->antialiasing == TRUE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
		"on");
	else if (scene->antialiasing == FALSE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
		"off");
}

void	put_camera_1(t_scene *scene, t_mlx *mlx)
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

void	put_camera_2(t_scene *scene, t_mlx *mlx)
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
