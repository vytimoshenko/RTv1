/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 08:45:30 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/12 09:04:32 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		parse_item_description(t_scene *scene, char *type, char *description)
{
	int		i;
	char	*property;
	char	*value;
	char	*prepared_value;
	
	if (!(*description))
		return (0);
	i = 0;
	while (description[i] != ':')
		i++;
	property = ft_strnew(i);
	ft_strncpy(property, description, i);
	while (--i >= -1)
		description++;
	while (description[i] != ';')
		i++;
	value = ft_strnew(i);
	ft_strncpy(value, description, i);
	prepared_value = prepare_value_to_write(value);
printf("\tPRP:\t%s\n", property);
printf("\tP_VAL:\t%s\n\n", prepared_value);
	if (parse_item_by_property(scene, type, property, prepared_value) == -1)
		return (-1);
	ft_strdel(&property);
	ft_strdel(&value);
	ft_strdel(&prepared_value);
	while (--i >= -1)
		description++;
	if (parse_item_description(scene, type, description) == -1)
		return (-1);
	return (0);
}

char	*prepare_value_to_write(char *value)
{
	int		len;
	char	*prepared_value;
	
	if (*value == '"')
		any_whitespace_to_space(value);
	if (*value == '"' || *value == '<' || *value == '[')
	{
		value++;
		len = ft_strlen(value);
		prepared_value = ft_strnew(len - 1);
		ft_strncpy(prepared_value, value, len - 1);
	}
	else
		prepared_value = ft_strdup(value);
	return (prepared_value);
}

int    parse_item_by_property(t_scene *scene, char *type, char *property, char *value)
{
	if (!(ft_strcmp(type, FILE_SCENE)))
		return(parse_scene_description(scene, property, value));
    else if (!(ft_strcmp(type, FILE_CAMERA)))
		return (parse_camera_description(scene, property, value));
	else if (!(ft_strcmp(type, FILE_LIGHT)))
		return (parse_light_description(scene, property, value));
	else if (!(ft_strcmp(type, FILE_MATERIAL)))
		return (parse_material_description(scene, property, value));
	else if (!(ft_strcmp(type, FILE_OBJECT)))
		return (parse_object_description(scene, property, value));
	else
		return (-1);
	return (0);
}
