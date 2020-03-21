/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_effect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 23:31:54 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	info_effect(t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;

	x = WIN_SIZE_W - 350;
	y = 50;
	info_effect_1(scene, mlx, x, y);
	info_effect_2(scene, mlx, x, y);
	info_effect_3(scene, mlx, x, y);
}

void	info_effect_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->mlx, mlx->win, x + 125, y - 30, TEXT_COLOR, "STATUS");
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR, "Effect:");
	if (scene->effect == NO_EFFECT)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR, "no");
	else if (scene->effect == EFFECT_GRAYSCALE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR, "Grayscale");
	else if (scene->effect == EFFECT_NEGATIVE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR, "Negative");
}

void	info_effect_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	if (scene->effect == EFFECT_CARTOON)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 150, y, TEXT_COLOR,
		str = ft_itoa(scene->k_cartoon));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 120, y, TEXT_COLOR,
		"x1/    Cartoon");
	}
	else if (scene->effect == EFFECT_PIXELATION)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 150, y, TEXT_COLOR,
		str = ft_itoa(scene->k_pixelation));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 140, y, TEXT_COLOR,
		"x    Pixelation");
	}
	else if (scene->effect == EFFECT_OUTLINE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR, "Outline");
}

void	info_effect_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	if (scene->effect == EFFECT_DEPTH)
	{
		mlx_string_put(mlx->mlx, mlx->win, x + 150, y, TEXT_COLOR,
		str = ft_itoa(scene->k_depth_map));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, x + 120, y, TEXT_COLOR,
		"x1/    Depth");
	}
	else if (scene->effect == EFFECT_ANAGLYPH)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR, "Anaglyph");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR, "Antialiasing:");
	if (scene->antialiasing == TRUE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR, "on");
	else if (scene->antialiasing == FALSE)
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR, "off");
}
