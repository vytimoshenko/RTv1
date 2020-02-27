/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_status_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 01:54:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_status	*init_status(int argc, char **argv)
{
	t_status		*status;
	
	(void)argv;
	if (argc != 2)
		ft_put_error("usage: RTv1 scene_name.rt");
	if (!(status = (t_status *)ft_memalloc(sizeof(t_status))))
		ft_put_errno(PROGRAM_NAME);
	// check_argument(status, argv[1]);
	reset_status(status);
	init_object_buffer(status);
	status->file_name_with_path = ft_strdup(argv[1]);
	return (status);
}

void		init_object_buffer(t_status *status)
{
	if (!(status->object_buffer = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	if (!(status->got_object = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_object_buffer(status);
}

void		clean_object_buffer(t_status *status)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		status->object_buffer[i] = NO_OBJECT_SELECTED;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		status->got_object[i] = FALSE;
}

void		reset_status(t_status *status)
{
	int	i;

	status->active_object = -1;
	status->scene_name = ft_strdup("Four amazing balls");

	status->current_camera = 0;

	status->cameras_quantity = 3;
	status->cameras = (t_camera **)ft_memalloc(sizeof(t_camera *) * status->cameras_quantity);
	i = -1;
	while (++i < status->cameras_quantity)
		status->cameras[i] = (t_camera *)ft_memalloc(sizeof(t_camera));
	i = 0;
	status->cameras[i]->position.x = 0.0;
	status->cameras[i]->position.y = 0.0;
	status->cameras[i]->position.z = -10.0;
	status->cameras[i]->direction.x = 0.0;
	status->cameras[i]->direction.y = 0.0;
	status->cameras[i]->direction.z = 0.0;
	i++;
	status->cameras[i]->position.x = 20.0;
	status->cameras[i]->position.y = 10.0;
	status->cameras[i]->position.z = -80.0;
	status->cameras[i]->direction.x = 0.0;
	status->cameras[i]->direction.y = 0.0;
	status->cameras[i]->direction.z = 0.0;
	i++;
	status->cameras[i]->position.x = 0.0;
	status->cameras[i]->position.y = 100.0;
	status->cameras[i]->position.z = 30.0;
	status->cameras[i]->direction.x = -90.0;
	status->cameras[i]->direction.y = 0.0;
	status->cameras[i]->direction.z = 0.0;

	status->spheres.quantity = 4;
	status->spheres.array = (t_sphere **)ft_memalloc(sizeof(t_sphere *) * status->spheres.quantity);
	i = -1;
	while (++i < status->spheres.quantity)
		status->spheres.array[i] = (t_sphere *)ft_memalloc(sizeof(t_sphere));
	i = 0;
	status->spheres.array[i]->id = i;
	status->spheres.array[i]->color.r = 0xFF;
	status->spheres.array[i]->color.g = 0x00;
	status->spheres.array[i]->color.b = 0x00;
	status->spheres.array[i]->specular = 500;
	status->spheres.array[i]->reflective = 0.2;
	status->spheres.array[i]->center.x = 0.0;
	status->spheres.array[i]->center.y = -10.0;
	status->spheres.array[i]->center.z = 30.0;
	status->spheres.array[i]->radius = 10.0;
	i++;
	status->spheres.array[i]->id = i;
	status->spheres.array[i]->color.r = 0x00;
	status->spheres.array[i]->color.g = 0xFF;
	status->spheres.array[i]->color.b = 0x00;
	status->spheres.array[i]->specular = 1000;
	status->spheres.array[i]->reflective = 0.7;
	status->spheres.array[i]->center.x = 20.0;
	status->spheres.array[i]->center.y = 1.0;
	status->spheres.array[i]->center.z = 40.0;
	status->spheres.array[i]->radius = 12.0;
	i++;
	status->spheres.array[i]->id = i;
	status->spheres.array[i]->color.r = 0x00;
	status->spheres.array[i]->color.g = 0x00;
	status->spheres.array[i]->color.b = 0xFF;
	status->spheres.array[i]->specular = 500;
	status->spheres.array[i]->reflective = 0.3;
	status->spheres.array[i]->center.x = -20.0;
	status->spheres.array[i]->center.y = 0.0;
	status->spheres.array[i]->center.z = 40.0;
	status->spheres.array[i]->radius = 8.0;
	i++;
	status->spheres.array[i]->id = i;
	status->spheres.array[i]->color.r = 0xFF;
	status->spheres.array[i]->color.g = 0xFF;
	status->spheres.array[i]->color.b = 0x00;
	status->spheres.array[i]->specular = 250;
	status->spheres.array[i]->reflective = 0.2;
	status->spheres.array[i]->center.x = 0.0;
	status->spheres.array[i]->center.y = -50010.0;
	status->spheres.array[i]->center.z = 0.0;
	status->spheres.array[i]->radius = 50000;

	// status->light_sources.quantity = 3;
	status->light_sources.quantity = 4;
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
	status->light_sources.array[i]->position.x = -20;
	status->light_sources.array[i]->position.y = 20;
	status->light_sources.array[i]->position.z = 30;
	i++;
	status->light_sources.array[i]->type = LIGHT_TYPE_POINT;
	status->light_sources.array[i]->intensity = 0.3;
	status->light_sources.array[i]->position.x = 20;
	status->light_sources.array[i]->position.y = 10;
	status->light_sources.array[i]->position.z = 00;
    i++;
	status->light_sources.array[i]->type = LIGHT_TYPE_DIRECTIONAL;
	status->light_sources.array[i]->intensity = 0.2;
	status->light_sources.array[i]->direction.x = 10;
	status->light_sources.array[i]->direction.y = 40;
	status->light_sources.array[i]->direction.z = 40;
}
