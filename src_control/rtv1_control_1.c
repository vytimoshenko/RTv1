/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 13:25:06 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

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
	else if (key == PAGE_UP)
		scene->cameras.array[i]->position.z += CAMERA_MOVEMENT_INCREMENT;
	else if (key == PAGE_DOWN)
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
	else if (key == MORE)
		scene->cameras.array[i]->direction.z += CAMERA_ROTATION_INCREMENT;
	else if (key == LESS)
		scene->cameras.array[i]->direction.z -= CAMERA_ROTATION_INCREMENT;
	get_sin_cos(scene->cameras.array[i]);
}

void	move_object(t_scene *scene, int key)
{
	int i;

	i = scene->active_object;
	if (key == ARROW_DOWN)
		scene->objects.array[i]->position.y -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		scene->objects.array[i]->position.y += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		scene->objects.array[i]->position.x += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		scene->objects.array[i]->position.x -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == PAGE_UP)
		scene->objects.array[i]->position.z += OBJECT_MOVEMENT_INCREMENT;
	else if (key == PAGE_DOWN)
		scene->objects.array[i]->position.z -= OBJECT_MOVEMENT_INCREMENT;
}

void	rotate_object(t_scene *scene, int key)
{
	int i;

	i = scene->active_object;
	if (key == W)
		scene->objects.array[i]->orientation.y += OBJECT_ROTATION_INCREMENT;
	else if (key == S)
		scene->objects.array[i]->orientation.y -= OBJECT_ROTATION_INCREMENT;
	else if (key == D)
		scene->objects.array[i]->orientation.x += OBJECT_ROTATION_INCREMENT;
	else if (key == A)
		scene->objects.array[i]->orientation.x -= OBJECT_ROTATION_INCREMENT;
	else if (key == MORE)
		scene->objects.array[i]->orientation.z += OBJECT_ROTATION_INCREMENT;
	else if (key == LESS)
		scene->objects.array[i]->orientation.z -= OBJECT_ROTATION_INCREMENT;
}
