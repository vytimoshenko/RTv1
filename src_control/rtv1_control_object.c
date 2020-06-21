/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 16:51:34 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 19:12:38 by vitaly           ###   ########.fr       */
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
	object_id = global->scene->pix_buff[i].obj_id;
	if (object_id == NOTHING_SELECTED)
	{
		global->scene->act_mod = MODE_CAMERA;
		global->scene->act_obj = NOTHING_SELECTED;
		return (1);
	}
	global->scene->act_mod = MODE_OBJECT;
	if (global->scene->act_obj == object_id)
		return (0);
	else
	{
		global->scene->act_obj = object_id;
		return (1);
	}
}

void	change_object(t_scene *scene, int key)
{
	if (key == MORE && scene->act_obj != scene->objs.quant - 1)
		scene->act_obj++;
	else if (key == MORE && scene->act_obj == scene->objs.quant - 1)
		scene->act_obj = 0;
	else if (key == LESS && scene->act_obj != 0)
		scene->act_obj--;
	else if (key == LESS && scene->act_obj == 0)
		scene->act_obj = scene->objs.quant - 1;
}

void	move_object(t_scene *scene, int key)
{
	int i;

	i = scene->act_obj;
	if (key == ARROW_DOWN)
		scene->objs.arr[i]->pos.y -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		scene->objs.arr[i]->pos.y += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		scene->objs.arr[i]->pos.x += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		scene->objs.arr[i]->pos.x -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == BRACKET_RIGHT)
		scene->objs.arr[i]->pos.z += OBJECT_MOVEMENT_INCREMENT;
	else if (key == BRACKET_LEFT)
		scene->objs.arr[i]->pos.z -= OBJECT_MOVEMENT_INCREMENT;
}

void	rotate_object(t_scene *scene, int key)
{
	t_vec dir;

	dir = scene->objs.arr[scene->act_obj]->dir;
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
	scene->objs.arr[scene->act_obj]->dir = dir;
	get_sin_cos_obj(scene->objs.arr[scene->act_obj]);
	rotate_vector(scene->objs.arr[scene->act_obj]);
}

void	get_sin_cos_obj(t_obj *object)
{
	object->sin.x = sin(deg_to_rad(object->dir.x));
	object->sin.y = sin(deg_to_rad(object->dir.y));
	object->sin.z = sin(deg_to_rad(object->dir.z));
	object->cos.x = cos(deg_to_rad(object->dir.x));
	object->cos.y = cos(deg_to_rad(object->dir.y));
	object->cos.z = cos(deg_to_rad(object->dir.z));
}

void	rotate_vector(t_obj *object)
{
	double		temp1;
	double		temp2;
	t_vec		pos;

	pos = object->pos;
	temp1 = pos.y * object->cos.x + pos.z * object->sin.x;
	temp2 = -pos.y * object->sin.x + pos.z * object->cos.x;
	object->dir.y = temp1;
	object->dir.z = temp2;
	temp1 = pos.x * object->cos.y + pos.z * object->sin.y;
	temp2 = -pos.x * object->sin.y + pos.z * object->cos.y;
	object->dir.x = temp1;
	object->dir.z = temp2;
	temp1 = pos.x * object->cos.z - pos.y * object->sin.z;
	temp2 = pos.x * object->sin.z + pos.y * object->cos.z;
	object->dir.x = temp1;
	object->dir.y = temp2;
	object->dir = nrm(object->dir);
}
