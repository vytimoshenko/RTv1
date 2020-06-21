/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_vector_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:12:27 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:15:56 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

double		deg_to_rad(int degrees)
{
	return ((double)degrees * PI / 180.0);
}

double		dot(t_vec v1, t_vec v2)
{
	return ((double)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

double		length(t_vec v)
{
	return ((double)sqrt(dot(v, v)));
}

t_vec	normalize(t_vec v)
{
	return ((mult_sv(1.0 / length(v), v)));
}
