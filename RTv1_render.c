/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:48:28 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/20 21:08:47 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	    get_image(t_status *status, t_mlx *mlx)
{
	int	x;
	int	y;
    int color;
	// int color_int;
	
	x = -IMG_SIZE_W / 2;
	while (++x < IMG_SIZE_W / 2)
	{
		y = -IMG_SIZE_H / 2;
		while (++y < IMG_SIZE_H / 2)
        {
            color = get_color(status->spheres_arr, status->spheres_quantity,
			status->lights_arr, status->lights_quantity, status->camera, canvas_to_viewport(x, y));
			// if (color > 0xFFFFFF)
			// 	color = 0xFFFFFF;
			// else if (color < 0)
			// 	color = 0;
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

int	      get_color(t_sphere	**spheres_arr, int spheres_quantity,
			t_light **lights_arr, int lights_quantity,
			t_vector camera, t_vector viewport_pixel)
{
	int			i;
	double		closest;
	t_sphere	closest_sphere;
	t_vector	normal;
	t_vector	point;
	t_color		color;

	i = -1;
	closest = DRAW_DISTANCE_MAX;
	while (++i < spheres_quantity)
	{
		sphere_intersect(spheres_arr[i], camera, viewport_pixel);
		if (spheres_arr[i]->t1 >= DRAW_DISTANCE_MIN && spheres_arr[i]->t1 <=
		DRAW_DISTANCE_MAX && spheres_arr[i]->t1 < closest)
		{
			closest = spheres_arr[i]->t1;
			closest_sphere = *spheres_arr[i];
		}
		if (spheres_arr[i]->t2 >= DRAW_DISTANCE_MIN && spheres_arr[i]->t2 <=
		DRAW_DISTANCE_MAX && spheres_arr[i]->t2 < closest)
		{
			closest = spheres_arr[i]->t2;
			closest_sphere = *spheres_arr[i];
		}
	}
	if (closest == DRAW_DISTANCE_MAX)
		return (BACK_COLOR);
	point = add(camera, multiply(closest, viewport_pixel));
	normal = substract(point, closest_sphere.center);
	normal = multiply(1.0 / length(normal), normal);
	double light = get_lightning(point, normal, lights_arr, lights_quantity);
	// light = 1;
    // return (closest_sphere.color * light);
	color = multiply_color(light, closest_sphere.color);
	int color_int = 256 * 256 * color.r + 256 * color.g + color.b;
	return (color_int);
	// return Multiply(ComputeLighting(point, normal), closest_sphere.color);
}

void	    sphere_intersect(t_sphere *sphere, t_vector camera,
			t_vector viewport_pixel)
{	
	t_vector    cam_to_obj;
	double      k1;
	double      k2;
	double      k3;
	double      d;
	
	cam_to_obj = substract(camera, sphere->center);
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

double		get_lightning(t_vector point, t_vector normal,
			t_light **lights_arr, int lights_quantity)
{
	int		i;
	double	intensity;
	t_vector	l;
	double	ldn;

	intensity = 0.0;
	i = -1;
	while (++i < lights_quantity)
	{
		if (lights_arr[i]->type == LIGHT_TYPE_AMBIENT)
			intensity += lights_arr[i]->intensity;
		else
		{
			if (lights_arr[i]->type == LIGHT_TYPE_POINT)
				l = substract(lights_arr[i]->position, point);
			else if (lights_arr[i]->type == LIGHT_TYPE_DIRECTIONAL)
				l = lights_arr[i]->direction;
			ldn = dot(normal, l);
			if (ldn > 0)
				intensity += lights_arr[i]->intensity * ldn / (length(normal) * length(l));
		}
	}
	if (intensity > 1)
		intensity = 1;
	// printf("%f\n", intensity);
	return (intensity);
}

double      dot(t_vector v1, t_vector v2)
{
	return ((double)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

double      length(t_vector v1)
{
	return ((double)sqrt(dot(v1, v1)));
}

t_vector    multiply(double k, t_vector v)
{
	t_vector result;
	
	result.x = k * v.x;
	result.y = k * v.y;
	result.z = k * v.z;
	return (result);
}

t_color    multiply_color(double k, t_color color)
{
	t_color result;
	
	result.r = k * color.r;
	result.g = k * color.g;
	result.b = k * color.b;
	return (result);
}

t_vector    add(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vector    substract(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}
