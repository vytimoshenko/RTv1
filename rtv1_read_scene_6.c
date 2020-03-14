/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:30:13 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/14 14:52:00 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	parse_vector(char *value)
{
	int			i;
	char		*tmp;
	t_vector	vector;

	tmp = ft_strnew(10);
	i = ft_strindex(',', value);
	tmp = ft_strncat(tmp, value, i);
	vector.x = ft_atoi(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	i = ft_strindex(',', value);
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
	t_color		color;

	value_start = value;
	tmp = ft_strnew(10);
	i = ft_strindex(',', value);
	tmp = ft_strncat(tmp, value, i);
	color.r = check_and_get_int_value(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	i = ft_strindex(',', value);
	tmp = ft_strncat(tmp, value, i);
	color.g = check_and_get_int_value(tmp);
	ft_bzero(tmp, 10);
	while (i-- >= 0)
		value++;
	color.b = check_and_get_int_value(value);
	ft_strdel(&tmp);
	validate_color(value_start, color);
	return (color);
}

void		validate_color(char *value, t_color color)
{
	if (color.r > 255 || color.g > 255 || color.b > 255 ||
	color.r < 0 || color.g < 0 || color.b < 0)
	{
		ft_putstr("=> ");
		ft_putendl(value);
		put_error_pn("wrong color in scene");
	}
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
