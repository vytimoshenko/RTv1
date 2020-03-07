/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_put_info_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:05:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/07 02:17:04 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	put_scene_summary_1(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 40;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 90, pos_y, TEXT_COLOR,
	"SCENE SUMMARY");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Name:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 60, pos_y + 30, TEXT_COLOR,
	scene->scene_name);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
	"Cameras:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(scene->cameras.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 60, TEXT_COLOR,
	"Materials:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 310, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(scene->materials_quantity));
	free(str);
}

void	put_scene_summary_2(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 40;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 90, TEXT_COLOR,
	"Light sources:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 90, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 120, TEXT_COLOR,
	"- ambient:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 120, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity_ambient));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 140, TEXT_COLOR,
	"- directional:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 140, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity_directional));
	free(str);
}

void	put_scene_summary_3(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 40;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 160, TEXT_COLOR,
	"- point:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 160, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity_point));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 90, TEXT_COLOR,
	"Objects:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 310, pos_y + 90, TEXT_COLOR,
	str = ft_itoa(scene->total_objects_quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 120, TEXT_COLOR,
	"- planes:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 310, pos_y + 120, TEXT_COLOR,
	str = ft_itoa(scene->planes_quantity));
	free(str);
}

void	put_scene_summary_4(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 40;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 140, TEXT_COLOR,
	"- spheres:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 310, pos_y + 140, TEXT_COLOR,
	str = ft_itoa(scene->objects_quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 160, TEXT_COLOR,
	"- cones:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 310, pos_y + 160, TEXT_COLOR,
	str = ft_itoa(scene->cones_quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 180, TEXT_COLOR,
	"- cylinders:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 310, pos_y + 180, TEXT_COLOR,
	str = ft_itoa(scene->cylinders_quantity));
	free(str);
}
