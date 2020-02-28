/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 22:58:54 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_image(t_scene *scene, t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	pixel;
	t_color		color;

	clean_object_buffer(scene);
	get_sin_cos(scene->cameras[scene->current_camera]);
	x = -IMG_SIZE_W / 2;
	while (++x < IMG_SIZE_W / 2)
	{
		y = -IMG_SIZE_H / 2;
		while (++y < IMG_SIZE_H / 2)
		{
			pixel = get_pixel(x, y);
			pixel = rotate_pixel(pixel, scene->cameras[scene->current_camera]);
			color = get_color(scene->spheres, scene->light_sources,
			scene->cameras[scene->current_camera]->position, pixel,
			REFLECTION_DEPTH, scene, x, y);

			// color = plane_intersection(scene->cameras[scene->current_camera]->position, pixel);
			put_pixel(mlx, x, y, final_processing(scene, x, y, color));
		}
	}
}

t_vector	get_pixel(int x, int y)
{
	t_vector pixel;

	pixel.x = x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	pixel.y = y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	pixel.z = VIEWPORT_DISTANCE;
	return (pixel);
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

t_vector	rotate_pixel(t_vector pixel, t_camera *camera)
{
	double temp1;
	double temp2;

	temp1 = pixel.y * camera->cos.x + pixel.z * camera->sin.x;
	temp2 = -pixel.y * camera->sin.x + pixel.z * camera->cos.x;
	pixel.y = temp1;
	pixel.z = temp2;
	temp1 = pixel.x * camera->cos.y + pixel.z * camera->sin.y;
	temp2 = -pixel.x * camera->sin.y + pixel.z * camera->cos.y;
	pixel.x = temp1;
	pixel.z = temp2;
	temp1 = pixel.x * camera->cos.z - pixel.y * camera->sin.z;
	temp2 = pixel.x * camera->sin.z + pixel.y * camera->cos.z;
	pixel.x = temp1;
	pixel.y = temp2;
	return (pixel);
}

void		put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int i;

	x = IMG_SIZE_W / 2 + x;
	y = IMG_SIZE_H / 2 - y;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	mlx->data[i] = color;
}
