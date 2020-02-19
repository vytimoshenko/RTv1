/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/20 01:19:48 by mperseus         ###   ########.fr       */
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
            color = get_color(status->spheres_arr, status->camera,
			canvas_to_viewport(x, y));
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

int	        get_color(t_sphere	**spheres_arr, t_vector camera,
			t_vector viewport_pixel)
{
	int i;
	int closest_color;
	int closest;

	i = -1;
	closest = DRAW_DISTANCE_MAX;
	while (++i < 3)
	{
		sphere_intersect(spheres_arr[i], camera, viewport_pixel);
		if (spheres_arr[i]->t1 >= DRAW_DISTANCE_MIN && spheres_arr[i]->t1 <=
		DRAW_DISTANCE_MAX && spheres_arr[i]->t1 < closest)
		{
			closest = spheres_arr[i]->t1;
			closest_color = spheres_arr[i]->color;
		}
		if (spheres_arr[i]->t2 >= DRAW_DISTANCE_MIN && spheres_arr[i]->t2 <=
		DRAW_DISTANCE_MAX && spheres_arr[i]->t2 < closest)
		{
			closest = spheres_arr[i]->t2;
			closest_color = spheres_arr[i]->color;
		}
	}
	if (closest == DRAW_DISTANCE_MAX)
		return (BACK_COLOR);
	else
		return (closest_color);
}

void	    sphere_intersect(t_sphere *sphere, t_vector camera,
			t_vector viewport_pixel)
{	
	t_vector    cam_to_obj;
	double      k1;
	double      k2;
	double      k3;
	double      d;
	
	cam_to_obj = substract(sphere->center, camera);
	k1 = dot(viewport_pixel, viewport_pixel);
	k2 = 2 * dot(cam_to_obj, viewport_pixel);
	k3 = dot(cam_to_obj, cam_to_obj) - sphere->radius * sphere->radius;
	d = k2 * k2 - 4 * k1 * k3;
	if (d < 0)
	{
		sphere->t1 = -1;
		sphere->t2 = -1;
		return;
	}
	sphere->t1 = (-k2 + sqrt(d)) / (2 * k1);
	sphere->t2 = (-k2 - sqrt(d)) / (2 * k1);
}

double      dot(t_vector v1, t_vector v2)
{
	return ((double)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

t_vector    substract(t_vector start, t_vector end)
{
	t_vector result;

	result.x = end.x - start.x;
	result.y = end.y - start.y;
	result.z = end.z - start.z;
	return (result);
}
