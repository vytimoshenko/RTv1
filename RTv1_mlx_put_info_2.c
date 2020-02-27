/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_mlx_put_info_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:50:53 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/28 01:14:35 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	put_status_1(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 380;
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 110, pos_y - 30, TEXT_COLOR,
	"STATUS");
    mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y, TEXT_COLOR,
	"Effect:");
	if (status->effect == NO_EFFECT)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"no");
	else if (status->effect == EFFECT_GRAYSCALE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Grayscale");
	else if (status->effect == EFFECT_NEGATIVE)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Negative");
	else if (status->effect == EFFECT_CARTOON)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y, TEXT_COLOR,
		"Cartoon");
}

void	put_status_2(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 380;
	
	mlx_string_put(mlx->mlx, mlx->win, pos_x , pos_y + 30, TEXT_COLOR,
	"Current camera:   #");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
	str = ft_itoa(status->current_camera + 1));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
	"- position (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->position.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->position.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 60, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->position.z));
	free(str);
}

void	put_status_3(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 380;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
	"- rotation (XYZ):");
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->direction.x));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->direction.y));
	free(str);
	mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 80, TEXT_COLOR,
	str = ft_itoa(status->cameras[status->current_camera]->direction.z));
	free(str);
}

void	put_status_4(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 490;
	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 30, TEXT_COLOR,
	"Selected object:");
	if (status->active_object == NO_OBJECT_SELECTED)
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
		"no");
	else
	{		
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 30, TEXT_COLOR,
		str = ft_itoa(status->active_object));
		free(str);	
	}
}

void	put_status_5(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 490;
	if (status->active_object != NO_OBJECT_SELECTED)
	{
		mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 60, TEXT_COLOR,
        "- position (XYZ):");
        mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 60, TEXT_COLOR,
        str = ft_itoa(status->spheres.array[status->active_object]->center.x));
        free(str);
        mlx_string_put(mlx->mlx, mlx->win, pos_x + 240, pos_y + 60, TEXT_COLOR,
        str = ft_itoa(status->spheres.array[status->active_object]->center.y));
        free(str);
        mlx_string_put(mlx->mlx, mlx->win, pos_x + 290, pos_y + 60, TEXT_COLOR,
        str = ft_itoa(status->spheres.array[status->active_object]->center.z));
        free(str);
        mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 80, TEXT_COLOR,
        "- rotation (XYZ):");
	}
}

void	put_status_6(t_status *status, t_mlx *mlx)
{
	int		pos_x;
	int		pos_y;
	char	*str;

	pos_x = WIN_SIZE_W - 350;
	pos_y = 490;
    if (status->active_object != NO_OBJECT_SELECTED)
	{
    	mlx_string_put(mlx->mlx, mlx->win, pos_x, pos_y + 100, TEXT_COLOR,
		"- radius:");
		mlx_string_put(mlx->mlx, mlx->win, pos_x + 190, pos_y + 100, TEXT_COLOR,
		str = ft_itoa(status->spheres.array[status->active_object]->radius));
		free(str); 
        // mlx_string_put(mlx->mlx, mlx->win, pos_x + 200, pos_y + 80, TEXT_COLOR,
        // str = ft_itoa(status->cameras[status->current_camera]->direction.x));
        // free(str);
        // mlx_string_put(mlx->mlx, mlx->win, pos_x + 250, pos_y + 80, TEXT_COLOR,
        // str = ft_itoa(status->cameras[status->current_camera]->direction.y));
        // free(str);
        // mlx_string_put(mlx->mlx, mlx->win, pos_x + 300, pos_y + 80, TEXT_COLOR,
        // str = ft_itoa(status->cameras[status->current_camera]->direction.z));
        // free(str);
    }
}
