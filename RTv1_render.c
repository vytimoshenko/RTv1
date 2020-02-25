/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/26 01:21:33 by mperseus         ###   ########.fr       */
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
			// get_m(&status->m, status->y_rotation);
			// camera_direction = multiply_mv(status->m, camera_direction);
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

void		get_m(t_matrix *m, double y_rotation)
{
	m->a[0] = cos(deg_to_rad(y_rotation));
	m->a[1] = 0.0;
	m->a[2] = -1 * sin(deg_to_rad(y_rotation));
	m->b[0] = 0.0;
	m->b[1] = 1.0;
	m->b[2] = 0.0;
	m->c[0] = cos(deg_to_rad(y_rotation));
	m->c[1] = 0.0;
	m->c[2] = cos(deg_to_rad(y_rotation));
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
