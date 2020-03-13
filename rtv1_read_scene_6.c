/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:30:13 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/13 07:39:53 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

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

t_color		parse_color(char *value)
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
