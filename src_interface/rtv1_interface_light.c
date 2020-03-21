/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_interface_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 20:40:47 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 23:31:49 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	info_light(t_scene *scene, t_mlx *mlx)
{
	int	x;
	int	y;

	x = WIN_SIZE_W - 350;
	y = 300;
    info_light_1(scene, mlx, x, y);
    info_light_2(scene, mlx, x, y);
    info_light_3(scene, mlx, x, y);
    info_light_4(scene, mlx, x, y);
}

void	info_light_1(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char    *str;

    mlx_string_put(mlx->mlx, mlx->win, x + 90, y - 30, TEXT_COLOR,
    "LIGHT CONTROL");
    mlx_string_put(mlx->mlx, mlx->win, x, y, TEXT_COLOR,
    "Light source:     #");
    mlx_string_put(mlx->mlx, mlx->win, x + 190, y, TEXT_COLOR,
    str = ft_itoa(scene->active_light));
    free(str);
    if (scene->lights.array[scene->active_light]->type == LIGHT_TYPE_AMBIENT)
        mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR, "Ambient");
    else if (scene->lights.array[scene->active_light]->type ==
    LIGHT_TYPE_DIRECTIONAL)
        mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR,
        "Directional");
    else if (scene->lights.array[scene->active_light]->type == LIGHT_TYPE_POINT)
        mlx_string_put(mlx->mlx, mlx->win, x + 210, y, TEXT_COLOR, "Point");
}

void	info_light_2(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

    mlx_string_put(mlx->mlx, mlx->win, x, y + 30, TEXT_COLOR,  "- switch:");
    if (scene->lights.array[scene->active_light]->off == FALSE)
        mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR, "on");
    else if (scene->lights.array[scene->active_light]->off == TRUE)
        mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 30, TEXT_COLOR, "off");
    mlx_string_put(mlx->mlx, mlx->win, x, y + 50, TEXT_COLOR,
    "- intensity (x10):");
    mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 50, TEXT_COLOR,
    str = ft_itoa(10 * scene->lights.array[scene->active_light]->intensity));
    free(str);
}

void	info_light_3(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

    if (scene->lights.array[scene->active_light]->type ==
    LIGHT_TYPE_POINT)
    {
        mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
        "- position (XYZ):");
        mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 70, TEXT_COLOR,
        str = ft_itoa(scene->lights.array[scene->active_light]->position.x));
        free(str);
        mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 70, TEXT_COLOR,
        str = ft_itoa(scene->lights.array[scene->active_light]->position.y));
        free(str);
        mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 70, TEXT_COLOR,
        str = ft_itoa(scene->lights.array[scene->active_light]->position.z));
        free(str);
    }
}

void	info_light_4(t_scene *scene, t_mlx *mlx, int x, int y)
{
	char	*str;

    if (scene->lights.array[scene->active_light]->type ==
    LIGHT_TYPE_DIRECTIONAL)
    {
        mlx_string_put(mlx->mlx, mlx->win, x, y + 70, TEXT_COLOR,
        "- direction (XYZ):");
        mlx_string_put(mlx->mlx, mlx->win, x + 190, y + 70, TEXT_COLOR,
        str = ft_itoa(scene->lights.array[scene->active_light]->direction.x));
        free(str);
        mlx_string_put(mlx->mlx, mlx->win, x + 240, y + 70, TEXT_COLOR,
        str = ft_itoa(scene->lights.array[scene->active_light]->direction.y));
        free(str);
        mlx_string_put(mlx->mlx, mlx->win, x + 290, y + 70, TEXT_COLOR,
        str = ft_itoa(scene->lights.array[scene->active_light]->direction.z));
        free(str);
    }
}
