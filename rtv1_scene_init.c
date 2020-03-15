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
	
	if (argc != 2)
		ft_put_error("usage: RTv1 scene_name.rt");
	if (!(scene = (t_scene *)ft_memalloc(sizeof(t_scene))))
		ft_put_errno(PROGRAM_NAME);
	read_scene(scene, argv[1]);
	set_initial_status(scene);
	get_lights_statistics(scene);
	get_objects_statistics(scene);
	init_frame_buffer(scene);
	init_motion_blur_buffer(scene);
	init_depth_buffer(scene);
	init_aliasing_buffer(scene);
	init_object_buffer(scene);
	get_sin_cos(scene->cameras.array[scene->active_camera]);
	scene->file_name_with_path = ft_strdup(argv[1]);
	return (scene);
}

void	set_initial_status(t_scene *scene)
{
	scene->background = (t_color){0, 0, 0};
	scene->depth_map_k = 64;
	scene->pixelation_k = PIXELATION_MIN;
	scene->pixelation_k = 256;
	scene->active_camera = 0;
	scene->active_light = NOTHING_SELECTED;
	scene->active_material = NOTHING_SELECTED;
	scene->active_object = NOTHING_SELECTED;
	scene->material_source = NOTHING_SELECTED;
}

void	get_lights_statistics(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->lights.quantity)
	{
		if (scene->lights.array[i]->type == LIGHT_TYPE_AMBIENT)
			scene->lights.quantity_ambient++;
		if (scene->lights.array[i]->type == LIGHT_TYPE_DIRECTIONAL)
			scene->lights.quantity_directional++;
		if (scene->lights.array[i]->type == LIGHT_TYPE_POINT)
			scene->lights.quantity_point++;
	}
}

void	get_objects_statistics(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->objects.quantity)
	{
		if (scene->objects.array[i]->type == OBJECT_TYPE_PLANE)
			scene->objects.quantity_planes++;
		if (scene->objects.array[i]->type == OBJECT_TYPE_SPHERE)
			scene->objects.quantity_spheres++;
		if (scene->objects.array[i]->type == OBJECT_TYPE_CYLINDER)
			scene->objects.quantity_cylinders++;
		if (scene->objects.array[i]->type == OBJECT_TYPE_CONE)
			scene->objects.quantity_cones++;
	}
}
