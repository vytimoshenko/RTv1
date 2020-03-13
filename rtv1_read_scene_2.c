/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 08:45:30 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/13 04:30:50 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		parse_item_description(t_scene *scene, int type_id, char *description)
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
	if (parse_item_by_property(scene, type_id, property, prepared_value) == -1)
		return (-1);
	ft_strdel(&property);
	ft_strdel(&value);
	ft_strdel(&prepared_value);
	while (--i >= -1)
		description++;
	if (parse_item_description(scene, type_id, description) == -1)
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

int    parse_item_by_property(t_scene *scene, int type_id, char *property, char *value)
{
	if (type_id == FILE_PARSE_SCENE)
		return(parse_scene_description(scene, property, value));
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

t_vector	parse_vector(char *value)
{
	int			i;
	char		*tmp;
	t_vector	vector;
	
	tmp = ft_strnew(10);
	i = 0;
	while (value[i] != ',')
		i++;
	tmp = ft_strncat(tmp, value, i);
	vector.x = ft_atoi(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	i = 0;
	while (value[i] != ',')
		i++;
	tmp = ft_strncat(tmp, value, i);
	vector.y = ft_atoi(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	vector.z = ft_atoi(value);
	ft_strdel(&tmp);
	return (vector);
}

t_color	parse_color(char *value)
{
	int			i;
	char		*tmp;
	t_color		color;
	
	tmp = ft_strnew(10);
	i = 0;
	while (value[i] != ',')
		i++;
	tmp = ft_strncat(tmp, value, i);
	color.r = ft_atoi(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	i = 0;
	while (value[i] != ',')
		i++;
	tmp = ft_strncat(tmp, value, i);
	color.g = ft_atoi(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	color.b = ft_atoi(value);
	ft_strdel(&tmp);
	return (color);
}
