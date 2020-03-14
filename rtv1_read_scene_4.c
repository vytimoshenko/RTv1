/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:00:27 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/13 07:38:25 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		parse_item_by_property(t_scene *scene, int type_id, char *property,
		char *value)
{
	if (type_id == FILE_PARSE_SCENE)
		return (parse_scene_description(scene, property, value));
	else if (type_id == FILE_PARSE_CAMERA)
		return (parse_camera_description(scene, property, value));
	else if (type_id == FILE_PARSE_LIGHT)
		return (parse_light_description(scene, property, value));
	else if (type_id == FILE_PARSE_MATERIAL)
		return (parse_material_description(scene, property, value));
	else if (type_id == FILE_PARSE_OBJECT)
		return (parse_object_description(scene, property, value));
	else
		return (-1);
	return (0);
}

int		parse_scene_description(t_scene *scene, char *property, char *value)
{
	if (!(ft_strcmp(property, FILE_SCENE_NAME)))
		scene->name = ft_strdup(value);
	else if (!(ft_strcmp(property, FILE_SCENE_AUTHOR)))
		scene->author = ft_strdup(value);
	else
		return (-1);
	return (0);
}

int		parse_camera_description(t_scene *scene, char *property, char *value)
{
	int i;

	i = scene->active_camera;
	if (!(ft_strcmp(property, FILE_CAMERA_POSITION)))
		scene->cameras.array[i]->position = parse_vector(value);
	else if (!(ft_strcmp(property, FILE_CAMERA_DIRECTION)))
		scene->cameras.array[i]->direction = parse_vector(value);
	else
		return (-1);
	return (0);
}

int		parse_light_description(t_scene *scene, char *property, char *value)
{
	int i;

	i = scene->active_light;
	if (!(ft_strcmp(property, FILE_LIGHT_TYPE)))
	{
		if (!(ft_strcmp(value, FILE_LIGHT_TYPE_AMBIENT)))
			scene->lights.array[i]->type = LIGHT_TYPE_AMBIENT;
		else if (!(ft_strcmp(value, FILE_LIGHT_TYPE_DIRECTIONAL)))
			scene->lights.array[i]->type = LIGHT_TYPE_DIRECTIONAL;
		else if (!(ft_strcmp(value, FILE_LIGHT_TYPE_POINT)))
			scene->lights.array[i]->type = LIGHT_TYPE_POINT;
	}
	else if (!(ft_strcmp(property, FILE_LIGHT_INTENSITY)))
		scene->lights.array[i]->intensity = (double)ft_atoi(value) / 10.0;
	else if (!(ft_strcmp(property, FILE_LIGHT_POSITION)))
		scene->lights.array[i]->position = parse_vector(value);
	else
		return (-1);
	return (0);
}

int		parse_material_description(t_scene *scene, char *property, char *value)
{
	int i;

	i = scene->active_material;
	if (!(ft_strcmp(property, FILE_MATERIAL_NAME)))
		scene->materials.array[i]->name = ft_strdup(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_COLOR)))
		scene->materials.array[i]->color = parse_color(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_SPECULAR)))
		scene->materials.array[i]->specular = ft_atoi(value);
	else if (!(ft_strcmp(property, FILE_MATERIAL_REFLECTIVE)))
		scene->materials.array[i]->reflective = (double)ft_atoi(value) / 10.0;
	else
		return (-1);
	return (0);
}