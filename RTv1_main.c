/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:09:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/19 03:26:46 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int	main(int argc, char **argv)
{
	t_global	global;

	(void)argc;
	(void)argv;
	// global.status = init_status(argc, argv);
	global.mlx = init_mlx();
	draw(&global);
	loop(&global);
	exit(0);
}

void	get_image(t_mlx *mlx)
{
	int	x;
	int	y;
	
	x = -IMG_SIZE_W/ 2;
	while (++x <= IMG_SIZE_W/ 2)
	{
		y = -IMG_SIZE_H/ 2;
		while (++y <= IMG_SIZE_H/ 2)
			put_pixel(mlx, x, y, get_color(mlx, canvas_to_viewport(x, y)));
	}
}

void	put_pixel(t_mlx *mlx, int x, int y, int color)
{
	x = IMG_SIZE_W / 2 + x;
  	y = IMG_SIZE_H / 2 - y - 1;
	if (x >= 0 || x < IMG_SIZE_W || y >= 0 || y < IMG_SIZE_H)
		mlx->data[(int)(IMG_SIZE_W * (y - 1) + x)] = color;
}

t_vector canvas_to_viewport(int x, int y)
{
	t_vector d;

	d.x = x * VIEWPORT_SIZE_W / IMG_SIZE_W;
	d.y = y * VIEWPORT_SIZE_H / IMG_SIZE_H;
	d.z = VIEWPORT_DISTANCE;
	return (d);
}


int	get_color(t_mlx *mlx, t_vector d)
{
	double t_min;
	double t_max;
	int sphere_color = 0xFF0000;

	t_min = 1.0;
	t_max = 1000000.0;
	find_intersection(mlx, d);
	// printf("x%f,y%f,z%f\n", d.x, d.y, d.z);
	// printf("t1 %f t2 %f\n", mlx->t1, mlx->t2);
	// if (mlx->t1 >= t_min && mlx->t1 <= t_max /*&& mlx->t1 < closest*/)
	// {
	// 	// closest = mlx->t1;
	// 	// closest_sphere = sphere_color;
	// }
	// if (mlx->t2 >= t_min && mlx->t2 <= t_max /*&& mlx->t2 < closest*/)
	// {
	// 	// closest = mlx->t2;
	// 	// closest_sphere = sphere_color;
	// }
	// if (closest_sphere == 0)
	if (mlx->t1 < 1 && mlx->t1 < 1)
		return (BACK_COLOR);
	else
		return (sphere_color);
}

double dot(t_vector v1, t_vector v2)
{
	return ((double)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

t_vector substract(t_vector start, t_vector end)
{
	t_vector result;

	result.x = end.x - start.x;
	result.y = end.y - start.y;
	result.z = end.z - start.z;
	return (result);
}

void	find_intersection(t_mlx *mlx, t_vector d)
{	
	double k1;
	double k2;
	double k3;
	double discriminant;
	
	t_vector camera;
	t_vector sphere_center;
	t_vector oc;
	
	camera.x = 0.0;
	camera.y = 0.0;
	camera.z = 0.0;
	sphere_center.x = 0.0;
	sphere_center.y = 0.0;
	sphere_center.z = 10.0;
	int r = 3.0;

	oc = substract(sphere_center, camera);

	k1 = dot(d, d);
	k2 = 2 * dot(oc, d);
	k3 = dot(oc, oc) - r * r;
	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
	{
		mlx->t1 = -1;
		mlx->t2 = -1;
		return;
	}
	mlx->t1 = (-k2 + sqrt(discriminant)) / (2 * k1);
	mlx->t2 = (-k2 - sqrt(discriminant)) / (2 * k1);
}