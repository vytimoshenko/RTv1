/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 16:51:34 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/14 18:38:06 by vitaly           ###   ########.fr       */
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
	t_vector dir;

	dir = scene->objects.array[scene->active_object]->orientation;
	if (key == W)
		dir.y += OBJECT_ROTATION_INCREMENT;
	else if (key == S)
		dir.y -= OBJECT_ROTATION_INCREMENT;
	else if (key == D)
		dir.x += OBJECT_ROTATION_INCREMENT;
	else if (key == A)
		dir.x -= OBJECT_ROTATION_INCREMENT;
	else if (key == Z)
		dir.z += OBJECT_ROTATION_INCREMENT;
	else if (key == X)
		dir.z -= OBJECT_ROTATION_INCREMENT;
	dir.x = dir.x >= 360 ? dir.x - 360 : dir.x;
	dir.y = dir.y >= 360 ? dir.x - 360 : dir.y;
	dir.z = dir.z >= 360 ? dir.x - 360 : dir.z;
	dir.x = dir.x <= -360 ? dir.x + 360 : dir.x;
	dir.y = dir.y <= -360 ? dir.x + 360 : dir.y;
	dir.z = dir.z <= -360 ? dir.x + 360 : dir.z;
	scene->objects.array[scene->active_object]->orientation = dir;
	get_sin_cos_obj(scene->objects.array[scene->active_object]);
	rotate_vector(scene->objects.array[scene->active_object]);
}

void	get_sin_cos_obj(t_object *object)
{
	object->sin.x = sin(deg_to_rad(object->orientation.x));
	object->sin.y = sin(deg_to_rad(object->orientation.y));
	object->sin.z = sin(deg_to_rad(object->orientation.z));
	object->cos.x = cos(deg_to_rad(object->orientation.x));
	object->cos.y = cos(deg_to_rad(object->orientation.y));
	object->cos.z = cos(deg_to_rad(object->orientation.z));
}

void	rotate_vector(t_object *object)
{
	double		temp1;
	double		temp2;
	t_vector	position;

	position = object->position;
	temp1 = position.y * object->cos.x + position.z * object->sin.x;
	temp2 = -position.y * object->sin.x + position.z * object->cos.x;
	object->direction.y = temp1;
	object->direction.z = temp2;
	temp1 = position.x * object->cos.y + position.z * object->sin.y;
	temp2 = -position.x * object->sin.y + position.z * object->cos.y;
	object->direction.x = temp1;
	object->direction.z = temp2;
	temp1 = position.x * object->cos.z - position.y * object->sin.z;
	temp2 = position.x * object->sin.z + position.y * object->cos.z;
	object->direction.x = temp1;
	object->direction.y = temp2;
	object->direction = normalize(object->direction);
}
