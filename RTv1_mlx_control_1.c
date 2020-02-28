/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_control_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 03:36:18 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	move_camera(t_scene *scene, int key)
{
	int i;

	i = scene->current_camera;
	if (key == ARROW_DOWN)
		scene->cameras[i]->position.y -= CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		scene->cameras[i]->position.y += CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		scene->cameras[i]->position.x += CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		scene->cameras[i]->position.x -= CAMERA_MOVEMENT_INCREMENT;
	else if (key == PLUS)
		scene->cameras[i]->position.z += CAMERA_MOVEMENT_INCREMENT;
	else if (key == MINUS)
		scene->cameras[i]->position.z -= CAMERA_MOVEMENT_INCREMENT;
}

void	rotate_camera(t_scene *scene, int key)
{
	int i;

	i = scene->current_camera;
	if (key == W)
		scene->cameras[i]->direction.x += CAMERA_ROTATION_INCREMENT;
	else if (key == S)
		scene->cameras[i]->direction.x -= CAMERA_ROTATION_INCREMENT;
	else if (key == D)
		scene->cameras[i]->direction.y += CAMERA_ROTATION_INCREMENT;
	else if (key == A)
		scene->cameras[i]->direction.y -= CAMERA_ROTATION_INCREMENT;
	else if (key == MORE)
		scene->cameras[i]->direction.z += CAMERA_ROTATION_INCREMENT;
	else if (key == LESS)
		scene->cameras[i]->direction.z -= CAMERA_ROTATION_INCREMENT;
}

void	move_object(t_scene *scene, int key)
{
	int i;

	i = scene->active_object;
	if (key == ARROW_DOWN)
		scene->spheres.array[i]->center.y -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		scene->spheres.array[i]->center.y += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		scene->spheres.array[i]->center.x += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		scene->spheres.array[i]->center.x -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == PLUS)
		scene->spheres.array[i]->center.z += OBJECT_MOVEMENT_INCREMENT;
	else if (key == MINUS)
		scene->spheres.array[i]->center.z -= OBJECT_MOVEMENT_INCREMENT;
}

// void	rotate_object(t_scene *scene, int key)
// {
// 	int i;

// 	i = scene->current_camera;
// 	if (key == W)
// 		scene->cameras[i]->direction.x += OBJECT_ROTATION_INCREMENT;
// 	else if (key == S)
// 		scene->cameras[i]->direction.x -= OBJECT_ROTATION_INCREMENT;
// 	else if (key == D)
// 		scene->cameras[i]->direction.y += OBJECT_ROTATION_INCREMENT;
// 	else if (key == A)
// 		scene->cameras[i]->direction.y -= OBJECT_ROTATION_INCREMENT;
// 	else if (key == MORE)
// 		scene->cameras[i]->direction.z += OBJECT_ROTATION_INCREMENT;
// 	else if (key == LESS)
// 		scene->cameras[i]->direction.z -= OBJECT_ROTATION_INCREMENT;
// }
