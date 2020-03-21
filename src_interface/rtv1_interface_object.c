/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_object.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 19:38:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"
#include "../rtv1_interface.h"

void	info_object_1(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 80, pos_y - 30, TEXT_COLOR,
	"OBJECT CONTROL");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"Object:");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y, TEXT_COLOR,
	"#");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
	str = ft_itoa(scene->active_object));
	free(str);
	if (scene->objects.array[scene->active_object]->type ==
	OBJECT_TYPE_PLANE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y, TEXT_COLOR,
		"Plane");
	else if (scene->objects.array[scene->active_object]->type ==
	OBJECT_TYPE_SPHERE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y, TEXT_COLOR,
		"Sphere");
}

void	info_object_2(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	if (scene->objects.array[scene->active_object]->type ==
	OBJECT_TYPE_CONE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y, TEXT_COLOR,
		"Cone");
	else if (scene->objects.array[scene->active_object]->type ==
	OBJECT_TYPE_CYLINDER)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y, TEXT_COLOR,
		"Cylinder");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"- position (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->position.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->position.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->position.z));
	free(str);
}

void	info_object_3(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 50, TEXT_COLOR,
	"- rotation (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 50, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->orientation.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 50, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->orientation.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 50, TEXT_COLOR,
	str = ft_itoa(scene->objects.array[scene->active_object]->orientation.z));
	free(str);
}

void	info_object_4(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	if (scene->objects.array[scene->active_object]->type != OBJECT_TYPE_PLANE)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 70, TEXT_COLOR,
		"- radius:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 70, TEXT_COLOR,
		str = ft_itoa(scene->objects.array[scene->active_object]->radius));
		free(str);
	}
}
