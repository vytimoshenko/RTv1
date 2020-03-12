/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 09:00:27 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/12 09:09:10 by mperseus         ###   ########.fr       */
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
	(void)scene;
	(void)property;
	(void)value;
	return (0);
}

int		parse_light_description(t_scene *scene, char *property, char *value)
{
	(void)scene;
	(void)property;
	(void)value;
	return (0);
}

int		parse_material_description(t_scene *scene, char *property, char *value)
{
	(void)scene;
	(void)property;
	(void)value;
	return (0);
}

int		parse_object_description(t_scene *scene, char *property, char *value)
{
	(void)scene;
	(void)property;
	(void)value;
	return (0);
}
