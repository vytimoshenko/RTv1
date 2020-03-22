/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:28:16 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/22 18:24:54 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	change_camera(t_scene *scene, int key)
{
	if (key == MORE && scene->active_camera != scene->cameras.quantity - 1)
		scene->active_camera++;
	else if (key == MORE && scene->active_camera == scene->cameras.quantity - 1)
		scene->active_camera = 0;
	else if (key == LESS && scene->active_camera != 0)
		scene->active_camera--;
	else if (key == LESS && scene->active_camera == 0)
		scene->active_camera = scene->cameras.quantity - 1;
    get_sin_cos(scene->cameras.array[scene->active_camera]);
}

void	move_camera(t_scene *scene, int key)
{
	int i;

	i = scene->active_camera;
	if (key == ARROW_DOWN)
		scene->cameras.array[i]->position.y -= CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		scene->cameras.array[i]->position.y += CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		scene->cameras.array[i]->position.x += CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		scene->cameras.array[i]->position.x -= CAMERA_MOVEMENT_INCREMENT;
	else if (key == BRACKET_RIGHT)
		scene->cameras.array[i]->position.z += CAMERA_MOVEMENT_INCREMENT;
	else if (key == BRACKET_LEFT)
		scene->cameras.array[i]->position.z -= CAMERA_MOVEMENT_INCREMENT;
}

void	rotate_camera(t_scene *scene, int key)
{
	int i;

	i = scene->active_camera;
	if (key == W)
		scene->cameras.array[i]->direction.x += CAMERA_ROTATION_INCREMENT;
	else if (key == S)
		scene->cameras.array[i]->direction.x -= CAMERA_ROTATION_INCREMENT;
	else if (key == D)
		scene->cameras.array[i]->direction.y += CAMERA_ROTATION_INCREMENT;
	else if (key == A)
		scene->cameras.array[i]->direction.y -= CAMERA_ROTATION_INCREMENT;
	else if (key == Z)
		scene->cameras.array[i]->direction.z += CAMERA_ROTATION_INCREMENT;
	else if (key == X)
		scene->cameras.array[i]->direction.z -= CAMERA_ROTATION_INCREMENT;
	get_sin_cos(scene->cameras.array[i]);
}
