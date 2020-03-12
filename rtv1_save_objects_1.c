/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_save_objects_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 05:35:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/12 03:48:21 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	write_all_info(t_scene *scene, int fd)
{
	// ft_putstr_fd("{\n", fd);
	write_scene_info(scene, fd);
	ft_putstr_fd("\n\n", fd);
	write_cameras_info(scene, fd);
	ft_putstr_fd("\n\n", fd);
	write_lights_info(scene, fd);
	ft_putstr_fd("\n\n", fd);
	write_materials_info(scene, fd);
	ft_putstr_fd("\n\n", fd);
	write_objects_info(scene, fd);
	// ft_putendl_fd("\n}", fd);
}

void	write_scene_info(t_scene *scene, int fd)
{
	ft_putendl_fd("\t\"scene\":", fd);
	ft_putstr_fd("\t{\n\t\t\"name\":\t\t\"", fd);
	ft_putstr_fd(scene->name, fd);
	ft_putendl_fd("\",", fd);
	ft_putstr_fd("\t\t\"author\":\t\"", fd);
	ft_putstr_fd(scene->author, fd);
	ft_putendl_fd("\"\n\t},", fd);
}

void	write_cameras_info(t_scene *scene, int fd)
{
	int	i;

	i = -1;
	while (++i < scene->cameras.quantity)
	{
		ft_putendl_fd("\t\"camera\":", fd);
		ft_putstr_fd("\t{\n\t\t\"position\":\t[", fd);
		ft_putnbr_fd(scene->cameras.array[i]->position.x, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->cameras.array[i]->position.y, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->cameras.array[i]->position.z, fd);
		ft_putstr_fd("],\n\t\t\"direction\":\t[", fd);
		ft_putnbr_fd(scene->cameras.array[i]->direction.x, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->cameras.array[i]->direction.y, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->cameras.array[i]->direction.z, fd);
		ft_putendl_fd("]\n\t},", fd);
	}
}

void	write_lights_info(t_scene *scene, int fd)
{
	int	i;

	i = -1;
	while (++i < scene->lights.quantity)
	{
		ft_putendl_fd("\t\"light\":", fd);
		ft_putstr_fd("\t{\n\t\t\"type\":\t\t", fd);
		if (scene->lights.array[i]->type == LIGHT_TYPE_AMBIENT)
			ft_putstr_fd("\"ambient\"", fd);
		else if (scene->lights.array[i]->type == LIGHT_TYPE_DIRECTIONAL)
			ft_putstr_fd("\"directional\"", fd);
		else if (scene->lights.array[i]->type == LIGHT_TYPE_POINT)
			ft_putstr_fd("\"point\"", fd);
		ft_putstr_fd(",\n\t\t\"intensity\":\t", fd);
		ft_putnbr_fd((int)(10 * scene->lights.array[i]->intensity), fd);
		if (scene->lights.array[i]->type == LIGHT_TYPE_AMBIENT)
			ft_putendl_fd("\n\t},", fd);
		else
			write_lights_info_extra(scene, fd, i);
	}
}

void	write_lights_info_extra(t_scene *scene, int fd, int i)
{
	ft_putstr_fd(",\n\t\t\"position\":\t[", fd);
	ft_putnbr_fd(scene->lights.array[i]->position.x, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->lights.array[i]->position.y, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->lights.array[i]->position.z, fd);
	ft_putendl_fd("]\n\t},", fd);
}
