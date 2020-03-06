/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/07 02:02:52 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trace_rays(t_scene *scene)
{
	t_pixel		pixel;
	double		jitter[MULTI_SAMPLING_RATE];
	int i;
	
	clean_object_buffer(scene);
	clean_depth_buffer(scene);
	clean_aliasing_buffer(scene);
	clean_frame_buffer(scene);
	get_jitter(jitter);
	pixel.x = -IMG_SIZE_W / 2;
	while (++pixel.x <= IMG_SIZE_W / 2)
	{
		pixel.y = -IMG_SIZE_H / 2;
		while (++pixel.y <= IMG_SIZE_H / 2)
		{
			// if (scene->anti_aliasing == TRUE)
			// 	anti_aliasing(scene, &pixel, jitter);
			// else
			// {
				pixel.color = scene->background;
				get_pixel_position(scene, &pixel);
				get_pixel_color(scene, scene->cameras.array[scene->cameras.current]->
				position, &pixel, REFLECTION_DEPTH);
			// }
			fill_frame_buffer(scene, pixel);
		}
	}
	fill_aliasing_buffer(scene);
	if (scene->anti_aliasing == TRUE)
	{
		pixel.x = -IMG_SIZE_W / 2;
		while (++pixel.x <= IMG_SIZE_W / 2)
		{
			pixel.y = -IMG_SIZE_H / 2;
			while (++pixel.y <= IMG_SIZE_H / 2)
			{
				i = (int)(IMG_SIZE_W * (IMG_SIZE_H / 2 - pixel.y - 1) + IMG_SIZE_W / 2 + pixel.x);
				if (scene->aliasing_buffer[i])
				{
					anti_aliasing(scene, &pixel, jitter);
					fill_frame_buffer(scene, pixel);
					// ft_putstr("GGG");
				}
			}
		}
	}
}

// void	run_anti_aliasing(t_scene *scene)
// {
// 	int	i;
// 	double		jitter[MULTI_SAMPLING_RATE];

// 	i = -1;
// 	get_jitter(jitter);
// 	while (++i < IMG_SIZE_W * IMG_SIZE_H)
// 	{
// 		if (scene->aliasing_buffer[i])
// 			anti_aliasing(scene, frame_buffer, jitter);
// 	}
// }



void	get_pixel_position(t_scene *scene, t_pixel *pixel)
{
	pixel->position.x = pixel->x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	pixel->position.y = pixel->y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	pixel->position.z = VIEWPORT_DISTANCE;
	rotate_pixel(pixel, scene->cameras.array[scene->cameras.current]);
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

void		fill_frame_buffer(t_scene *scene, t_pixel pixel)
{
	int i;

	pixel.x = IMG_SIZE_W / 2 + pixel.x - 1;
	pixel.y = IMG_SIZE_H / 2 - pixel.y;
	i = (int)(IMG_SIZE_W * pixel.y + pixel.x);
	// if (i == 1535 * 1023)
	// 	ft_putstr("HHH");
	// if (i == 1)
	// ft_putnbr((int)(IMG_SIZE_W / 2 + IMG_SIZE_W / 2));
	scene->frame_buffer[i] = pixel.color;
}

void		final_processing(t_mlx *mlx, t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i] = pixel_post_processing(scene, i,
		scene->frame_buffer[i]);
	if (scene->in_motion_blur == TRUE && scene->buffer_id != MOTION_BLUR_BUFFERS - 1)
	{
		i = -1;
		while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->motion_blur_buffers[scene->buffer_id][i] = scene->frame_buffer[i];
		++scene->buffer_id;
	}
	if (scene->in_motion_blur == TRUE && scene->buffer_id == MOTION_BLUR_BUFFERS - 1)
	{
		motion_blur(scene->frame_buffer, scene->motion_blur_buffers);
		i = -1;
		while (++i < IMG_SIZE_W * IMG_SIZE_H)
		{
			if (scene->object_buffer[i] == scene->active_object)
			{
				scene->frame_buffer[i].r = scene->motion_blur_buffers[MOTION_BLUR_BUFFERS - 2][i].r;
				scene->frame_buffer[i].g = scene->motion_blur_buffers[MOTION_BLUR_BUFFERS - 2][i].g;
				scene->frame_buffer[i].b = scene->motion_blur_buffers[MOTION_BLUR_BUFFERS - 2][i].b;
			}
		}
		scene->in_motion_blur = FALSE;
		scene->buffer_id = 0;
	}
	// if (scene->effect == EFFECT_PIXELATION)
	// 	effect_pixelation(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->data[i] = unite_color_channels(scene->frame_buffer[i]);
}

