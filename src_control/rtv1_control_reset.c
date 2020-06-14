/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_reset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 15:15:10 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/14 16:09:55 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	reset(t_global *global, int key)
{
	if (key == R)
	{
		clean_scene(global->scene);
		read_scene(global->scene, global->scene->file_name_with_path);
		set_initial_status(global->scene);
		get_lights_statistics(global->scene);
		get_objects_statistics(global->scene);
		set_initial_angles(global->scene);
		draw(global);
	}
}

void	clean_scene(t_scene *scene)
{
	int	i;

	free(scene->name);
	free(scene->author);
	i = -1;
	while (++i < scene->cameras.quantity)
		free(scene->cameras.array[i]);
	free(scene->cameras.array);
	i = -1;
	while (++i < scene->lights.quantity)
		free(scene->lights.array[i]);
	free(scene->lights.array);
	i = -1;
	while (++i < scene->materials.quantity)
		free(scene->materials.array[i]);
	free(scene->materials.array);
	i = -1;
	while (++i < scene->objects.quantity)
		free(scene->objects.array[i]);
	free(scene->objects.array);
}
