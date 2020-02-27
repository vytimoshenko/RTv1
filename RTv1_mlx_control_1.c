/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_control_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 01:47:36 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	move_camera(t_status *status, int key)
{
	int i;

	i = status->current_camera;
	if (key == ARROW_DOWN)
		status->cameras[i]->position.y -= CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		status->cameras[i]->position.y += CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		status->cameras[i]->position.x += CAMERA_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		status->cameras[i]->position.x -= CAMERA_MOVEMENT_INCREMENT;
	else if (key == PLUS)
		status->cameras[i]->position.z += CAMERA_MOVEMENT_INCREMENT;
	else if (key == MINUS)
		status->cameras[i]->position.z -= CAMERA_MOVEMENT_INCREMENT;
}

void	rotate_camera(t_status *status, int key)
{
	int i;

	i = status->current_camera;
	if (key == W)
		status->cameras[i]->direction.x += CAMERA_ROTATION_INCREMENT;
	else if (key == S)
		status->cameras[i]->direction.x -= CAMERA_ROTATION_INCREMENT;
	else if (key == D)
		status->cameras[i]->direction.y += CAMERA_ROTATION_INCREMENT;
	else if (key == A)
		status->cameras[i]->direction.y -= CAMERA_ROTATION_INCREMENT;
	else if (key == MORE)
		status->cameras[i]->direction.z += CAMERA_ROTATION_INCREMENT;
	else if (key == LESS)
		status->cameras[i]->direction.z -= CAMERA_ROTATION_INCREMENT;
}

void	move_object(t_status *status, int key)
{
	int i;

	i = status->active_object;
	if (key == ARROW_DOWN)
		status->spheres.array[i]->center.y -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		status->spheres.array[i]->center.y += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		status->spheres.array[i]->center.x += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		status->spheres.array[i]->center.x -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == PLUS)
		status->spheres.array[i]->center.z += OBJECT_MOVEMENT_INCREMENT;
	else if (key == MINUS)
		status->spheres.array[i]->center.z -= OBJECT_MOVEMENT_INCREMENT;
}

// void	rotate_object(t_status *status, int key)
// {
// 	int i;

// 	i = status->current_camera;
// 	if (key == W)
// 		status->cameras[i]->direction.x += OBJECT_ROTATION_INCREMENT;
// 	else if (key == S)
// 		status->cameras[i]->direction.x -= OBJECT_ROTATION_INCREMENT;
// 	else if (key == D)
// 		status->cameras[i]->direction.y += OBJECT_ROTATION_INCREMENT;
// 	else if (key == A)
// 		status->cameras[i]->direction.y -= OBJECT_ROTATION_INCREMENT;
// 	else if (key == MORE)
// 		status->cameras[i]->direction.z += OBJECT_ROTATION_INCREMENT;
// 	else if (key == LESS)
// 		status->cameras[i]->direction.z -= OBJECT_ROTATION_INCREMENT;
// }
