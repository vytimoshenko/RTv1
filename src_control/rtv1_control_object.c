/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 16:51:34 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/28 21:26:47 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

int		select_object(int x, int y, t_global *global)
{
	int	i;
	int object_id;

	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return (-1);
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	object_id = global->scene->pixel_buffer[i].object_id;
    if (object_id == NOTHING_SELECTED)
    {
		global->scene->active_mode = MODE_CAMERA;
		global->scene->active_object = NOTHING_SELECTED;
		return (1);
    }
	global->scene->active_mode = MODE_OBJECT;
	if (global->scene->active_object == object_id)
		return (0);
	else
	{
		global->scene->active_object = object_id;
		return (1);
	}
}

void	change_object(t_scene *scene, int key)
{
	if (key == MORE && scene->active_object != scene->objects.quantity - 1)
		scene->active_object++;
	else if (key == MORE && scene->active_object == scene->objects.quantity - 1)
		scene->active_object = 0;
	else if (key == LESS && scene->active_object != 0)
		scene->active_object--;
	else if (key == LESS && scene->active_object == 0)
		scene->active_object = scene->objects.quantity - 1;
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
	else if (key == BRACKET_RIGHT)
		scene->objects.array[i]->position.z += OBJECT_MOVEMENT_INCREMENT;
	else if (key == BRACKET_LEFT)
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
	else if (key == Z)
		scene->objects.array[i]->orientation.z += OBJECT_ROTATION_INCREMENT;
	else if (key == X)
		scene->objects.array[i]->orientation.z -= OBJECT_ROTATION_INCREMENT;
}
