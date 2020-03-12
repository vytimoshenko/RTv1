/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:00:27 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/12 10:36:18 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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
    if (!(ft_strcmp(property, FILE_CAMERA_POSITION)))
		scene->cameras.array[0]->position = parse_vector(value);
	else if (!(ft_strcmp(property, FILE_CAMERA_DIRECTION)))
		scene->cameras.array[0]->direction = parse_vector(value);
	else
		return (-1);
	return (0);
}

int		parse_light_description(t_scene *scene, char *property, char *value)
{
    if (!(ft_strcmp(property, FILE_LIGHT_TYPE)))
    {
        if (!(ft_strcmp(value, FILE_LIGHT_TYPE_AMBIENT)))
            scene->lights.array[0]->type = LIGHT_TYPE_AMBIENT;
        else if (!(ft_strcmp(value, FILE_LIGHT_TYPE_DIRECTIONAL)))
            scene->lights.array[0]->type = LIGHT_TYPE_DIRECTIONAL;
        else if (!(ft_strcmp(value, FILE_LIGHT_TYPE_POINT)))
            scene->lights.array[0]->type = LIGHT_TYPE_POINT;
    }
    else if (!(ft_strcmp(property, FILE_LIGHT_INTENSITY)))
		scene->lights.array[0]->intensity = (double)ft_atoi(value) / 10.0;
    else if (!(ft_strcmp(property, FILE_LIGHT_POSITION)))
		scene->lights.array[0]->position = parse_vector(value);
	else
		return (-1);
	return (0);
}

int		parse_material_description(t_scene *scene, char *property, char *value)
{
    if (!(ft_strcmp(property, FILE_MATERIAL_NAME)))
		scene->materials.array[0]->name = ft_strdup(value);
    else if (!(ft_strcmp(property, FILE_MATERIAL_COLOR)))
		scene->materials.array[0]->color = parse_color(value);
    else if (!(ft_strcmp(property, FILE_MATERIAL_SPECULAR)))
		scene->materials.array[0]->specular = ft_atoi(value);
    else if (!(ft_strcmp(property, FILE_MATERIAL_REFLECTIVE)))
		scene->materials.array[0]->reflective = (double)ft_atoi(value) / 10.0;
	else
		return (-1);
	return (0);
}

int		parse_object_description(t_scene *scene, char *property, char *value)
{
    if (!(ft_strcmp(property, FILE_OBJECT_TYPE)))
    {
        if (!(ft_strcmp(value, FILE_OBJECT_TYPE_PLANE)))
            scene->objects.array[0]->type = OBJECT_TYPE_PLANE;
        else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_SPHERE)))
            scene->objects.array[0]->type = OBJECT_TYPE_SPHERE;
        else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_CYLINDER)))
            scene->objects.array[0]->type = OBJECT_TYPE_CYLINDER;
        else if (!(ft_strcmp(value, FILE_OBJECT_TYPE_CONE)))
            scene->objects.array[0]->type = OBJECT_TYPE_CONE;
    }
    else if (!(ft_strcmp(property, FILE_OBJECT_MATERIAL)))
        return (0);
		// scene->objects.array[0]->material = parse_vector(value);
    else if (!(ft_strcmp(property, FILE_OBJECT_POSITION)))
		scene->objects.array[0]->position = parse_vector(value);
    else if (!(ft_strcmp(property, FILE_OBJECT_ORIENTATION)))
		scene->objects.array[0]->orientation = parse_vector(value);
    else if (!(ft_strcmp(property, FILE_OBJECT_RADIUS)))
		scene->objects.array[0]->radius = ft_atoi(value);
	else
		return (-1);
	return (0);
}
