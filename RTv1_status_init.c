/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_status_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/25 02:08:11 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_status	*init_status(int argc, char **argv)
{
	t_status		*status;
	
	(void)argc;
	(void)argv;
	// if (argc != 2)
	// 	error_wrong_argument();
	if (!(status = (t_status *)ft_memalloc(sizeof(t_status))))
		ft_put_errno(PROGRAM_NAME);
	// check_argument(status, argv[1]);
	reset_status(status);
	return (status);
}

void		error_wrong_argument(void)
{
	ft_putendl("usage:");
	ft_putendl("\tmandelbrot\t1");
	ft_putendl("\tjulia\t\t2");
	ft_putendl("\tburning ship\t3");
	ft_putendl("\tspider\t\t4");
	ft_putendl("\tsin\t\t5");
	exit(1);
}

double	deg_to_rad(int degrees)
{
	return ((double)degrees * PI / 180.0);
}

void		reset_status(t_status *status)
{
	int	i;

	status->y_rotation = 15.0;

	// status->m.a[0] = 0.7071;
	// status->m.a[1] = 0.0;
	// status->m.a[2] = -0.7071;
	// status->m.b[0] = 0.0;
	// status->m.b[1] = 1.0;
	// status->m.b[2] = 0.0;
	// status->m.c[0] = 0.7071;
	// status->m.c[1] = 0.0;
	// status->m.c[2] = 0.7071;

	status->current_camera = 0;

	status->cameras.quantity = 3;
	status->cameras.array = (t_vector **)ft_memalloc(sizeof(t_vector *) * status->cameras.quantity);
	i = -1;
	while (++i < status->cameras.quantity)
		status->cameras.array[i] = (t_vector *)ft_memalloc(sizeof(t_vector));
	i = 0;
	status->cameras.array[i]->x = 0.0;
	status->cameras.array[i]->y = 0.0;
	status->cameras.array[i]->z = -1.0;
	i++;
	status->cameras.array[i]->x = 2.0;
	status->cameras.array[i]->y = 1.0;
	status->cameras.array[i]->z = -1.0;
	i++;
	status->cameras.array[i]->x = -2.0;
	status->cameras.array[i]->y = -2.0;
	status->cameras.array[i]->z = -5.0;

	status->spheres.quantity = 4;
	status->spheres.array = (t_sphere **)ft_memalloc(sizeof(t_sphere *) * status->spheres.quantity);
	i = -1;
	while (++i < status->spheres.quantity)
		status->spheres.array[i] = (t_sphere *)ft_memalloc(sizeof(t_sphere));
	i = 0;
	status->spheres.array[i]->num = i;
	status->spheres.array[i]->color.r = 0xFF;
	status->spheres.array[i]->color.g = 0x00;
	status->spheres.array[i]->color.b = 0x00;
	status->spheres.array[i]->specular = 500;
	status->spheres.array[i]->reflective = 0.2;
	status->spheres.array[i]->center.x = 0.0;
	status->spheres.array[i]->center.y = -1.0;
	status->spheres.array[i]->center.z = 3.0;
	status->spheres.array[i]->radius = 1.0;
	i++;
	status->spheres.array[i]->num = i;
	status->spheres.array[i]->color.r = 0x00;
	status->spheres.array[i]->color.g = 0xFF;
	status->spheres.array[i]->color.b = 0x00;
	status->spheres.array[i]->specular = 10;
	status->spheres.array[i]->reflective = 0.4;
	status->spheres.array[i]->center.x = 2.0;
	status->spheres.array[i]->center.y = 0.2;
	status->spheres.array[i]->center.z = 4.0;
	status->spheres.array[i]->radius = 1.2;
	i++;
	status->spheres.array[i]->num = i;
	status->spheres.array[i]->color.r = 0x00;
	status->spheres.array[i]->color.g = 0x00;
	status->spheres.array[i]->color.b = 0xFF;
	status->spheres.array[i]->specular = 500;
	status->spheres.array[i]->reflective = 0.3;
	status->spheres.array[i]->center.x = -2.0;
	status->spheres.array[i]->center.y = 0.0;
	status->spheres.array[i]->center.z = 4.0;
	status->spheres.array[i]->radius = 0.8;
	i++;
	status->spheres.array[i]->num = i;
	status->spheres.array[i]->color.r = 0xFF;
	status->spheres.array[i]->color.g = 0xFF;
	status->spheres.array[i]->color.b = 0x00;
	status->spheres.array[i]->specular = 250;
	status->spheres.array[i]->reflective = 0.2;
	status->spheres.array[i]->center.x = 0.0;
	status->spheres.array[i]->center.y = -5001.0;
	status->spheres.array[i]->center.z = 0.0;
	status->spheres.array[i]->radius = 5000;

	// status->light_sources.quantity = 3;
	status->light_sources.quantity = 3;
	status->light_sources.array = (t_light **)ft_memalloc(sizeof(t_light *) * status->light_sources.quantity);
	i = -1;
	while (++i < status->light_sources.quantity)
		status->light_sources.array[i] = (t_light *)ft_memalloc(sizeof(t_light));
	i = 0;
	status->light_sources.array[i]->type = LIGHT_TYPE_AMBIENT;
	status->light_sources.array[i]->intensity = 0.2;
	i++;
	status->light_sources.array[i]->type = LIGHT_TYPE_POINT;
	status->light_sources.array[i]->intensity = 0.6;
	status->light_sources.array[i]->position.x = 2;
	status->light_sources.array[i]->position.y = 1;
	status->light_sources.array[i]->position.z = 0;
    i++;
	status->light_sources.array[i]->type = LIGHT_TYPE_DIRECTIONAL;
	status->light_sources.array[i]->intensity = 0.2;
	status->light_sources.array[i]->direction.x = 1;
	status->light_sources.array[i]->direction.y = 4;
	status->light_sources.array[i]->direction.z = 4;
}
