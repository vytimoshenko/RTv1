/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_other.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 11:14:03 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 16:39:10 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"
#include "../rtv1_interface.h"

void	info_draw_box(t_mlx *mlx, int size_w, int size_h)
{
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;

	pos_x = (WIN_SIZE_W - size_w) / 2;
	pos_y = (WIN_SIZE_H - size_h) / 2;
	y = -1;
	while (++y < size_h)
	{
		x = -1;
		while (++x < size_w)
			mlx_pixel_put(mlx->mlx, mlx->win, pos_x + x, pos_y + y, 0x50000000);
	}
}

void	info_message_box(t_mlx *mlx, char *message_title, char *message_content)
{
	int		pos_x;
	int		pos_y;

	pos_x = (WIN_SIZE_W - MESSAGE_BOX_W) / 2;
	pos_y = (WIN_SIZE_H - MESSAGE_BOX_H) / 2;
	info_draw_box(mlx, MESSAGE_BOX_W, MESSAGE_BOX_H);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(message_title) / 2, pos_y + MESSAGE_BOX_INDENTATION, TEXT_COLOR,
	message_title);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + MESSAGE_BOX_W / 2 -
	10 * ft_strlen(message_content) / 2, pos_y + MESSAGE_BOX_H / 2, TEXT_COLOR,
	message_content);
}
