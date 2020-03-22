/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_effect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/22 19:56:22 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	info_effect(t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;

	x = WIN_SIZE_W - 350;
	y = 450;
	info_effect_1(scene, mlx, x, y);
	info_effect_2(scene, mlx, x, y);
	info_effect_3(scene, mlx, x, y);
}

void	info_effect_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx, mlx->win, x + 125, y - 30, TEXT_COLOR, "EFFECT");
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR, "Effect:");
	if (scene->active_effect == EFFECT_GRAYSCALE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR, "Grayscale");
	else if (scene->active_effect == EFFECT_NEGATIVE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR, "Negative");
}

void	info_effect_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	if (scene->active_effect == EFFECT_CARTOON)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 150, y, TEXT_COLOR,
		str = ft_itoa(scene->k_cartoon));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 120, y, TEXT_COLOR,
		"x1/    Cartoon");
	}
	else if (scene->active_effect == EFFECT_PIXELATION)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 150, y, TEXT_COLOR,
		str = ft_itoa(scene->k_pixelation));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 140, y, TEXT_COLOR,
		"x    Pixelation");
	}
	else if (scene->active_effect == EFFECT_OUTLINE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR, "Outline");
}

void	info_effect_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	if (scene->active_effect == EFFECT_DEPTH)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 150, y, TEXT_COLOR,
		str = ft_itoa(scene->k_depth_map));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 120, y, TEXT_COLOR,
		"x1/    Depth");
	}
	else if (scene->active_effect == EFFECT_ANAGLYPH)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR, "Anaglyph");
}
