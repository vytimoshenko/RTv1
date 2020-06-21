/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_vector_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 07:57:12 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 19:11:27 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

t_vec	add(t_vec v1, t_vec v2)
{
	t_vec result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vec	sub(t_vec v1, t_vec v2)
{
	t_vec result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vec	mult(double k, t_vec v)
{
	t_vec result;

	result.x = k * v.x;
	result.y = k * v.y;
	result.z = k * v.z;
	return (result);
}
