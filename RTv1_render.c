/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/24 03:22:47 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	    get_image(t_status *status, t_mlx *mlx)
{
	int	x;
	int	y;
    int color;
	
	x = -IMG_SIZE_W / 2;
	while (++x < IMG_SIZE_W / 2)
	{
		y = -IMG_SIZE_H / 2;
		while (++y < IMG_SIZE_H / 2)
        {
			// D = camera.rotation * CanvasToViewport(x, y)
			color = unite_color_channels(get_color(status->spheres, status->light_sources,
			*status->cameras.array[status->current_camera], canvas_to_viewport(x, y),
			REFLECTION_DEPTH));
			put_pixel(mlx, x, y, color);
        }
	}
}

void	    put_pixel(t_mlx *mlx, int x, int y, int color)
{
	x = IMG_SIZE_W / 2 + x;
  	y = IMG_SIZE_H / 2 - y - 1;
	if (x >= 0 || x < IMG_SIZE_W || y >= 0 || y < IMG_SIZE_H)
		mlx->data[(int)(IMG_SIZE_W * (y - 1) + x)] = color;
}

t_vector    canvas_to_viewport(int x, int y)
{
	t_vector viewport_pixel;

	viewport_pixel.x = x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	viewport_pixel.y = y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	viewport_pixel.z = VIEWPORT_DISTANCE;
	return (viewport_pixel);
}
