/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_vector_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:12:27 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/15 08:14:11 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		deg_to_rad(int degrees)
{
	return ((double)degrees * PI / 180.0);
}

double		dot(t_vector v1, t_vector v2)
{
	return ((double)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

double		length(t_vector v)
{
	return ((double)sqrt(dot(v, v)));
}

t_vector	normalize(t_vector v)
{
	return ((multiply_sv(1.0 / length(v), v)));
}
