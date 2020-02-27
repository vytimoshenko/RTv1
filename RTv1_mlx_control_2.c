/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_control_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 01:08:23 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/27 04:27:50 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	get_mouse_position(t_status *status, int x, int y)
{
	status->x_mouse_position = x - IMG_SIZE_W / 2 - IMG_INDT_W;
	status->y_mouse_position = IMG_SIZE_H / 2 - y + IMG_INDT_H;
	if (x < IMG_INDT_W || y < IMG_INDT_H || x > IMG_INDT_W + IMG_SIZE_W ||
	y > IMG_INDT_H + IMG_SIZE_H)
	{
		status->x_mouse_position = 0;
		status->y_mouse_position = 0;
	}
}

int		select_object(int x, int y, t_global *global)
{
	int	i;
	int object_id;
	
	x = x - IMG_INDT_W;
	y = y - IMG_INDT_H;
	if (x < 0 || x > IMG_SIZE_W || y < 0 || y > IMG_SIZE_H)
		return (-1);
	i = (int)(IMG_SIZE_W * (y - 1) + x);
	object_id = global->status->object_buffer[i];
	if (global->status->active_object == object_id)
		return (0);
	else
	{
		global->status->active_object = object_id;
		return (1);
	}
}

void	change_camera(t_status *status)
{
	if (status->current_camera != status->cameras_quantity - 1)
		status->current_camera++;
	else
		status->current_camera = 0;
}

void	change_effect(t_status *status)
{
	if (status->effect != EFFECTS_QUANTITY)
		status->effect++;
	else
		status->effect = NO_EFFECT;
}