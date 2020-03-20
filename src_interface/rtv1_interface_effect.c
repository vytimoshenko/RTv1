/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_effect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 16:38:42 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"
#include "../rtv1_interface.h"

void	info_effect_1(t_scene *scene, t_mlx *mlx)
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
		"no");
	else if (scene->effect == EFFECT_GRAYSCALE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Grayscale");
	else if (scene->effect == EFFECT_NEGATIVE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Negative");
}

void	info_effect_2(t_scene *scene, t_mlx *mlx)
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

void	info_effect_3(t_scene *scene, t_mlx *mlx)
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
