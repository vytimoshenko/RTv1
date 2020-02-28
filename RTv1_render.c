/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 04:16:32 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_image(t_scene *scene, t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	camera_direction;
	t_color		color;

	clean_object_buffer(scene);
	get_sin_cos(scene->cameras[scene->current_camera]);
	x = -IMG_SIZE_W / 2;
	while (++x < IMG_SIZE_W / 2)
	{
		y = -IMG_SIZE_H / 2;
		while (++y < IMG_SIZE_H / 2)
		{
			camera_direction = canvas_to_viewport(x, y);
			camera_direction = camera_totation(camera_direction,
			scene->cameras[scene->current_camera]);
			color = get_color(scene->spheres, scene->light_sources,
			scene->cameras[scene->current_camera]->position, camera_direction,
			REFLECTION_DEPTH, scene, x, y);
			put_pixel(mlx, x, y, final_processing(scene, x, y, color));
		}
	}
}

t_vector	canvas_to_viewport(int x, int y)
{
	t_vector viewport_pixel;

	viewport_pixel.x = x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	viewport_pixel.y = y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	viewport_pixel.z = VIEWPORT_DISTANCE;
	return (viewport_pixel);
}

void		get_sin_cos(t_camera *camera)
{
	camera->sin.x = sin(deg_to_rad(camera->direction.x));
	camera->sin.y = sin(deg_to_rad(camera->direction.y));
	camera->sin.z = sin(deg_to_rad(camera->direction.z));
	camera->cos.x = cos(deg_to_rad(camera->direction.x));
	camera->cos.y = cos(deg_to_rad(camera->direction.y));
	camera->cos.z = cos(deg_to_rad(camera->direction.z));
}

t_vector	camera_totation(t_vector vector, t_camera *camera)
{
	double temp1;
	double temp2;

	temp1 = vector.y * camera->cos.x + vector.z * camera->sin.x;
	temp2 = -vector.y * camera->sin.x + vector.z * camera->cos.x;
	vector.y = temp1;
	vector.z = temp2;
	temp1 = vector.x * camera->cos.y + vector.z * camera->sin.y;
	temp2 = -vector.x * camera->sin.y + vector.z * camera->cos.y;
	vector.x = temp1;
	vector.z = temp2;
	temp1 = vector.x * camera->cos.z - vector.y * camera->sin.z;
	temp2 = vector.x * camera->sin.z + vector.y * camera->cos.z;
	vector.x = temp1;
	vector.y = temp2;
	return (vector);
}

void		put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int i;

	x = IMG_SIZE_W / 2 + x;
	y = IMG_SIZE_H / 2 - y;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	mlx->data[i] = color;
}
