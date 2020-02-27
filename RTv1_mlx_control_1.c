/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_control_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/27 04:23:50 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	move_camera(t_status *status, int key)
{
	int i;

	i = status->current_camera;
	if (key == ARROW_DOWN)
		status->cameras[i]->position.y -= 5;
	else if (key == ARROW_UP)
		status->cameras[i]->position.y += 5;
	else if (key == ARROW_RIGHT)
		status->cameras[i]->position.x += 5;
	else if (key == ARROW_LEFT)
		status->cameras[i]->position.x -= 5;
	else if (key == PLUS)
		status->cameras[i]->position.z += 5;
	else if (key == MINUS)
		status->cameras[i]->position.z -= 5;
}

void	rotate_camera(t_status *status, int key)
{
	int i;

	i = status->current_camera;
	if (key == W)
		status->cameras[i]->direction.x += 30.0;
	else if (key == S)
		status->cameras[i]->direction.x -= 30.0;
	else if (key == D)
		status->cameras[i]->direction.y += 30.0;
	else if (key == A)
		status->cameras[i]->direction.y -= 30.0;
	else if (key == MORE)
		status->cameras[i]->direction.z += 30.0;
	else if (key == LESS)
		status->cameras[i]->direction.z -= 30.0;
}

void	move_object(t_status *status, int key)
{
	int i;

	i = status->active_object;
	if (key == ARROW_DOWN)
		status->spheres.array[i]->center.y -= 5;
	else if (key == ARROW_UP)
		status->spheres.array[i]->center.y += 5;
	else if (key == ARROW_RIGHT)
		status->spheres.array[i]->center.x += 5;
	else if (key == ARROW_LEFT)
		status->spheres.array[i]->center.x -= 5;
	else if (key == PLUS)
		status->spheres.array[i]->center.z += 5;
	else if (key == MINUS)
		status->spheres.array[i]->center.z -= 5;
}

// void	rotate_object(t_status *status, int key)
// {
// 	int i;

// 	i = status->current_camera;
// 	if (key == W)
// 		status->cameras[i]->direction.x += 30.0;
// 	else if (key == S)
// 		status->cameras[i]->direction.x -= 30.0;
// 	else if (key == D)
// 		status->cameras[i]->direction.y += 30.0;
// 	else if (key == A)
// 		status->cameras[i]->direction.y -= 30.0;
// 	else if (key == MORE)
// 		status->cameras[i]->direction.z += 30.0;
// 	else if (key == LESS)
// 		status->cameras[i]->direction.z -= 30.0;
// }
