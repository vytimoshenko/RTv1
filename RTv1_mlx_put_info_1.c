/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_put_info_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 03:05:11 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/27 03:18:32 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	put_scene_summary_1(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 70;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y, TEXT_COLOR,
	"SCENE SUMMARY");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Cameras:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(status->cameras_quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 140, TEXT_COLOR,
	"Light sources:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 140, TEXT_COLOR,
	str = ft_itoa(status->light_sources.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 170, TEXT_COLOR,
	"Objects total:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 170, TEXT_COLOR,
	str = ft_itoa(status->total_objects_quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 50, pos_y + 190, TEXT_COLOR,
	"- planes:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 190, TEXT_COLOR,
	str = ft_itoa(status->planes.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 40, pos_y + 210, TEXT_COLOR,
	"- spheres:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 210, TEXT_COLOR,
	str = ft_itoa(status->spheres.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 60, pos_y + 230, TEXT_COLOR,
	"- cones:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 230, TEXT_COLOR,
	str = ft_itoa(status->cones.quantity));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 20, pos_y + 250, TEXT_COLOR,
	"- cylinders:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 250, TEXT_COLOR,
	str = ft_itoa(status->cylinders.quantity));
	free(str);
}

void	put_status_1(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 400;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 130, pos_y, TEXT_COLOR,
	"STATUS");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 30, TEXT_COLOR,
	"Current: #");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 250, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(status->current_camera + 1));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 70, TEXT_COLOR,
	"position (x,y,z):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 200, pos_y + 70, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->position.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 250, pos_y + 70, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->position.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 300, pos_y + 70, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->position.z));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 20, pos_y + 90, TEXT_COLOR,
	"angles (x,y,z):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 200, pos_y + 90, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->direction.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 250, pos_y + 90, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->direction.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 300, pos_y + 90, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->direction.z));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 280, TEXT_COLOR,
	"Selected object:");
	if (status->active_object == NO_OBJECT_SELECTED)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 280, TEXT_COLOR,
		"no");
	else
	{		
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 280, TEXT_COLOR,
		str = ft_itoa(status->active_object));
		free(str);	
	}
	if (status->active_object != NO_OBJECT_SELECTED)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 300, TEXT_COLOR,
		"x:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 300, TEXT_COLOR,
		str = ft_itoa(status->spheres.array[status->active_object]->center.x));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 320, TEXT_COLOR,
		"y:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 320, TEXT_COLOR,
		str = ft_itoa(status->spheres.array[status->active_object]->center.y));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 150, pos_y + 340, TEXT_COLOR,
		"z:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 340, TEXT_COLOR,
		str = ft_itoa(status->spheres.array[status->active_object]->center.z));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 100, pos_y + 360, TEXT_COLOR,
		"radius:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 170, pos_y + 360, TEXT_COLOR,
		str = ft_itoa(status->spheres.array[status->active_object]->radius));
		free(str);
	}
}

