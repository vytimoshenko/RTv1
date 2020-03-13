/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:24:15 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/13 07:36:18 by mperseus         ###   ########.fr       */
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

char	*any_whitespace_to_space(char *value)
{
	int	i;

	i = 0;
	while (value[i++] != '\0')
	{
		if (is_whitespace(value[i]))
			value[i] = ' ';
	}
	return (value);
}
