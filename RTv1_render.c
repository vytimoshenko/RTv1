/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/26 21:36:37 by mperseus         ###   ########.fr       */
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
	x = -IMG_SIZE_W / 2;
	while (++x < IMG_SIZE_W / 2)
	{
		y = -IMG_SIZE_H / 2;
		while (++y < IMG_SIZE_H / 2)
        {
			camera_direction = canvas_to_viewport(x, y);
			camera_direction = rotate_direction(camera_direction, status);
			color = get_color(status->spheres, status->light_sources,
			*status->cameras.array[status->current_camera], camera_direction,
			REFLECTION_DEPTH, status, x, y);
			if (status->active_object != NO_OBJECT_SELECTED)
				color = shade_unselesected(status, x, y, color);
			united_color = unite_color_channels(color);
			put_pixel(mlx, x, y, united_color);
        }
	}
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

void	    put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int i;

	x = IMG_SIZE_W / 2 + x;
  	y = IMG_SIZE_H / 2 - y;
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	mlx->data[i] = color;
}

t_vector    canvas_to_viewport(int x, int y)
{
	t_vector viewport_pixel;

	viewport_pixel.x = x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	viewport_pixel.y = y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	viewport_pixel.z = VIEWPORT_DISTANCE;
	return (viewport_pixel);
}

t_vector	rotate_direction(t_vector vector, t_status *status)
{
	double temp1;
	double temp2;
	double x_angle;
	double y_angle;
	double z_angle;

	x_angle = deg_to_rad(status->x_rotation);
	y_angle = deg_to_rad(status->y_rotation);
	z_angle = deg_to_rad(status->z_rotation);
	temp1 = vector.y * cos(x_angle) + vector.z * sin(x_angle);
	temp2 = -vector.y * sin(x_angle) + vector.z * cos(x_angle);
	vector.y = temp1;
	vector.z = temp2;
	temp1 = vector.x * cos(y_angle) + vector.z * sin(y_angle);
	temp2 = -vector.x * sin(y_angle) + vector.z * cos(y_angle);
	vector.x = temp1;
	vector.z = temp2;
	temp1 = vector.x * cos(z_angle) - vector.y * sin(z_angle);
	temp2 = vector.x * sin(z_angle) + vector.y * cos(z_angle);
	vector.x = temp1;
	vector.y = temp2;
	return (vector);
}
