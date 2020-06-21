/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:28:22 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	trace_rays(t_scene *scene)
{
	int	i;

	clean_pixel_buffer(scene);
	prepare_pixels(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		trace_pixel(scene, scene->cams.arr[scene->act_cam]->
		pos, &scene->pixel_buffer[i], 1);
	fill_aliasing_buffer(scene);
}

void	prepare_pixels(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pixel_buffer[i].i = i;
		get_centered_coordinates(&scene->pixel_buffer[i]);
		get_pixel_viewport_coordinates(scene, &scene->pixel_buffer[i]);
	}
}

void	get_centered_coordinates(t_pix *pixel)
{
	pixel->x = pixel->i % (int)IMG_SIZE_W - 0.5 * (int)IMG_SIZE_W;
	pixel->y = 0.5 * (int)IMG_SIZE_H - pixel->i / (int)IMG_SIZE_W;
}

void	get_pixel_viewport_coordinates(t_scene *scene, t_pix *pixel)
{
	pixel->pos.x = pixel->x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	pixel->pos.y = pixel->y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	pixel->pos.z = VIEWPORT_DISTANCE;
	rotate_pixel(pixel, scene->cams.arr[scene->act_cam]);
}

void	rotate_pixel(t_pix *pixel, t_cam *camera)
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
