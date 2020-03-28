/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_object.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/28 21:29:08 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	info_object(t_scene *scene, t_mlx *mlx)
{
	int		x;
	int		y;

	x = WIN_SIZE_W - 350;
	y = 250;
	info_object_1(scene, mlx, x, y);
	info_object_2(scene, mlx, x, y);
	info_object_3(scene, mlx, x, y);
}

void	info_object_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x + 80, y - 30, TEXT_COLOR,
	"OBJECT CONTROL");
	mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
	"Object:");
	mlx_string_put(mlx->mlx, mlx->win, x + 180, y, TEXT_COLOR,
	"#");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR,
	str = ft_itoa(scene->active_object));
	free(str);
	if (scene->objects.array[scene->active_object]->type ==
	OBJECT_TYPE_PLANE)
		mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR,
		"Plane");
	else if (scene->objects.array[scene->active_object]->type ==
	OBJECT_TYPE_SPHERE)
		mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR,
		"Sphere");
}

void	info_object_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	if (scene->objects.array[scene->active_object]->type ==
	OBJECT_TYPE_CONE)
		mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR,
		"Cone");
	else if (scene->objects.array[scene->active_object]->type ==
	OBJECT_TYPE_CYLINDER)
		mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR,
		"Cylinder");
	mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,
	"- position (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->position.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->position.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 30, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->position.z));
	free(str);
}

void	info_object_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

	mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
	"- rotation (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->orientation.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->orientation.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 50, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->orientation.z));
	free(str);
	if (scene->objects.array[scene->active_object]->type != OBJECT_TYPE_PLANE)
	{
		mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
		"- radius:");
		mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 70, TEXT_COLOR,
		str = ft_itoa(scene->objects.array[scene->active_object]->radius));
		free(str);
	}
}
