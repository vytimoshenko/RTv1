/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:05:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 14:48:52 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	show_scene_info(t_global *global)
{
	draw_box(global->mlx, INFO_BOX_W, INFO_BOX_H);
	put_scene_info_1(global->scene, global->mlx);
	put_scene_info_2(global->scene, global->mlx);
	put_scene_info_3(global->scene, global->mlx);
	put_scene_info_4(global->scene, global->mlx);
}

void	put_scene_info_1(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 20;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y, TEXT_COLOR,
	"SCENE SUMMARY");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Scene:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 80, pos_y + 30, TEXT_COLOR,
	scene->name);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"Author:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 80, pos_y + 50, TEXT_COLOR,
	scene->author);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"Cameras:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(scene->cameras.quantity));
	free(str);
}

void	put_scene_info_2(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 20;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 80, TEXT_COLOR,
	"Materials:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 320, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(scene->materials.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 110, TEXT_COLOR,
	"Light sources:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 110, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
	"- ambient:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 130, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity_ambient));
	free(str);
}

void	put_scene_info_3(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 20;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 150, TEXT_COLOR,
	"- directional:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 150, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity_directional));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 170, TEXT_COLOR,
	"- point:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 170, TEXT_COLOR,
	str = ft_itoa(scene->lights.quantity_point));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 110, TEXT_COLOR,
	"Objects:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 320, pos_y + 110, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity));
	free(str);
}

void	put_scene_info_4(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 20;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 130, TEXT_COLOR,
	"- planes:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 320, pos_y + 130, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity_planes));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 150, TEXT_COLOR,
	"- spheres:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 320, pos_y + 150, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity_spheres));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 170, TEXT_COLOR,
	"- cones:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 320, pos_y + 170, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity_cones));
	free(str);
}

void	put_scene_info_5(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 20;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 190, TEXT_COLOR,
	"- cylinders:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 320, pos_y + 190, TEXT_COLOR,
	str = ft_itoa(scene->objects.quantity_cylinders));
	free(str);
}
