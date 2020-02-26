/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_control_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 18:34:41 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/26 21:37:46 by mperseus         ###   ########.fr       */
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

void	control_zoom(t_status *status, int key)
{
	if (key == PLUS)
		status->zoom *= 1.1;
	else if (key == MINUS)
		status->zoom /= 1.1;
}

void	control_mouse_zoom(t_status *status, int x, int y, int key)
{
	int i;
	(void)x;
	(void)y;

	i = status->current_camera;
	if (key == MOUSE_SCROLL_UP)
		status->cameras.array[i]->z += 1;
	else if (key == MOUSE_SCROLL_DOWN)
		status->cameras.array[i]->z -= 1;
}

void	change_camera(t_status *status)
{
	if (status->current_camera != status->cameras.quantity - 1)
		status->current_camera++;
	else
		status->current_camera = 0;
}

void	move_camera(t_status *status, int key)
{
	int i;

	i = status->current_camera;
	if (key == ARROW_DOWN)
		status->cameras.array[i]->y -= 5;
	else if (key == ARROW_UP)
		status->cameras.array[i]->y += 5;
	else if (key == ARROW_RIGHT)
		status->cameras.array[i]->x += 5;
	else if (key == ARROW_LEFT)
		status->cameras.array[i]->x -= 5;
	else if (key == PLUS)
		status->cameras.array[i]->z += 5;
	else if (key == MINUS)
		status->cameras.array[i]->z -= 5;
}

void	move_object(t_status *status, int key)
{
	int i;

	i = status->active_object;
	if (key == ARROW_DOWN)
		status->spheres.array[i]->center.y -= 5;
	else if (key == ARROW_UP)
		status->spheres.array[i]->center.y += 5;
	else if (key == ARROW_RIGHT)
		status->spheres.array[i]->center.x += 5;
	else if (key == ARROW_LEFT)
		status->spheres.array[i]->center.x -= 5;
	else if (key == PLUS)
		status->spheres.array[i]->center.z += 5;
	else if (key == MINUS)
		status->spheres.array[i]->center.z -= 5;
}

void	rotate_camera(t_status *status, int key)
{
	if (key == W)
		status->x_rotation += 30.0;
	else if (key == S)
		status->x_rotation -= 30.0;
	else if (key == D)
		status->y_rotation += 30.0;
	else if (key == A)
		status->y_rotation -= 30.0;
	else if (key == MORE)
		status->z_rotation += 30.0;
	else if (key == LESS)
		status->z_rotation -= 30.0;
}

// void	control_mouse_shift(t_status *status, int x, int y)
// {
// 	int i;

// 	x = IMG_SIZE_W / 2 - x;
// 	y = IMG_SIZE_H / 2 - y;
// 	if (status->middle_mouse_button == 1)
// 	{
// 		status->x_move = x;
// 		status->y_move = y;
// 		status->middle_mouse_button = 2;
// 	}
// 	i = status->current_camera;
// 	if (status->middle_mouse_button == 2)
// 	{
// 		status->cameras.array[i]->x += status->x_move / IMG_SIZE_W;
// 		status->cameras.array[i]->y += status->y_move / IMG_SIZE_H;
// 		status->x_move = x;
// 		status->y_move = y;
// 	}
// }

void	control_mouse_shift(t_status *status, int x, int y)
{
	int i;
	
	x = x - IMG_SIZE_W / 2 - IMG_INDT_W;
	y = IMG_SIZE_H / 2 - y + IMG_INDT_H;
	i = status->current_camera;
	if (status->middle_mouse_button == BUTTON_DOWN)
	{
		status->x_move = x;
		status->y_move = y;
		status->middle_mouse_button = IN_MOVE;
	}
	else if (status->middle_mouse_button == IN_MOVE)
	{
		status->cameras.array[i]->x -= (int)((x - status->x_move) / IMG_SIZE_W);
		status->cameras.array[i]->y -= (int)((y - status->y_move) / IMG_SIZE_H);
		status->x_move = 0;
		status->y_move = 0;
	}
}

// void	control_mouse_shift(t_status *status, int x, int y)
// {
// 	if (status->middle_mouse_button == 1)
// 	{
// 		status->x_move = status->x_shift - x;
// 		status->y_move = status->y_shift - y;
// 		status->middle_mouse_button = 2;
// 	}
// 	else if (status->middle_mouse_button == 2)
// 	{
// 		status->x_shift = status->x_move + x;
// 		status->y_shift = status->y_move + y;
// 	}