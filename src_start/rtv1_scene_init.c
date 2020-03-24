/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_scene_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:29:21 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/24 15:47:19 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_scene	*init_scene(int argc, char **argv)
{
	t_scene		*scene;

	if (argc != 2)
		ft_put_error("usage: RTv1 scene_name.rt");
	if (!(scene = (t_scene *)ft_memalloc(sizeof(t_scene))))
		ft_put_errno(PROGRAM_NAME);
	scene->name = NULL;
	scene->author = NULL;
	read_scene(scene, argv[1]);
	if (!scene->name || !scene->author)
		put_error_pn("scene must contain scene name and author info");
	set_initial_status(scene);
	get_lights_statistics(scene);
	get_objects_statistics(scene);
	init_frame_buffer(scene);
	init_depth_buffers(scene);
	init_aliasing_buffer(scene);
	init_object_buffers(scene);
	init_anaglyph_buffers(scene);
	get_sin_cos(scene->cameras.array[scene->active_camera]);
	scene->file_name_with_path = ft_strdup(argv[1]);
	return (scene);
}

void	set_initial_status(t_scene *scene)
{
	scene->background = (t_color){0, 0, 0};
	scene->k_cartoon = CARTOON_INIT;
	scene->k_pixelation = PIXELATION_INIT;
	scene->k_depth_map = DEPTH_MAP_INIT;
	scene->active_camera = 0;
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
