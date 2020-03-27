/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/27 13:50:29 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	trace_rays(t_scene *scene)
{
	int	i;

	clean_pixel_buffer(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pixel_buffer[i].i = i;
		scene->pixel_buffer[i].object_id = EMPTY;
		get_centered_coordinates(&scene->pixel_buffer[i]);
		get_pixel_viewport_coordinates(scene, &scene->pixel_buffer[i]);
		trace_pixel(scene, scene->cameras.array[scene->active_camera]->
		position, &scene->pixel_buffer[i], REFLECTION_DEPTH);
	}
	fill_aliasing_buffer(scene);
}

void	get_centered_coordinates(t_pixel *pixel)
{
	pixel->x = pixel->i % (int)IMG_SIZE_W - 0.5 * (int)IMG_SIZE_W;
	pixel->y = 0.5 * (int)IMG_SIZE_H - pixel->i / (int)IMG_SIZE_W;
}

void	get_pixel_viewport_coordinates(t_scene *scene, t_pixel *pixel)
{
	pixel->pos.x = pixel->x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	pixel->pos.y = pixel->y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	pixel->pos.z = VIEWPORT_DISTANCE;
	rotate_pixel(pixel, scene->cameras.array[scene->active_camera]);
}

void	get_sin_cos(t_camera *camera)
{
	camera->sin.x = sin(deg_to_rad(camera->direction.x));
	camera->sin.y = sin(deg_to_rad(camera->direction.y));
	camera->sin.z = sin(deg_to_rad(camera->direction.z));
	camera->cos.x = cos(deg_to_rad(camera->direction.x));
	camera->cos.y = cos(deg_to_rad(camera->direction.y));
	camera->cos.z = cos(deg_to_rad(camera->direction.z));
}

void	rotate_pixel(t_pixel *pixel, t_camera *camera)
{
	double temp1;
	double temp2;

	temp1 = pixel->pos.y * camera->cos.x + pixel->pos.z * camera->sin.x;
	temp2 = -pixel->pos.y * camera->sin.x + pixel->pos.z * camera->cos.x;
	pixel->pos.y = temp1;
	pixel->pos.z = temp2;
	temp1 = pixel->pos.x * camera->cos.y + pixel->pos.z * camera->sin.y;
	temp2 = -pixel->pos.x * camera->sin.y + pixel->pos.z * camera->cos.y;
	pixel->pos.x = temp1;
	pixel->pos.z = temp2;
	temp1 = pixel->pos.x * camera->cos.z - pixel->pos.y * camera->sin.z;
	temp2 = pixel->pos.x * camera->sin.z + pixel->pos.y * camera->cos.z;
	pixel->pos.x = temp1;
	pixel->pos.y = temp2;
}
