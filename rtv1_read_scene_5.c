/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:09:49 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/13 07:33:08 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	parse_object_description(t_scene *scene, char *property, char *value)
{
	int i;

	i = scene->active_object;
	scene->objects.array[i]->id = i;
	if (!(ft_strcmp(property, FILE_OBJECT_TYPE)))
		scene->objects.array[i]->type = find_object_type(value);
	else if (!(ft_strcmp(property, FILE_OBJECT_MATERIAL)))
		scene->objects.array[i]->material = find_object_material(scene, value);
	else if (!(ft_strcmp(property, FILE_OBJECT_POSITION)))
		scene->objects.array[i]->position = parse_vector(value);
	else if (!(ft_strcmp(property, FILE_OBJECT_ORIENTATION)))
		scene->objects.array[i]->orientation = parse_vector(value);
	else if (!(ft_strcmp(property, FILE_OBJECT_RADIUS)))
		scene->objects.array[i]->radius = ft_atoi(value);
	else
		return (-1);
	return (0);
}

int	find_object_type(char *value)
{
	if (!(ft_strcmp(value, FILE_OBJECT_TYPE_PLANE)))
		return (OBJECT_TYPE_PLANE);
	else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_SPHERE)))
		return (OBJECT_TYPE_SPHERE);
	else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_CYLINDER)))
		return (OBJECT_TYPE_CYLINDER);
	else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_CONE)))
		return (OBJECT_TYPE_CONE);
	return (-1);
}

int	find_object_material(t_scene *scene, char *value)
{
	int	i;

	i = -1;
	while (++i < scene->materials.quantity)
	{
		if (!(ft_strcmp(scene->materials.array[i]->name, value)))
			return (i);
	}
	return (-1);
}