void	get_macro_pixel(t_scene *scene, int pitch)
{
	int i;
	int j;
	t_color tmp;

	tmp = get_average_color(scene, pitch);
	j = -1;
	while (++j < scene->pixelation_k)
	{
		i = -1;
		while (++i < scene->pixelation_k)
		{
			scene->frame_buffer[pitch + i + (int)(IMG_SIZE_W * j)].r = tmp.r;
			scene->frame_buffer[pitch + i + (int)(IMG_SIZE_W * j)].g = tmp.g;
			scene->frame_buffer[pitch + i + (int)(IMG_SIZE_W * j)].b = tmp.b;
		}
	}
}

void	motion_blur(t_color *frame_buffer, t_color **motion_blur_frame_buffers)
{
	int i;
	int n;
	int sum_r;
	int sum_g;
	int sum_b;
	
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		n = -1;
		sum_r = 0;
		sum_g = 0;
		sum_b = 0;
		while (++n < MOTION_BLUR_BUFFERS)
		{
			sum_r += motion_blur_frame_buffers[n][i].r;
			sum_g += motion_blur_frame_buffers[n][i].g;
			sum_b += motion_blur_frame_buffers[n][i].b;
		}
		frame_buffer[i].r = (int)(sum_r / MOTION_BLUR_BUFFERS);
		frame_buffer[i].g = (int)(sum_g / MOTION_BLUR_BUFFERS);
		frame_buffer[i].b = (int)(sum_b / MOTION_BLUR_BUFFERS);
	}
}

t_color	get_average_color(t_scene *scene, int pitch)
{
	int		i;
	int		j;
	t_color	tmp;

	tmp = (t_color){0, 0, 0};
	j = -1;
	while (++j < scene->pixelation_k)
	{
		i = -1;
		while (++i < scene->pixelation_k)
		{
			tmp.r += scene->frame_buffer[pitch + i + (int)(IMG_SIZE_W * j)].r;
			tmp.g += scene->frame_buffer[pitch + i + (int)(IMG_SIZE_W * j)].g;
			tmp.b += scene->frame_buffer[pitch + i + (int)(IMG_SIZE_W * j)].b;
		}
	}
	tmp.r /= scene->pixelation_k * scene->pixelation_k;
	tmp.g /= scene->pixelation_k * scene->pixelation_k;
	tmp.b /= scene->pixelation_k * scene->pixelation_k;
	return (tmp);
}

// void	effect_pixelation(t_scene *scene)
// {
// 	int pitch;
// 	int i;
// 	int k;
	
// 	pitch = 0;
// 	i = IMG_SIZE_H / scene->pixelation_k - 1;
// 	k = 0;
// 	while (k < IMG_SIZE_W * IMG_SIZE_H / (scene->pixelation_k * scene->pixelation_k))
// 	{
// 		while (pitch < i * IMG_SIZE_W * scene->pixelation_k)
// 		{
// 			get_macro_pixel(scene, pitch);
// 			pitch += scene->pixelation_k;
// 			k++;
// 		}
// 		i++;
// 		ft_putnbr(pitch);
// 		ft_putchar('\n');
// 		// pitch += IMG_SIZE_W * scene->pixelation_k;
// 	}
// }

void	effect_pixelation(t_scene *scene)
{
	int pitch;
	int i;
	
	pitch = 0;
	i = IMG_SIZE_H / scene->pixelation_k - 1;
	while (pitch < IMG_SIZE_W * IMG_SIZE_H)
	{
		while (pitch < i * IMG_SIZE_W * scene->pixelation_k)
		{
			get_macro_pixel(scene, pitch);
			pitch += scene->pixelation_k;
		}
		i++;
		// ft_putnbr(pitch);
		// ft_putchar('\n');
		// pitch += IMG_SIZE_W * scene->pixelation_k;
	}
}

