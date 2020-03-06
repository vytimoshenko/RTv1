/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_put_info_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:02:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/07 02:01:28 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	put_status_1(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
		char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 380;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 110, pos_y - 30, TEXT_COLOR,
	"STATUS");
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"Effect:");
	if (scene->effect == NO_EFFECT)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"-");
	// else if (scene->effect == EFFECT_PIXELATION)
	// 	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
	// 	"Pixelation");
	else if (scene->effect == EFFECT_CARTOON)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Cartoon");
	else if (scene->effect == EFFECT_GRAYSCALE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Grayscale");
	else if (scene->effect == EFFECT_NEGATIVE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Negative");
	else if (scene->effect == EFFECT_RED_CHANNEL)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Red channel");
	else if (scene->effect == EFFECT_GREEN_CHANNEL)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Green channel");
	else if (scene->effect == EFFECT_BLUE_CHANNEL)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Blue channel");
	else if (scene->effect == EFFECT_DEPTH_MAP)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Depth map");
	if (scene->effect == EFFECT_DEPTH_MAP)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 20, TEXT_COLOR,
		"Depth:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 250, pos_y + 20, TEXT_COLOR,
		str = ft_itoa(scene->depth_map_k));
		free(str);
	}
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 20, TEXT_COLOR,
	"Antialiasing:");
	if (scene->anti_aliasing == TRUE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 20, TEXT_COLOR,
		"yes");
	else if (scene->anti_aliasing == FALSE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 20, TEXT_COLOR,
		"no");
}

void	put_status_2(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 410;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Current camera:   #");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(scene->cameras.current + 1));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
	"- position (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->cameras.current]->position.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->cameras.current]->position.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->cameras.current]->position.z));
	free(str);
}

void	put_status_3(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 410;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"- rotation (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->cameras.current]->direction.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->cameras.current]->direction.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(scene->cameras.array[scene->cameras.current]->direction.z));
	free(str);
}

void	put_status_4(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 500;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Selected object:");
	if (scene->active_object == NO_OBJECT_SELECTED)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
		"-");
	else
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 30, TEXT_COLOR,
		"#");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
		str = ft_itoa(scene->active_object));
		free(str);
		if (scene->objects.array[scene->active_object]->type ==
		OBJECT_TYPE_PLANE)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 30,
			TEXT_COLOR, "Plane");
		else if (scene->objects.array[scene->active_object]->type ==
		OBJECT_TYPE_SPHERE)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 30,
			TEXT_COLOR, "Sphere");
		else if (scene->objects.array[scene->active_object]->type ==
		OBJECT_TYPE_CONE)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 30,
			TEXT_COLOR, "Cone");
		else if (scene->objects.array[scene->active_object]->type ==
		OBJECT_TYPE_CYLINDER)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 30,
			TEXT_COLOR, "Cylinder");
	}
}

void	put_status_4a(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 500;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Selected object:");
	if (scene->active_object == NO_OBJECT_SELECTED)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
		"-");
	else
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 180, pos_y + 30, TEXT_COLOR,
		"#");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
		str = ft_itoa(scene->lights.current));
		free(str);
		if (scene->lights.array[scene->lights.current]->type ==
		LIGHT_TYPE_AMBIENT)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 30,
			TEXT_COLOR, "Ambient");
		else if (scene->lights.array[scene->lights.current]->type ==
		LIGHT_TYPE_DIRECTIONAL)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 30,
			TEXT_COLOR, "Directional");
		else if (scene->lights.array[scene->lights.current]->type ==
		LIGHT_TYPE_POINT)
			mlx_string_put(mlx->mlx, mlx->win, pos_x + 210, pos_y + 30,
			TEXT_COLOR, "Point");
	}
}

void	put_status_5(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 500;
	if (scene->active_object != NO_OBJECT_SELECTED)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
		"- position (XYZ):");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 60, TEXT_COLOR,
		str = ft_itoa(scene->objects.array[scene->active_object]->center.x));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 60, TEXT_COLOR,
		str = ft_itoa(scene->objects.array[scene->active_object]->center.y));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 60, TEXT_COLOR,
		str = ft_itoa(scene->objects.array[scene->active_object]->center.z));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
		"- rotation (XYZ):");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 80, TEXT_COLOR,
		str = ft_itoa(scene->objects.array[scene->active_object]->direction.x));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 80, TEXT_COLOR,
		str = ft_itoa(scene->objects.array[scene->active_object]->direction.y));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 80, TEXT_COLOR,
		str = ft_itoa(scene->objects.array[scene->active_object]->direction.z));
		free(str);
	}
}

void	put_status_6(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 490;
	if (scene->active_object != NO_OBJECT_SELECTED)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 110, TEXT_COLOR,
		"- radius:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 110, TEXT_COLOR,
		str = ft_itoa(scene->objects.array[scene->active_object]->radius));
		free(str);
		// mlx_string_put(mlx->mlx, mlx->win, pos_x + 200, pos_y + 80, TEXT_COLOR,
		// str = ft_itoa(scene->cameras[scene->cameras.current]->direction.x));
		// free(str);
		// mlx_string_put(mlx->mlx, mlx->win, pos_x + 250, pos_y + 80, TEXT_COLOR,
		// str = ft_itoa(scene->cameras[scene->cameras.current]->direction.y));
		// free(str);
		// mlx_string_put(mlx->mlx, mlx->win, pos_x + 300, pos_y + 80, TEXT_COLOR,
		// str = ft_itoa(scene->cameras[scene->cameras.current]->direction.z));
		// free(str);
	}
}

void	put_status_7(t_scene *scene, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 490;
	if (scene->got_color == TRUE)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 130, TEXT_COLOR,
		"Color (RGB):");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 130, TEXT_COLOR,
		str = ft_itoa(scene->picked_color.r));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 130, TEXT_COLOR,
		str = ft_itoa(scene->picked_color.g));
		free(str);
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 130, TEXT_COLOR,
		str = ft_itoa(scene->picked_color.b));
		free(str);
		draw_color_sample(mlx, unite_color_channels(scene->picked_color));
	}
}

void	draw_color_sample(t_mlx *mlx, int color)
{
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 490;
	y = -1;
	while (++y < 18)
	{
		x = -1;
		while (++x < 18)
			mlx_pixel_put(mlx->mlx, mlx->win, pos_x + 150 + x, pos_y + 132 + y,
			color);
	}
}