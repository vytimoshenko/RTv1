/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/06 02:25:22 by mperseus         ###   ########.fr       */
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
	while (++pixel.x < IMG_SIZE_W / 2)
	{
		pixel.y = -IMG_SIZE_H / 2;
		while (++pixel.y < IMG_SIZE_H / 2)
		{
			// if (scene->anti_aliasing == TRUE)
			// 	anti_aliasing(scene, &pixel, jitter);
			// else
			// {
				pixel.color = scene->background;
				get_pixel_position(scene, &pixel);
				get_pixel_color(scene, scene->cameras[scene->current_camera]->
				position, &pixel, REFLECTION_DEPTH);
			// }
			fill_frame_buffer(scene, pixel);
		}
	}
	fill_aliasing_buffer(scene);
	if (scene->anti_aliasing == TRUE)
	{
		pixel.x = -IMG_SIZE_W / 2;
		while (++pixel.x < IMG_SIZE_W / 2)
		{
			pixel.y = -IMG_SIZE_H / 2;
			while (++pixel.y < IMG_SIZE_H / 2)
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

void	fill_aliasing_buffer(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->aliasing_buffer[i] = need_to_smooth(scene, i);
		if (scene->aliasing_buffer[i])
		{
			scene->aliasing_buffer[i - 2] = 1;
			scene->aliasing_buffer[i - 1] = 1;
			scene->aliasing_buffer[i + 1] = 1;
			scene->aliasing_buffer[i + 2] = 1;
			if (i - 2 - IMG_SIZE_W > 0)
			{
				scene->aliasing_buffer[i - 2 - (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i - 1 - (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i - (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + 1 - (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + 2 - (int)IMG_SIZE_W] = 1;
			}
			if (i + 2 + IMG_SIZE_W < IMG_SIZE_W * IMG_SIZE_H)
			{
				scene->aliasing_buffer[i - 2 + (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i - 1 + (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + 1 + (int)IMG_SIZE_W] = 1;
				scene->aliasing_buffer[i + 2 + (int)IMG_SIZE_W] = 1;
			}
			i++;
		}
	}
}

int	need_to_smooth(t_scene *scene, int i)
{
	t_color	diff;

	if (i == 0)
		return (0);
	diff = get_channel_diff(scene->frame_buffer[i], scene->frame_buffer[i - 1]);
	if (diff.r > 16 || diff.g > 16 || diff.b > 16)
		return (1);
	else
		return (0);
}

t_color	get_channel_diff(t_color c1, t_color c2)
{
	t_color	diff;

	diff.r = abs((c1.r - c2.r));
	diff.g = abs((c1.g - c2.g));
	diff.b = abs((c1.b - c2.b));
	return (diff);
}

void	anti_aliasing(t_scene *scene, t_pixel *pixel, double *jitter)
{
	int			i;
	t_color		sum;
	t_vector	tmp;

	sum = (t_color){0, 0, 0};
	i = -1;
	tmp.z = scene->cameras[scene->current_camera]->position.z;
	while (++i < MULTI_SAMPLING_RATE)
	{
		tmp.x = 0;
		tmp.y = 0;
		pixel->color = scene->background;
		get_pixel_position(scene, pixel);
		tmp.x = jitter[i] + scene->cameras[scene->current_camera]->position.x;
		tmp.y = jitter[i] + scene->cameras[scene->current_camera]->position.y;
		get_pixel_color(scene, tmp, pixel, REFLECTION_DEPTH);
		sum.r += pixel->color.r;
		sum.g += pixel->color.g;
		sum.b += pixel->color.b;
	}
	pixel->color.r = (int)(sum.r / (MULTI_SAMPLING_RATE));
	pixel->color.g = (int)(sum.g / (MULTI_SAMPLING_RATE));
	pixel->color.b = (int)(sum.b / (MULTI_SAMPLING_RATE));
}

void	get_jitter(double *random)
{
    int i;

	srand(79);
    i = -1;
	for (i = 1; i <= MULTI_SAMPLING_RATE; i++)
	{
    	random[i] = (rand() % 100 + 1.0) / 5000.0;
		if (i % 2)
        	random[i] *= -1;
		printf("%f\n", random[i]);
 	}
}

void	get_pixel_position(t_scene *scene, t_pixel *pixel)
{
	pixel->position.x = pixel->x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	pixel->position.y = pixel->y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	pixel->position.z = VIEWPORT_DISTANCE;
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

void		fill_frame_buffer(t_scene *scene, t_pixel pixel)
{
	int i;

	pixel.x = IMG_SIZE_W / 2 + pixel.x;
	pixel.y = IMG_SIZE_H / 2 - pixel.y;
	i = (int)(IMG_SIZE_W * (pixel.y - 1) + pixel.x);
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
	if (scene->effect == EFFECT_PIXELATION)
		effect_pixelation(scene);
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		mlx->data[i] = unite_color_channels(scene->frame_buffer[i]);
}

void	get_macro_pixel(t_scene *scene, int pitch)
{
	int i;
	int j;
	t_color tmp;

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

void	effect_pixelation(t_scene *scene)
{
	int pitch;
	int i;
	
	pitch = 0;
	i = IMG_SIZE_H / scene->pixelation_k - 1;
	while (pitch < IMG_SIZE_W * IMG_INDT_H)
	{
		while (pitch < i * IMG_SIZE_W * scene->pixelation_k)
		{
			get_macro_pixel(scene, pitch);
			pitch += scene->pixelation_k;
		}
		i++;
		pitch += i * IMG_SIZE_W * scene->pixelation_k;
	}
}