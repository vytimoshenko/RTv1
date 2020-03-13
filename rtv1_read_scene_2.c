/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 08:45:30 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/13 07:25:37 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		count_items_by_type(t_scene *scene, char *item_line)
{
	int		i;
	int		type_id;
	char	*type;

	i = 0;
	while (item_line[i] != '{')
		i++;
	type = ft_strnew(i);
	ft_strncpy(type, item_line, i);
	if ((type_id = define_item_type(scene, type)) == -1)
		return (-1);
	ft_strdel(&type);
	return (0);
}

int		define_item_type(t_scene *scene, char *type)
{
	if (!(ft_strcmp(type, FILE_SCENE)))
		return (FILE_PARSE_SCENE);
	else if (!(ft_strcmp(type, FILE_CAMERA)))
	{
		scene->active_camera++;
		return (FILE_PARSE_CAMERA);
	}
	else if (!(ft_strcmp(type, FILE_LIGHT)))
	{
		scene->active_light++;
		return (FILE_PARSE_LIGHT);
	}
	else if (!(ft_strcmp(type, FILE_MATERIAL)))
	{
		scene->active_material++;
		return (FILE_PARSE_MATERIAL);
	}
	else if (!(ft_strcmp(type, FILE_OBJECT)))
	{
		scene->active_object++;
		return (FILE_PARSE_OBJECT);
	}
	else
		return (-1);
	return (0);
}

void	save_quantities(t_scene *scene)
{
	scene->cameras.quantity = scene->active_camera + 1;
	scene->lights.quantity = scene->active_light + 1;
	scene->materials.quantity = scene->active_material + 1;
	scene->objects.quantity = scene->active_object + 1;
	scene->active_camera = NOTHING_SELECTED;
	scene->active_light = NOTHING_SELECTED;
	scene->active_material = NOTHING_SELECTED;
	scene->active_object = NOTHING_SELECTED;
}

void	allocate_memory(t_scene *scene)
{
	int	i;

	scene->cameras.array = (t_camera **)ft_memalloc(sizeof(t_camera *) *
	scene->cameras.quantity);
	i = -1;
	while (++i < scene->cameras.quantity)
		scene->cameras.array[i] = (t_camera *)ft_memalloc(sizeof(t_camera));
	scene->lights.array = (t_light **)ft_memalloc(sizeof(t_light *) *
	scene->lights.quantity);
	i = -1;
	while (++i < scene->lights.quantity)
		scene->lights.array[i] = (t_light *)ft_memalloc(sizeof(t_light));
	scene->materials.array = (t_material **)ft_memalloc(sizeof(t_material *) *
	scene->materials.quantity);
	i = -1;
	while (++i < scene->materials.quantity)
		scene->materials.array[i] =
		(t_material *)ft_memalloc(sizeof(t_material));
	scene->objects.array = (t_object **)ft_memalloc(sizeof(t_object *) *
	scene->objects.quantity);
	i = -1;
	while (++i < scene->objects.quantity)
		scene->objects.array[i] = (t_object *)ft_memalloc(sizeof(t_object));
}

int		parse_item_line(t_scene *scene, char *item_line)
{
	int		i;
	int		type_id;
	char	*type;
	char	*description;

	i = 0;
	while (item_line[i] != '{')
		i++;
	type = ft_strnew(i);
	ft_strncpy(type, item_line, i);
	type_id = define_item_type(scene, type);
	while (--i >= -1)
		item_line++;
	while (item_line[i] != '}')
		i++;
	description = ft_strnew(i);
	ft_strncpy(description, item_line, i);
	parse_item_description(scene, type_id, description);
	ft_strdel(&type);
	ft_strdel(&description);
	return (0);
}
