/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/04 02:48:43 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trace_rays(t_scene *scene)
{
	t_pixel	pixel;

	clean_object_buffer(scene);
	pixel.x = -IMG_SIZE_W / 2;
	while (++pixel.x < IMG_SIZE_W / 2)
	{
		pixel.y = -IMG_SIZE_H / 2;
		while (++pixel.y < IMG_SIZE_H / 2)
		{
			get_pixel_position(scene, &pixel);
			pixel.color = get_pixel_color(scene,
			scene->cameras[scene->current_camera]->position, &pixel, REFLECTION_DEPTH);
			put_pixel_into_buffer(scene, pixel);
		}
	}
}

void	get_pixel_position(t_scene *scene, t_pixel *pixel)
{
	pixel->position.x = pixel->x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	pixel->position.y = pixel->y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	pixel->position.z = scene->cameras[scene->current_camera]->zoom;
	rotate_pixel(pixel, scene->cameras[scene->current_camera]);
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

	temp1 = pixel->position.y * camera->cos.x + pixel->position.z * camera->sin.x;
	temp2 = -pixel->position.y * camera->sin.x + pixel->position.z * camera->cos.x;
	pixel->position.y = temp1;
	pixel->position.z = temp2;
	temp1 = pixel->position.x * camera->cos.y + pixel->position.z * camera->sin.y;
	temp2 = -pixel->position.x * camera->sin.y + pixel->position.z * camera->cos.y;
	pixel->position.x = temp1;
	pixel->position.z = temp2;
	temp1 = pixel->position.x * camera->cos.z - pixel->position.y * camera->sin.z;
	temp2 = pixel->position.x * camera->sin.z + pixel->position.y * camera->cos.z;
	pixel->position.x = temp1;
	pixel->position.y = temp2;
}

void		put_pixel_into_buffer(t_scene *scene, t_pixel pixel)
{
	int i;

	pixel.x = IMG_SIZE_W / 2 + pixel.x;
	pixel.y = IMG_SIZE_H / 2 - pixel.y;
	i = (int)(IMG_SIZE_W * (pixel.y - 1) + pixel.x);
	scene->frame_buffer[i] = pixel.color;
}

void		final_processing(t_mlx *mlx, t_scene *scene)
{
	int		i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i] = pixel_post_processing(scene, i,
		scene->frame_buffer[i]);
	if (scene->in_motion_blur == TRUE && scene->buffer_id != MOTION_BLUR_BUFFERS - 1)
	{
		i = -1;
		while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->motion_blur_frame_buffers[scene->buffer_id][i] = scene->frame_buffer[i];
		++scene->buffer_id;
	}
	if (scene->in_motion_blur == TRUE && scene->buffer_id == MOTION_BLUR_BUFFERS - 1)
	{
		motion_blur(scene->frame_buffer, scene->motion_blur_frame_buffers);
		i = -1;
		while (++i < IMG_SIZE_W * IMG_SIZE_H)
		{
			if (scene->object_buffer[i] == scene->active_object)
			{
				scene->frame_buffer[i].r = scene->motion_blur_frame_buffers[MOTION_BLUR_BUFFERS - 2][i].r;
				scene->frame_buffer[i].g = scene->motion_blur_frame_buffers[MOTION_BLUR_BUFFERS - 2][i].g;
				scene->frame_buffer[i].b = scene->motion_blur_frame_buffers[MOTION_BLUR_BUFFERS - 2][i].b;
			}
		}
		scene->in_motion_blur = FALSE;
		scene->buffer_id = 0;
	}
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->data[i] = unite_color_channels(scene->frame_buffer[i]);
}

// void	motion_blur(t_scene *scene)
// {
// 	t_color color;
// 	int n;

// 	while (n < MOTION_BLUR_BUFFERS)
// 	{
// 		scene->motion_blur_frame_buffers;
// 	}
// }

// 	void	effect_pixelation(t_scene *scene)
// {
// 	int	i;
// 	int tmp;
// 	int	k;

// 	t_color *frame_buffer = scene->frame_buffer;

// 	k = 8;
// 	i = -1;
// 	int sum_r;
// 	int sum_g;
// 	int sum_b;
// 	int n;
// 	sum_r = sum_g = sum_b = 0;
// 	while (++i < IMG_SIZE_W * (IMG_SIZE_H - k)
// 	{
// 		n = 0;
// 		sum_r = sum_g = sum_b = 0;
// 		while ()
// 		{
// 			sum_r += frame_buffer[i].r;
// 			sum_r += frame_buffer[i + 1].r;
// 			sum_r += frame_buffer[i + (int)IMG_SIZE_W].r;
// 			sum_r += frame_buffer[i + 1 + (int)IMG_SIZE_W].r;
// 			sum_g += frame_buffer[i].g;
// 			sum_g += frame_buffer[i + 1].g;
// 			sum_g += frame_buffer[i + (int)IMG_SIZE_W].g;
// 			sum_g += frame_buffer[i + 1 + (int)IMG_SIZE_W].g;
// 			sum_b += frame_buffer[i].b;
// 			sum_b += frame_buffer[i + 1].b;
// 			sum_b += frame_buffer[i + (int)IMG_SIZE_W].b;
// 			sum_b += frame_buffer[i + 1 + (int)IMG_SIZE_W].b;
// 		}
			
// 	}
// }



// void	effect_pixelation(t_scene *scene)
// {
// 	int	i;
// 	int tmp;
// 	int	k;
// 	t_color *frame_buffer = scene->frame_buffer;

// 	i = 0;
// 	k = 0;
// 	while (i < IMG_SIZE_W * IMG_SIZE_H)
// 	{
// 		k = 0;
// 		tmp = scene->frame_buffer[i];
// 		while (k < 8)
// 		{
// 			scene->frame_buffer[i + k] = tmp;
// 			k++;
// 		}
// 		i += 8;
// 	}
// }