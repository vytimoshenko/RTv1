/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_mlx_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 01:40:25 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 03:50:24 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mlx	*init_mlx(void)
{
	t_mlx *mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_put_errno(PROGRAM_NAME);
	if (!(mlx->mlx = mlx_init()))
		put_mlx_error(mlx, "mlx_init");
	if (!(mlx->win = (void *)mlx_new_window(mlx->mlx, WIN_SIZE_W, WIN_SIZE_H,
	PROGRAM_NAME)))
		put_mlx_error(mlx, "mlx_new_window");
	if (!(mlx->img = (void *)mlx_new_image(mlx->mlx, IMG_SIZE_W, IMG_SIZE_H)))
		put_mlx_error(mlx, "mlx_new_image");
	if (!(mlx->data = (int *)mlx_get_data_addr(mlx->img, &(mlx->bits_per_pixel),
	&(mlx->size_line), &(mlx->endian))))
		put_mlx_error(mlx, "mlx_get_data_addr");
	// reset_render_status(mlx);
	return (mlx);
}

void	clean_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		mlx_destroy_image(mlx->mlx, mlx->img);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
}

void	put_mlx_error(t_mlx *mlx, char *str)
{
	ft_putstr(PROGRAM_NAME);
	ft_putstr(": error occured in mlx function ");
	ft_putendl(str);
	clean_mlx(mlx);
	exit(1);
}
