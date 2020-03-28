/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_reset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 15:15:10 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/28 21:26:53 by mperseus         ###   ########.fr       */
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
		get_sin_cos(global->scene->cameras.array[global->scene->active_camera]);
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
