/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:13:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/12 07:17:52 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	read_scene(t_scene *scene, char *file_name)
{
	int		fd;
	int     ret;
	char	buff[READ_BUFF_SIZE + 1];
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	ret = read(fd, buff, READ_BUFF_SIZE);
	buff[ret] = '\0';
	if (read(fd, buff, READ_BUFF_SIZE))
		put_error_pn("scene file is too big");
	close(fd);
	line = NULL;
	line = delete_whitespaces(buff);
printf("INITIAL FILE CONTENT:\n%s\n", buff);
printf("LINE TO PARSE:\n%s\nSYMBOLS: %zu\n\n", line, ft_strlen(line));
	if (parse_all(scene, line) == -1)
		put_error_pn("invalid scene file data");
	free(line);
}

int	parse_all(t_scene *scene, char *line)
{
	int		i;
	int		items_count;
	int		item_size;
	char	*item_line;

	if ((items_count = count_items(line)) == -1)
		return (-1);
printf("SCENE ITEMS: %d\n\n", items_count);
	i = -1;
	while (++i < items_count)
	{
		item_size = count_item_size(line);
		item_line = (char *)(malloc(sizeof(char) * (item_size + 1)));
		ft_strncpy(item_line, line, item_size);
		item_line[item_size] = '\0';
printf("%d:\t%s\n", i, item_line);
		if (parse_item_line(scene, item_line) == -1)
			return (-1);
		while (--item_size >= 0)
			line++;
		ft_strdel(&item_line);
	}
	return (0);
}

int	count_items(char *line)
{
	int	i;
	int	a;
	int	b;
	
	a = 0;
	i = 0;
	while (line[i++] != '\0')
		a = line[i] == '{' ? a + 1 : a;
	b = 0;
	i = 0;
	while (line[i++] != '\0')
		b = line[i] == '}' ? b + 1 : b;
	if (a != b)
		return (-1);
	return (a);
}

int	count_item_size(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] != '}')
		i++;
	i++;
	return (i);
}

int	parse_item_line(t_scene *scene, char *item_line)
{
	int		i;
	char	*type;
	char	*description;
	
	i = 0;
	while (item_line[i] != '{')
		i++;
	type = ft_strnew(i);
	ft_strncpy(type, item_line, i);
	while (--i >= -1)
		item_line++;
	while (item_line[i] != '}')
		i++;
	description = ft_strnew(i);
	ft_strncpy(description, item_line, i);
printf("TYPE:\t%s\n", type);
printf("DESC:\t%s\n\n", description);
	parse_item_by_type(scene, type, description);
	ft_strdel(&type);
	ft_strdel(&description);
	return (0);
}

int    parse_item_by_type(t_scene *scene, char *type, char *description)
{
	if (!(ft_strcmp(type, JSON_SCENE)))
		return (parse_scene_description(scene, description));
    else if (!(ft_strcmp(type, JSON_CAMERA)))
		return (parse_camera_description(scene, description));
	else if (!(ft_strcmp(type, JSON_LIGHT)))
		return (parse_light_description(scene, description));
	else if (!(ft_strcmp(type, JSON_MATERIAL)))
		return (parse_material_description(scene, description));
	else if (!(ft_strcmp(type, JSON_OBJECT)))
		return (parse_object_description(scene, description));
	else
		return (-1);
	return (0);
}

int		parse_scene_description(t_scene *scene, char *description)
{
	int		i;
	char	*property;
	char	*value;
	
	if (!(*description))
		return (0);
	i = 0;
	while (description[i] != ':')
		i++;
	property = ft_strnew(i);
	ft_strncpy(property, description, i);
	while (--i >= -1)
		description++;
	while (description[i] != ';')
		i++;
	value = ft_strnew(i);
	ft_strncpy(value, description, i);
printf("PRP:\t%s\n", property);
printf("VAL:\t%s\n\n", value);
	// parse_item_by_type(scene, type, description);
	ft_strdel(&property);
	ft_strdel(&value);
	while (--i >= -1)
		description++;
	parse_scene_description(scene, description);
	(void)scene;
	return (0);
}

int    parse_description_by_type(t_scene *scene, char *object_type, char *description)
{
	if (!(ft_strcmp(object_type, JSON_NAME)))
		return (parse_scene_description(scene, description));
    else if (!(ft_strcmp(object_type, JSON_CAMERA)))
		return (parse_camera_description(scene, description));
	else if (!(ft_strcmp(object_type, JSON_LIGHT)))
		return (parse_light_description(scene, description));
	else if (!(ft_strcmp(object_type, JSON_MATERIAL)))
		return (parse_material_description(scene, description));
	else if (!(ft_strcmp(object_type, JSON_OBJECT)))
		return (parse_object_description(scene, description));
	else
		return (-1);
	return (0);
}

int		parse_camera_description(t_scene *scene, char *description)
{
		(void)scene;
	(void)description;
	return (0);
}

int		parse_light_description(t_scene *scene, char *description)
{
		(void)scene;
	(void)description;
	return (0);
}

int		parse_material_description(t_scene *scene, char *description)
{
		(void)scene;
	(void)description;
	return (0);
}

int		parse_object_description(t_scene *scene, char *description)
{
		(void)scene;
	(void)description;
	return (0);
}
