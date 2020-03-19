/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_object.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 21:08:29 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	object_info_1(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	if (scene->active_object != NOTHING_SELECTED)
	{
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
		else if (scene->objects.array[scene->active_object]->type ==
		OBJECT_TYPE_CONE)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y, TEXT_COLOR,
			"Cone");
		else if (scene->objects.array[scene->active_object]->type ==
		OBJECT_TYPE_CYLINDER)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y, TEXT_COLOR,
			"Cylinder");
	}
}

void	put_status_5(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	if (scene->active_object != NOTHING_SELECTED)
	{
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
}

void	put_status_6(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	int		i;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 320;
	i = scene->objects.array[scene->active_object]->material;
	if (scene->active_object != NOTHING_SELECTED)
	{
		if (scene->objects.array[scene->active_object]->type ==
		OBJECT_TYPE_SPHERE)
		{
			mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 70, TEXT_COLOR,
			"- radius:");
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 70, TEXT_COLOR,
			str = ft_itoa(scene->objects.array[scene->active_object]->radius));
			free(str);
		}
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
		"Material:         #");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 100, TEXT_COLOR,
		str = ft_itoa(i));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 100, TEXT_COLOR,
		scene->materials.array[i]->name);
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
		"- color (RGB):");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 130, TEXT_COLOR,
		str = ft_itoa(scene->materials.array[i]->color.r));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 130, TEXT_COLOR,
		str = ft_itoa(scene->materials.array[i]->color.g));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 130, TEXT_COLOR,
		str = ft_itoa(scene->materials.array[i]->color.b));
		free(str);
		put_material_color_sample(mlx, unite_color_channels(scene->materials.array[i]->color));
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 150, TEXT_COLOR,
		"- specular:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 150, TEXT_COLOR,
		str = ft_itoa(scene->materials.array[i]->specular));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 170, TEXT_COLOR,
		"- reflective (x10):");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 170, TEXT_COLOR,
		str = ft_itoa(10 * scene->materials.array[i]->reflective));
		free(str);
	}
}


void	draw_box(t_mlx *mlx, int size_w, int size_h)
{
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;

	pos_x = (WIN_SIZE_W - size_w) / 2;
	pos_y = (WIN_SIZE_H - size_h) / 2;
	y = -1;
	while (++y < size_h)
	{
		x = -1;
		while (++x < size_w)
			mlx_pixel_put(mlx->mlx, mlx->win, pos_x + x, pos_y + y, 0x50000000);
	}
}

void	put_material_color_sample(t_mlx *mlx, int color)
{
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;

	pos_x = WIN_SIZE_W - 200;
	pos_y = 452;
	y = -1;
	while (++y < 18)
	{
		x = -1;
		while (++x < 18)
			mlx_pixel_put(mlx->mlx, mlx->win, pos_x + x, pos_y + y, color);
	}
}

void	message_box(t_mlx *mlx, char *message_title, char *message_content)
{
	int		pos_x;
	int		pos_y;

	pos_x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2;
	pos_y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2;
	draw_box(mlx, MESSAGE_BOX_W, MESSAGE_BOX_H);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(message_title) / 2, pos_y + MESSAGE_BOX_INDENTATION, TEXT_COLOR,
	message_title);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(message_content) / 2, pos_y + MESSAGE_BOX_H / 2, TEXT_COLOR,
	message_content);
}
