/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_start_scene_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:29:21 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:52:56 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

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
	init_pixel_buffer(scene);
	set_initial_angles(scene);
	scene->file_name_with_path = ft_strdup(argv[1]);
	return (scene);
}

void	set_initial_status(t_scene *scene)
{
	scene->act_mod = MODE_CAMERA;
	scene->k_cartoon = CARTOON_INIT;
	scene->k_pixelation = PIXELATION_INIT;
	scene->k_depth_map = DEPTH_MAP_INIT;
	scene->act_cam = 0;
	scene->act_mat = 0;
	scene->act_obj = 0;
	scene->mat_source = NOTHING_SELECTED;
}

void	get_lights_statistics(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->lights.quant)
	{
		if (scene->lights.arr[i]->type == LIGHT_TYPE_AMBIENT)
			scene->lights.quant_ambient++;
		if (scene->lights.arr[i]->type == LIGHT_TYPE_DIRECTIONAL)
			scene->lights.quant_directional++;
		if (scene->lights.arr[i]->type == LIGHT_TYPE_POINT)
			scene->lights.quant_point++;
	}
}

void	get_objects_statistics(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < scene->objs.quant)
	{
		if (scene->objs.arr[i]->type == OBJECT_TYPE_PLANE)
			scene->objs.quant_planes++;
		if (scene->objs.arr[i]->type == OBJECT_TYPE_SPHERE)
			scene->objs.quant_spheres++;
		if (scene->objs.arr[i]->type == OBJECT_TYPE_CYLINDER)
			scene->objs.quant_cylinders++;
		if (scene->objs.arr[i]->type == OBJECT_TYPE_CONE)
			scene->objs.quant_cones++;
	}
}

void	set_initial_angles(t_scene *scene)
{
	int i;

	get_sin_cos(scene->cams.arr[scene->act_cam]);
	i = 0;
	while (i < scene->objs.quant)
	{
		if (scene->objs.arr[i]->type == OBJECT_TYPE_CYLINDER ||
		scene->objs.arr[i]->type == OBJECT_TYPE_CONE)
		{
			get_sin_cos_obj(scene->objs.arr[i]);
			rotate_vector(scene->objs.arr[i]);
		}
		i++;
	}
}
