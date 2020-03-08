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
	init_motion_blur_buffer(scene);
	init_depth_buffer(scene);
	init_aliasing_buffer(scene);
	init_object_buffer(scene);
	get_sin_cos(scene->cameras.array[scene->active_camera]);
	scene->file_name_with_path = ft_strdup(argv[1]);
	return (scene);
}

// void	check_scene(t_scene *scene)
// {
	
// }

// void	read_scene(t_scene *scene)
// {

// }

void		reset_scene(t_scene *scene)
{
	int	i;

	scene->pixelation_k = PIXELATION_MIN;
	scene->pixelation_k = 256;
	scene->active_object = -1;
	scene->scene_name = ft_strdup("Four amazing balls");
	scene->background = (t_color){0, 0, 0};
	scene->active_light = NOTHING_SELECTED;
	scene->active_object = NOTHING_SELECTED;
	scene->material_source = NOTHING_SELECTED;
	scene->active_camera = 0;
	scene->depth_map_k = 64;

	scene->cameras.quantity = 4;
	scene->cameras.array = (t_camera **)ft_memalloc(sizeof(t_camera *) * scene->cameras.quantity);
	i = -1;
	while (++i < scene->cameras.quantity)
		scene->cameras.array[i] = (t_camera *)ft_memalloc(sizeof(t_camera));
	i = 0;
	scene->cameras.array[i]->position = (t_vector){0, 0, -10};
	scene->cameras.array[i]->direction = (t_vector){0, 0, 0};
	scene->cameras.array[i]->zoom = 1.0;
	i++;
	scene->cameras.array[i]->position = (t_vector){20, 10, -80};
	scene->cameras.array[i]->direction = (t_vector){0, 0, 0};
	scene->cameras.array[i]->zoom = 1.0;
	i++;
	scene->cameras.array[i]->position = (t_vector){0, 100, 30};
	scene->cameras.array[i]->direction = (t_vector){-90, 0, 0};
	scene->cameras.array[i]->zoom = 1.0;
		i++;
	scene->cameras.array[i]->position = (t_vector){0, 100, 30};
	scene->cameras.array[i]->direction = (t_vector){0, -75, 0};
	scene->cameras.array[i]->zoom = 1.0;

	scene->objects.quantity = 6;
	scene->objects.array = (t_object **)ft_memalloc(sizeof(t_object *) * scene->objects.quantity);
	i = -1;
	while (++i < scene->objects.quantity)
		scene->objects.array[i] = (t_object *)ft_memalloc(sizeof(t_object));
	i = 0;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->material = i;
	scene->objects.array[i]->center.x = 0.0;
	scene->objects.array[i]->center.y = -10.0;
	scene->objects.array[i]->center.z = 30.0;
	scene->objects.array[i]->radius = 10.0;
	i++;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->material = i;
	scene->objects.array[i]->center.x = 20.0;
	scene->objects.array[i]->center.y = 0.0;
	scene->objects.array[i]->center.z = 40.0;
	scene->objects.array[i]->radius = 12.0;
	i++;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->material = i;
	scene->objects.array[i]->transparency = 0.9;
	scene->objects.array[i]->center.x = -20.0;
	scene->objects.array[i]->center.y = 0.0;
	scene->objects.array[i]->center.z = 40.0;
	scene->objects.array[i]->radius = 8.0;
	i++;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->material = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->center.x = -10.0;
	scene->objects.array[i]->center.y = 15.0;
	scene->objects.array[i]->center.z = 40.0;
	scene->objects.array[i]->radius = 2;
	i++;
	scene->objects.array[i]->id = i;
	scene->objects.array[i]->type = OBJECT_TYPE_SPHERE;
	scene->objects.array[i]->material = i;
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
	scene->objects.array[i]->material = i;
	scene->objects.array[i]->center.x = 0.0;
	scene->objects.array[i]->center.y = -10.0;
	scene->objects.array[i]->center.z = 0.0;

	scene->lights.quantity = 4;
	scene->lights.quantity_ambient = 1;
	scene->lights.quantity_directional = 1;
	scene->lights.quantity_point = 2;
	scene->lights.array = (t_light **)ft_memalloc(sizeof(t_light *) * scene->lights.quantity);
	i = -1;
	while (++i < scene->lights.quantity)
		scene->lights.array[i] = (t_light *)ft_memalloc(sizeof(t_light));
	i = 0;
	scene->lights.array[i]->type = LIGHT_TYPE_AMBIENT;
	scene->lights.array[i]->intensity = 0.1;
	i++;
	scene->lights.array[i]->type = LIGHT_TYPE_POINT;
	scene->lights.array[i]->intensity = 0.5;
	scene->lights.array[i]->position = (t_vector){-20, 20, 30};
	i++;
	scene->lights.array[i]->type = LIGHT_TYPE_POINT;
	scene->lights.array[i]->intensity = 0.4;
	scene->lights.array[i]->position = (t_vector){20, 9, 0};
    i++;
	scene->lights.array[i]->type = LIGHT_TYPE_DIRECTIONAL;
	scene->lights.array[i]->intensity = 0.1;
	scene->lights.array[i]->position = (t_vector){10, 40, 40};

	scene->materials.quantity = 6;
	scene->materials.array = (t_material **)ft_memalloc(sizeof(t_material *) * scene->materials.quantity);
	i = -1;
	while (++i < scene->materials.quantity)
		scene->materials.array[i] = (t_material *)ft_memalloc(sizeof(t_material));
	i = 0;
	scene->materials.array[i]->id = i;
	scene->materials.array[i]->name = ft_strdup("Shiny red");
	scene->materials.array[i]->color = (t_color){0xFF, 0x00, 0x00};
	scene->materials.array[i]->specular = 1000;
	scene->materials.array[i]->reflective = 0.5;
	scene->materials.array[i]->transparency = 0.0;
	i++;
	scene->materials.array[i]->id = i;
	scene->materials.array[i]->name = ft_strdup("Matte green");
	scene->materials.array[i]->color = (t_color){0x00, 0xFF, 0x00};
	scene->materials.array[i]->specular = 100;
	scene->materials.array[i]->reflective = 0.1;
	scene->materials.array[i]->transparency = 0.0;
	i++;
	scene->materials.array[i]->id = i;
	scene->materials.array[i]->name = ft_strdup("Super blue");
	scene->materials.array[i]->color = (t_color){0x00, 0x00, 0xFF};
	scene->materials.array[i]->specular = 1000;
	scene->materials.array[i]->reflective = 0.5;
	scene->materials.array[i]->transparency = 0.9;
	i++;
	scene->materials.array[i]->id = i;
	scene->materials.array[i]->color = (t_color){0xFF, 0xFF, 0xFF};
	scene->materials.array[i]->name = ft_strdup("Glossy white");
	scene->materials.array[i]->specular = 1000;
	scene->materials.array[i]->reflective = 0;
	scene->materials.array[i]->transparency = 0.0;
	i++;
	scene->materials.array[i]->id = i;
	scene->materials.array[i]->name = ft_strdup("Deep magenta");
	scene->materials.array[i]->color = (t_color){0xFF, 0x00, 0xFF};
	scene->materials.array[i]->specular = 1000;
	scene->materials.array[i]->reflective = 0.5;
	scene->materials.array[i]->transparency = 0.0;
	i++;
	scene->materials.array[i]->id = i;
	scene->materials.array[i]->name = ft_strdup("Light gray");
	scene->materials.array[i]->color = (t_color){0x100, 0x100, 0x100};
	scene->materials.array[i]->specular = 50;
	scene->materials.array[i]->reflective = 0.0;
	scene->materials.array[i]->transparency = 0.0;
}
