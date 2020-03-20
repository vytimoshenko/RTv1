/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 19:14:35 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	trace_rays(t_scene *scene)
{
	t_pixel		pixel;

	clean_object_buffers(scene);
	clean_depth_buffers(scene);
	clean_aliasing_buffer(scene);
	clean_frame_buffer(scene);
	pixel.x = -IMG_SIZE_W / 2;
	while (++pixel.x <= IMG_SIZE_W / 2)
	{
		pixel.y = -IMG_SIZE_H / 2;
		while (++pixel.y <= IMG_SIZE_H / 2)
		{
			pixel.color = scene->background;
			get_pixel_position(scene, &pixel);
			get_pixel_color(scene, scene->cameras.array[scene->active_camera]->
			position, &pixel, REFLECTION_DEPTH);
			fill_frame_buffer(scene, pixel);
		}
	}
}

void	get_pixel_position(t_scene *scene, t_pixel *pixel)
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

void		fill_frame_buffer(t_scene *scene, t_pixel pixel)
{
	int i;

	pixel.x = IMG_SIZE_W / 2 + pixel.x;
	pixel.y = IMG_SIZE_H / 2 - pixel.y;
	i = (int)(IMG_SIZE_W * pixel.y + pixel.x);
	scene->frame_buffer[i] = pixel.color;
}

void		final_processing(t_mlx *mlx, t_scene *scene)
{
	int	i;

	fill_aliasing_buffer(scene);
	if (scene->antialiasing == TRUE)
		run_antialiasing(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i] = pixel_post_processing(scene, i,
		scene->frame_buffer[i]);
	if (scene->effect == EFFECT_PIXELATION)
		effect_pixelation(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->data[i] = unite_color_channels(scene->frame_buffer[i]);
}
