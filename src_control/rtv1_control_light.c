/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 00:33:55 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/28 21:26:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	change_light(t_scene *scene, int key)
{
	if (key == MORE && scene->active_light != scene->lights.quantity - 1)
		scene->active_light++;
	else if (key == MORE && scene->active_light == scene->lights.quantity - 1)
		scene->active_light = 0;
	else if (key == LESS && scene->active_light != 0)
		scene->active_light--;
	else if (key == LESS && scene->active_light == 0)
		scene->active_light = scene->lights.quantity - 1;
}

void	move_light(t_scene *scene, int key)
{
	int i;

	i = scene->active_light;
	if (key == ARROW_DOWN)
		scene->lights.array[i]->position.y -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_UP)
		scene->lights.array[i]->position.y += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_RIGHT)
		scene->lights.array[i]->position.x += OBJECT_MOVEMENT_INCREMENT;
	else if (key == ARROW_LEFT)
		scene->lights.array[i]->position.x -= OBJECT_MOVEMENT_INCREMENT;
	else if (key == BRACKET_RIGHT)
		scene->lights.array[i]->position.z += OBJECT_MOVEMENT_INCREMENT;
	else if (key == BRACKET_LEFT)
		scene->lights.array[i]->position.z -= OBJECT_MOVEMENT_INCREMENT;
}

void	rotate_light(t_scene *scene, int key)
{
	int i;

	i = scene->active_light;
	if (key == W)
		scene->lights.array[i]->direction.y += OBJECT_ROTATION_INCREMENT;
	else if (key == S)
		scene->lights.array[i]->direction.y -= OBJECT_ROTATION_INCREMENT;
	else if (key == D)
		scene->lights.array[i]->direction.x += OBJECT_ROTATION_INCREMENT;
	else if (key == A)
		scene->lights.array[i]->direction.x -= OBJECT_ROTATION_INCREMENT;
	else if (key == Z)
		scene->lights.array[i]->direction.z += OBJECT_ROTATION_INCREMENT;
	else if (key == X)
		scene->lights.array[i]->direction.z -= OBJECT_ROTATION_INCREMENT;
}

void	change_light_intensity(t_scene *scene, int key)
{
	int i;

	i = scene->active_light;
	if (key == MINUS && scene->lights.array[i]->intensity >=
	LIGHT_INTENSITY_MIN + LIGHT_INTENSITY_INCREMENT)
		scene->lights.array[i]->intensity -= LIGHT_INTENSITY_INCREMENT;
	else if (key == PLUS && scene->lights.array[i]->intensity <
	LIGHT_INTENSITY_MAX)
		scene->lights.array[i]->intensity += LIGHT_INTENSITY_INCREMENT;
	if (key == B && scene->lights.array[i]->off == TRUE)
		scene->lights.array[i]->off = FALSE;
	else if (key == B && scene->lights.array[i]->off == FALSE)
		scene->lights.array[i]->off = TRUE;
}
