/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_scene_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 01:34:38 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 01:54:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene	*init_scene(int argc, char **argv)
{
	t_scene		*scene;
	
	(void)argv;
	if (argc != 2)
		ft_put_error("usage: RTv1 scene_name.rt");
	if (!(scene = (t_scene *)ft_memalloc(sizeof(t_scene))))
		ft_put_errno(PROGRAM_NAME);
	// check_argument(scene, argv[1]);
	reset_scene(scene);
	// read_map(scene, argv[1]);
	init_frame_buffer(scene);
	init_depth_buffer(scene);
	init_object_buffer(scene);
	get_sin_cos(scene->cameras[scene->current_camera]);
	scene->file_name_with_path = ft_strdup(argv[1]);
	return (scene);
}

// void	check_scene(t_scene *scene)
// {
	
// }

// void	read_scene(t_scene *scene)
// {

// }

void		init_frame_buffer(t_scene *scene)
{
	int i;

	if (!(scene->frame_buffer = (t_color *)malloc(sizeof(t_color)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	if (!(scene->motion_blur_frame_buffers = (t_color **)malloc(sizeof(t_color *)
	* MOTION_BLUR_BUFFERS)))
		ft_put_errno(PROGRAM_NAME);
	i = -1;
	while (++i < MOTION_BLUR_BUFFERS)
	{
		if (!(scene->motion_blur_frame_buffers[i] = (t_color *)malloc(sizeof(t_color)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	}
}

void		clean_frame_buffer(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i] = (t_color){0, 0, 0};
}

void		init_object_buffer(t_scene *scene)
{
	if (!(scene->object_buffer = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	if (!(scene->got_object = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_object_buffer(scene);
}

void		clean_object_buffer(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->object_buffer[i] = NO_OBJECT_SELECTED;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->got_object[i] = FALSE;
}

void		init_depth_buffer(t_scene *scene)
{
	if (!(scene->depth_buffer = (double *)malloc(sizeof(double)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	if (!(scene->got_depth = (int *)malloc(sizeof(int)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
	clean_depth_buffer(scene);
}

void		clean_depth_buffer(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->depth_buffer[i] = NO_OBJECT_SELECTED;
	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->got_depth[i] = FALSE;
}

void		reset_scene(t_scene *scene)
{
	int	i;

	scene->active_object = -1;
	scene->scene_name = ft_strdup("Four amazing balls");

	scene->current_camera = 0;
	scene->depth_map_k = 64;

	scene->cameras_quantity = 4;
	scene->cameras = (t_camera **)ft_memalloc(sizeof(t_camera *) * scene->cameras_quantity);
	i = -1;
	while (++i < scene->cameras_quantity)
		scene->cameras[i] = (t_camera *)ft_memalloc(sizeof(t_camera));
	i = 0;
	scene->cameras[i]->position.x = 0.0;
	scene->cameras[i]->position.y = 0.0;
	scene->cameras[i]->position.z = -10.0;
	scene->cameras[i]->direction.x = 0.0;
	scene->cameras[i]->direction.y = 0.0;
	scene->cameras[i]->direction.z = 0.0;
	scene->cameras[i]->zoom = 1.0;
	i++;
	scene->cameras[i]->position.x = 20.0;
	scene->cameras[i]->position.y = 10.0;
	scene->cameras[i]->position.z = -80.0;
	scene->cameras[i]->direction.x = 0.0;
	scene->cameras[i]->direction.y = 0.0;
	scene->cameras[i]->direction.z = 0.0;
	scene->cameras[i]->zoom = 1.0;
	i++;
	scene->cameras[i]->position.x = 0.0;
	scene->cameras[i]->position.y = 100.0;
	scene->cameras[i]->position.z = 30.0;
	scene->cameras[i]->direction.x = -90.0;
	scene->cameras[i]->direction.y = 0.0;
	scene->cameras[i]->direction.z = 0.0;
	scene->cameras[i]->zoom = 1.0;
		i++;
	scene->cameras[i]->position.x = 0.0;
	scene->cameras[i]->position.y = 100.0;
	scene->cameras[i]->position.z = 30.0;
	scene->cameras[i]->direction.x = 0.0;
	scene->cameras[i]->direction.y = -75.0;
	scene->cameras[i]->direction.z = 0.0;
	scene->cameras[i]->zoom = 1.0;

	scene->objects.quantity = 6;
	scene->objects.array = (t_object **)ft_memalloc(sizeof(t_object *) * scene->objects.quantity);
	i = -1;
	while (++i < scene->objects.quantity)
		scene->objects.array[i] = (t_object *)ft_memalloc(sizeof(t_object));
	i = 0;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->color.r = 0xFF;
	scene->objects.array[i]->color.g = 0x00;
	scene->objects.array[i]->color.b = 0x00;
	scene->objects.array[i]->specular = 1000;
	scene->objects.array[i]->reflective = 0.5;
	scene->objects.array[i]->transparency = 0.0;
	scene->objects.array[i]->center.x = 0.0;
	scene->objects.array[i]->center.y = -10.0;
	scene->objects.array[i]->center.z = 30.0;
	scene->objects.array[i]->radius = 10.0;
	i++;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->color.r = 0x00;
	scene->objects.array[i]->color.g = 0xFF;
	scene->objects.array[i]->color.b = 0x00;
	scene->objects.array[i]->specular = 1000;
	scene->objects.array[i]->reflective = 0.5;
	scene->objects.array[i]->transparency = 0.0;
	scene->objects.array[i]->center.x = 20.0;
	scene->objects.array[i]->center.y = 0.0;
	scene->objects.array[i]->center.z = 40.0;
	scene->objects.array[i]->radius = 12.0;
	i++;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->color.r = 0x00;
	scene->objects.array[i]->color.g = 0x00;
	scene->objects.array[i]->color.b = 0xFF;
	scene->objects.array[i]->specular = 1000;
	scene->objects.array[i]->reflective = 0.5;
	// scene->objects.array[i]->refractive = 1 - scene->objects.array[i]->reflective;
	scene->objects.array[i]->transparency = 0.9;
	scene->objects.array[i]->center.x = -20.0;
	scene->objects.array[i]->center.y = 0.0;
	scene->objects.array[i]->center.z = 40.0;
	scene->objects.array[i]->radius = 8.0;
	i++;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->color.r = 0xFF;
	scene->objects.array[i]->color.g = 0xFF;
	scene->objects.array[i]->color.b = 0xFF;
	scene->objects.array[i]->specular = 1000;
	scene->objects.array[i]->reflective = 0;
	scene->objects.array[i]->center.x = -10.0;
	scene->objects.array[i]->center.y = 15.0;
	scene->objects.array[i]->center.z = 40.0;
	scene->objects.array[i]->radius = 2;
	i++;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->color.r = 0xFF;
	scene->objects.array[i]->color.g = 0x00;
	scene->objects.array[i]->color.b = 0xFF;
	scene->objects.array[i]->specular = 1000;
	scene->objects.array[i]->reflective = 0.5;
	scene->objects.array[i]->transparency = 0.0;
	scene->objects.array[i]->center.x = 0.0;
	scene->objects.array[i]->center.y = 20.0;
	scene->objects.array[i]->center.z = 100.0;
	scene->objects.array[i]->radius = 5.0;
	// i++;
	// scene->objects.array[i]->id = i;
	// scene->objects.array[i]->type = OBJECT_TYPE_CYLINDER;
	// scene->objects.array[i]->color.r = 0xFF;
	// scene->objects.array[i]->color.g = 0xFF;
	// scene->objects.array[i]->color.b = 0x00;
	// scene->objects.array[i]->specular = 0;
	// scene->objects.array[i]->reflective = 0.2;
	// scene->objects.array[i]->center.x = 20.0;
	// scene->objects.array[i]->center.y = -20.0;
	// scene->objects.array[i]->center.z = 0.0;
	// scene->objects.array[i]->radius = 0.5;
	// 	i++;
	// scene->objects.array[i]->id = i;
	// scene->objects.array[i]->type = OBJECT_TYPE_CYLINDER;
	// scene->objects.array[i]->color.r = 0xFF;
	// scene->objects.array[i]->color.g = 0xFF;
	// scene->objects.array[i]->color.b = 0x00;
	// scene->objects.array[i]->specular = 0;
	// scene->objects.array[i]->reflective = 0.2;
	// scene->objects.array[i]->center.x = 20.0;
	// scene->objects.array[i]->center.y = -20.0;
	// scene->objects.array[i]->center.z = 20.0;
	// scene->objects.array[i]->radius = 1;
	// 		i++;
	// scene->objects.array[i]->id = i;
	// scene->objects.array[i]->type = OBJECT_TYPE_CONE;
	// scene->objects.array[i]->color.r = 0xFF;
	// scene->objects.array[i]->color.g = 0x00;
	// scene->objects.array[i]->color.b = 0xFF;
	// scene->objects.array[i]->specular = 0;
	// scene->objects.array[i]->reflective = 0.2;
	// scene->objects.array[i]->center.x = 1.0;
	// scene->objects.array[i]->center.y = 1.0;
	// scene->objects.array[i]->center.z = 1.0;
	// scene->objects.array[i]->center.x = 1.0;
	// scene->objects.array[i]->center.y = 1.0;
	// scene->objects.array[i]->center.z = 1.0;
	// scene->objects.array[i]->k = 0.134;
	// scene->objects.array[i]->radius = 0.1;
	i++;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_PLANE;
	scene->objects.array[i]->color.r = 0x100;
	scene->objects.array[i]->color.g = 0x100;
	scene->objects.array[i]->color.b = 0x100;
	scene->objects.array[i]->specular = 50;
	scene->objects.array[i]->reflective = 0.0;
	scene->objects.array[i]->center.x = 0.0;
	scene->objects.array[i]->center.y = -10.0;
	scene->objects.array[i]->center.z = 0.0;

	scene->light_sources.quantity = 4;
	scene->light_sources.array = (t_light **)ft_memalloc(sizeof(t_light *) * scene->light_sources.quantity);
	i = -1;
	while (++i < scene->light_sources.quantity)
		scene->light_sources.array[i] = (t_light *)ft_memalloc(sizeof(t_light));
	i = 0;
	scene->light_sources.array[i]->type = LIGHT_TYPE_AMBIENT;
	scene->light_sources.array[i]->intensity = 0.2;
	i++;
	scene->light_sources.array[i]->type = LIGHT_TYPE_POINT;
	scene->light_sources.array[i]->intensity = 0.9;
	scene->light_sources.array[i]->position.x = -20;
	scene->light_sources.array[i]->position.y = 20;
	scene->light_sources.array[i]->position.z = 30;
	i++;
	scene->light_sources.array[i]->type = LIGHT_TYPE_POINT;
	scene->light_sources.array[i]->intensity = 0.3;
	scene->light_sources.array[i]->position.x = 20;
	scene->light_sources.array[i]->position.y = 10;
	scene->light_sources.array[i]->position.z = 00;
    i++;
	scene->light_sources.array[i]->type = LIGHT_TYPE_DIRECTIONAL;
	scene->light_sources.array[i]->intensity = 0.2;
	scene->light_sources.array[i]->direction.x = 10;
	scene->light_sources.array[i]->direction.y = 40;
	scene->light_sources.array[i]->direction.z = 40;
}
