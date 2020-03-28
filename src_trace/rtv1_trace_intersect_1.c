/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace_intersect_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 08:30:52 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/28 21:31:17 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

t_object	get_intersection(t_objects objects, t_vector camera, t_vector pixel,
			t_t_min_max t_min_max)
{
	int			i;
	t_object	closest_object;

	i = -1;
	t_min_max.t = t_min_max.t_max;
	closest_object.null = 0;
	while (++i < objects.quantity)
	{
		select_object_intersect_function(objects.array[i], camera, pixel);
		if (objects.array[i]->t1 >= t_min_max.t_min && objects.array[i]->t1 <=
		t_min_max.t_max && objects.array[i]->t1 < t_min_max.t)
		{
			t_min_max.t = objects.array[i]->t1;
			closest_object = *objects.array[i];
			closest_object.null = 1;
		}
		if (objects.array[i]->t2 >= t_min_max.t_min && objects.array[i]->t2 <=
		t_min_max.t_max && objects.array[i]->t2 < t_min_max.t)
		{
			t_min_max.t = objects.array[i]->t2;
			closest_object = *objects.array[i];
			closest_object.null = 1;
		}
	}
	return (check_closest_object(closest_object, t_min_max.t));
}

t_object	check_closest_object(t_object closest_object, double t)
{
	closest_object.closest = t;
	if (closest_object.null == 1)
		closest_object.null = 1;
	else
		closest_object.null = 0;
	return (closest_object);
}

void		select_object_intersect_function(t_object *object, t_vector camera,
			t_vector pixel)
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
