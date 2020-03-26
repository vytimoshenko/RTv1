/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:30:13 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/26 19:21:05 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_vector	parse_vector(char *value)
{
	int			i;
	char		*tmp;
	char		*value_start;
	t_vector	vector;

	value_start = value;
	tmp = ft_strnew(10);
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	vector.x = ft_atoi(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	vector.y = ft_atoi(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	vector.z = ft_atoi(value);
	ft_strdel(&tmp);
	return (vector);
}

t_color		parse_color(char *value)
{
	int			i;
	char		*tmp;
	char		*value_start;
	t_vector	color;

	value_start = value;
	tmp = ft_strnew(10);
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	color.x = check_and_get_int_value(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	if ((i = ft_strindex(',', value)) < 0)
		put_error_wrong_scene_data(value_start, "missing ','");
	tmp = ft_strncat(tmp, value, i);
	color.y = check_and_get_int_value(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	color.z = check_and_get_int_value(value);
	ft_strdel(&tmp);
	validate_color(value_start, color);
	return ((t_color){color.x, color.y, color.z});
}

void		validate_color(char *value, t_vector color)
{
	if (color.x > 255 || color.y > 255 || color.z > 255 ||
	color.x < 0 || color.y < 0 || color.z < 0)
		put_error_wrong_scene_data(value, "wrong color in scene");
}

int			check_and_get_int_value(char *value)
{
	int	i;

	i = -1;
	while (value[++i] != '\0')
	{
		if (!(ft_isdigit(value[i])))
			return (-1);
	}
	return (ft_atoi(value));
}
