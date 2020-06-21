/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_intersect_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 08:30:52 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:50:14 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

t_obj	get_intersection(t_objs objects, t_vec camera, t_vec pixel,
			t_t_min_max t_min_max)
{
	int			i;
	t_obj	closest_object;

	i = -1;
	t_min_max.t = t_min_max.t_max;
	closest_object.null = 0;
	while (++i < objects.quant)
	{
		select_object_intersect_function(objects.arr[i], camera, pixel);
		if (objects.arr[i]->t1 >= t_min_max.t_min && objects.arr[i]->t1 <=
		t_min_max.t_max && objects.arr[i]->t1 < t_min_max.t)
		{
			t_min_max.t = objects.arr[i]->t1;
			closest_object = *objects.arr[i];
			closest_object.null = 1;
		}
		if (objects.arr[i]->t2 >= t_min_max.t_min && objects.arr[i]->t2 <=
		t_min_max.t_max && objects.arr[i]->t2 < t_min_max.t)
		{
			t_min_max.t = objects.arr[i]->t2;
			closest_object = *objects.arr[i];
			closest_object.null = 1;
		}
	}
	return (check_closest_object(closest_object, t_min_max.t));
}

t_obj	check_closest_object(t_obj closest_object, double t)
{
	closest_object.closest = t;
	if (closest_object.null == 1)
		closest_object.null = 1;
	else
		closest_object.null = 0;
	return (closest_object);
}

void		select_object_intersect_function(t_obj *object, t_vec camera,
			t_vec pixel)
{
	if (object->type == OBJECT_TYPE_PLANE)
		plane(object, camera, pixel);
	else if (object->type == OBJECT_TYPE_SPHERE)
		sphere(object, camera, pixel);
	else if (object->type == OBJECT_TYPE_CYLINDER)
		cylinder(object, camera, pixel);
	else if (object->type == OBJECT_TYPE_CONE)
		cone(object, camera, pixel);
}
