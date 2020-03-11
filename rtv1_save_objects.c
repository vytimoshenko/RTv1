/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_save_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 05:35:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/11 07:06:32 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void    write_scene_info(t_scene *scene, int fd)
{
	ft_putstr_fd("{\n\t\"scene_name\": \"", fd);
	ft_putstr_fd(scene->scene_name, fd);
    ft_putendl_fd("\",\n", fd);
	write_cameras_info(scene, fd);
    ft_putstr_fd("\n\n", fd);
	write_lights_info(scene, fd);
    ft_putstr_fd("\n\n", fd);
	write_materials_info(scene, fd);
    ft_putstr_fd("\n\n", fd);
	write_objects_info(scene, fd);
	ft_putendl_fd("\n}", fd);
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
        {
            ft_putstr_fd(",\n\t\t\"position\":\t[", fd);
            ft_putnbr_fd(scene->lights.array[i]->position.x, fd);
            ft_putstr_fd(", ", fd);
            ft_putnbr_fd(scene->lights.array[i]->position.y, fd);
            ft_putstr_fd(", ", fd);
            ft_putnbr_fd(scene->lights.array[i]->position.z, fd);
            ft_putendl_fd("]\n\t},", fd);
        }
	}
}

void	write_materials_info(t_scene *scene, int fd)
{
	int	i;
	
	i = -1;
	while (++i < scene->materials.quantity)
	{
		ft_putendl_fd("\t\"material\":", fd);
        ft_putstr_fd("\t{\n\t\t\"name\":\t\t\"", fd);
		ft_putstr_fd(scene->materials.array[i]->name, fd);
		ft_putstr_fd("\",\n\t\t\"color\":\t[", fd);
		ft_putnbr_fd(scene->materials.array[i]->color.r, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->materials.array[i]->color.g, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->materials.array[i]->color.b, fd);
		ft_putstr_fd("],\n\t\t\"specular\":\t", fd);
        ft_putnbr_fd(scene->materials.array[i]->specular, fd);
		ft_putstr_fd(",\n\t", fd);
        ft_putstr_fd("\t\"reflective\":\t", fd);
        ft_putnbr_fd((int)(10 * scene->materials.array[i]->reflective), fd);
		ft_putendl_fd("]\n\t},", fd);
	}
}

void	write_objects_info(t_scene *scene, int fd)
{
	int	i;
	
	i = -1;
	while (++i < scene->objects.quantity)
	{
		ft_putendl_fd("\t\"object\":", fd);
		ft_putstr_fd("\t{\n\t\t\"type\":\t\t", fd);
		if (scene->objects.array[i]->type == OBJECT_TYPE_PLANE)
            ft_putstr_fd("\"plane\"", fd);
        else if (scene->objects.array[i]->type == OBJECT_TYPE_SPHERE)
            ft_putstr_fd("\"sphere\"", fd);
        else if (scene->objects.array[i]->type == OBJECT_TYPE_CYLINDER)
            ft_putstr_fd("\"cylinder\"", fd);
        else if (scene->objects.array[i]->type == OBJECT_TYPE_CONE)
            ft_putstr_fd("\"cone\"", fd);
		ft_putstr_fd(",\n\t\t\"material\":\t\"", fd);
		ft_putstr_fd(scene->materials.array
        [scene->objects.array[i]->material]->name, fd);
        ft_putstr_fd("\",\n\t\t\"position\":\t[", fd);
		ft_putnbr_fd(scene->objects.array[i]->position.x, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->objects.array[i]->position.y, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->objects.array[i]->position.z, fd);
		ft_putstr_fd("],\n\t\t\"direction\":\t[", fd);
		ft_putnbr_fd(scene->objects.array[i]->direction.x, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->objects.array[i]->direction.y, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->objects.array[i]->direction.z, fd);
		ft_putstr_fd("]\n\t}", fd);
		if (i < scene->objects.quantity - 1)
			ft_putendl_fd(",", fd);
	}
}
