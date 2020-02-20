/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_status_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/20 20:50:37 by mperseus         ###   ########.fr       */
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

void		reset_status(t_status *status)
{
	int	i;

	status->camera.x = 0.0;
	status->camera.y = 0.0;
	status->camera.z = 0.0;

	status->spheres_quantity = 4;
	status->spheres_arr = (t_sphere **)ft_memalloc(sizeof(t_sphere *) * status->spheres_quantity);
	i = -1;
	while (++i < status->spheres_quantity)
		status->spheres_arr[i] = (t_sphere *)ft_memalloc(sizeof(t_sphere));
	i = 0;
	// status->spheres_arr[i]->color = 0x00FF00;
	status->spheres_arr[i]->color.r = 0xFF;
	status->spheres_arr[i]->color.g = 0x00;
	status->spheres_arr[i]->color.b = 0x00;
	status->spheres_arr[i]->center.x = 0.0;
	status->spheres_arr[i]->center.y = -1.0;
	status->spheres_arr[i]->center.z = 3.0;
	status->spheres_arr[i]->radius = 1.25;
	i++;
	// status->spheres_arr[i]->color = 0x00FF00;
	status->spheres_arr[i]->color.r = 0x00;
	status->spheres_arr[i]->color.g = 0xFF;
	status->spheres_arr[i]->color.b = 0x00;
	status->spheres_arr[i]->center.x = 2.0;
	status->spheres_arr[i]->center.y = 0.0;
	status->spheres_arr[i]->center.z = 4.0;
	status->spheres_arr[i]->radius = 1;
	i++;
	// status->spheres_arr[i]->color = 0x0000FF;
	status->spheres_arr[i]->color.r = 0x00;
	status->spheres_arr[i]->color.g = 0x00;
	status->spheres_arr[i]->color.b = 0xFF;
	status->spheres_arr[i]->center.x = -2.0;
	status->spheres_arr[i]->center.y = 0.0;
	status->spheres_arr[i]->center.z = 4.0;
	status->spheres_arr[i]->radius = 1;
	i++;
	// status->spheres_arr[i]->color = 0x00FFFF;
	status->spheres_arr[i]->color.r = 0x00;
	status->spheres_arr[i]->color.g = 0xFF;
	status->spheres_arr[i]->color.b = 0xFF;
	status->spheres_arr[i]->center.x = 0.0;
	status->spheres_arr[i]->center.y = -5001.0;
	status->spheres_arr[i]->center.z = 0.0;
	status->spheres_arr[i]->radius = 5000;

	status->lights_quantity = 3;
	status->lights_arr = (t_light **)ft_memalloc(sizeof(t_light *) * status->lights_quantity);
	i = -1;
	while (++i < status->lights_quantity)
		status->lights_arr[i] = (t_light *)ft_memalloc(sizeof(t_light));
	i = 0;
	status->lights_arr[i]->type = LIGHT_TYPE_AMBIENT;
	status->lights_arr[i]->intensity = 0.2;
	i++;
	status->lights_arr[i]->type = LIGHT_TYPE_POINT;
	status->lights_arr[i]->intensity = 0.6;
	status->lights_arr[i]->position.x = 2;
	status->lights_arr[i]->position.x = 1;
	status->lights_arr[i]->position.x = 0;
    i++;
	status->lights_arr[i]->type = LIGHT_TYPE_DIRECTIONAL;
	status->lights_arr[i]->intensity = 0.2;
	status->lights_arr[i]->direction.x = 1;
	status->lights_arr[i]->direction.x = 4;
	status->lights_arr[i]->direction.x = 4;
}
