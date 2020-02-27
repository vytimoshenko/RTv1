/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/27 05:30:48 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	    get_image(t_status *status, t_mlx *mlx)
{
	int	x;
	int	y;
    int united_color;
	t_vector	camera_direction;
	t_color		color;
	
	clean_object_buffer(status);
	get_sin_cos(status->cameras[status->current_camera]);
	x = -IMG_SIZE_W / 2;
	while (++x < IMG_SIZE_W / 2)
	{
		y = -IMG_SIZE_H / 2;
		while (++y < IMG_SIZE_H / 2)
        {
			camera_direction = canvas_to_viewport(x, y);
			camera_direction = rotate_direction(camera_direction,
			status->cameras[status->current_camera]);
			color = get_color(status->spheres, status->light_sources,
			status->cameras[status->current_camera]->position, camera_direction,
			REFLECTION_DEPTH, status, x, y);
			if (status->active_object != NO_OBJECT_SELECTED)
				color = shade_unselesected(status, x, y, color);
			if (status->effect == EFFECT_GRAYSCALE)
				color = effect_grayscale(color);
			else if (status->effect == EFFECT_CARTOON)
				color = effect_cartoon(color);
			united_color = unite_color_channels(color);
			put_pixel(mlx, x, y, united_color);
        }
	}
}

t_vector    canvas_to_viewport(int x, int y)
{
	t_vector viewport_pixel;

	viewport_pixel.x = x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	viewport_pixel.y = y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	viewport_pixel.z = VIEWPORT_DISTANCE;
	return (viewport_pixel);
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

t_vector	rotate_direction(t_vector vector, t_camera *camera)
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

t_color		shade_unselesected(t_status *status, int x, int y, t_color color)
{
	int i;

	x = IMG_SIZE_W / 2 + x;
  	y = IMG_SIZE_H / 2 - y;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	if (status->object_buffer[i] != status->active_object)
		return (multiply_color(SHADE_UNSELECTED, color));
	else
		return (color);
}

t_color		effect_grayscale(t_color color)
{
	int tmp;

	tmp = 0.2126 * color.r + 0.7152 * color.g + 0.0722 * color.b;
	color.r = tmp;
	color.g = tmp;
	color.b = tmp;
	return (color);
}


t_color		effect_cartoon(t_color color)
{
	color.r /= 32;
	color.g /= 32;
	color.b /= 32;
	color.r *= 32;
	color.g *= 32;
	color.b *= 32;
	return (color);
}

// int		*effect_pixelation(int *img)
// {
// 	int x;
// 	int y;

// 	avr.r = 
// }

void	    put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int i;

	x = IMG_SIZE_W / 2 + x;
  	y = IMG_SIZE_H / 2 - y;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	mlx->data[i] = color;
}
