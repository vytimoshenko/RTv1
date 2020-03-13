/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_save_scene_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 05:35:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/13 07:49:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	write_materials_info(t_scene *scene, int fd)
{
	int	i;

	i = -1;
	while (++i < scene->materials.quantity)
	{
		ft_putendl_fd("material", fd);
		ft_putstr_fd("{\n\tname:\t\t\"", fd);
		ft_putstr_fd(scene->materials.array[i]->name, fd);
		ft_putstr_fd("\";\n\tcolor:\t\t[", fd);
		ft_putnbr_fd(scene->materials.array[i]->color.r, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->materials.array[i]->color.g, fd);
		ft_putstr_fd(", ", fd);
		ft_putnbr_fd(scene->materials.array[i]->color.b, fd);
		ft_putstr_fd("];\n\tspecular:\t", fd);
		ft_putnbr_fd(scene->materials.array[i]->specular, fd);
		ft_putstr_fd(";\n\t", fd);
		ft_putstr_fd("reflective:\t", fd);
		ft_putnbr_fd((int)(10 * scene->materials.array[i]->reflective), fd);
		ft_putendl_fd(";\n}\n", fd);
	}
}

void	write_objects_info(t_scene *scene, int fd)
{
	int	i;

	i = -1;
	while (++i < scene->objects.quantity)
	{
		ft_putendl_fd("object", fd);
		ft_putstr_fd("{\n\ttype:\t\t", fd);
		if (scene->objects.array[i]->type == OBJECT_TYPE_PLANE)
			ft_putstr_fd("<plane>", fd);
		else if (scene->objects.array[i]->type == OBJECT_TYPE_SPHERE)
			ft_putstr_fd("<sphere>", fd);
		else if (scene->objects.array[i]->type == OBJECT_TYPE_CYLINDER)
			ft_putstr_fd("<cylinder>", fd);
		else if (scene->objects.array[i]->type == OBJECT_TYPE_CONE)
			ft_putstr_fd("<cone>", fd);
		ft_putstr_fd(";\n\tmaterial:\t\"", fd);
		ft_putstr_fd(scene->materials.array
		[scene->objects.array[i]->material]->name, fd);
		write_objects_info_extra(scene, fd, i);
	}
}

void	write_objects_info_extra(t_scene *scene, int fd, int i)
{
	ft_putstr_fd("\";\n\tposition:\t[", fd);
	ft_putnbr_fd(scene->objects.array[i]->position.x, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->objects.array[i]->position.y, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->objects.array[i]->position.z, fd);
	ft_putstr_fd("];\n\torientation:\t[", fd);
	ft_putnbr_fd(scene->objects.array[i]->orientation.x, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->objects.array[i]->orientation.y, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(scene->objects.array[i]->orientation.z, fd);
	ft_putstr_fd("];\n", fd);
	if (scene->objects.array[i]->type != OBJECT_TYPE_PLANE)
	{
		ft_putstr_fd("\tradius:\t\t", fd);
		ft_putnbr_fd(scene->objects.array[i]->radius, fd);
		ft_putendl_fd(";\n}\n", fd);
	}
	else
		ft_putendl_fd("}\n", fd);
}
