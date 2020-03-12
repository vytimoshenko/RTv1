/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:13:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/12 11:37:01 by mperseus         ###   ########.fr       */
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
	i = -1;
	while (++i < items_count)
	{
		item_size = count_item_size(line);
		item_line = (char *)(malloc(sizeof(char) * (item_size + 1)));
		ft_strncpy(item_line, line, item_size);
		item_line[item_size] = '\0';
		if (parse_item_line(scene, item_line) == -1)
			return (-1);
		while (--item_size >= 0)
			line++;
		ft_strdel(&item_line);
	}
	return (0);
}

int	parse_item_line(t_scene *scene, char *item_line)
{
	int		i;
	int		type_id;
	char	*type;
	char	*description;
	
	i = 0;
	while (item_line[i] != '{')
		i++;
	type = ft_strnew(i);
	ft_strncpy(type, item_line, i);
	type_id = define_item_type(scene, type);
	printf("type to parse - %d", type_id);
	while (--i >= -1)
		item_line++;
	while (item_line[i] != '}')
		i++;
	description = ft_strnew(i);
	ft_strncpy(description, item_line, i);
	parse_item_description(scene, type, description);
	ft_strdel(&type);
	ft_strdel(&description);
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

int    define_item_type(t_scene *scene, char *type)
{
	if (!(ft_strcmp(type, FILE_SCENE)))
		return(FILE_PARSE_SCENE);
    else if (!(ft_strcmp(type, FILE_CAMERA)))
	{
		scene->active_camera++;
		return (FILE_PARSE_CAMERA);
	}
	else if (!(ft_strcmp(type, FILE_LIGHT)))
	{
		scene->active_light++;
		return (FILE_PARSE_LIGHT);
	}
	else if (!(ft_strcmp(type, FILE_MATERIAL)))
	{
		scene->active_material++;
		return (FILE_PARSE_MATERIAL);
	}
	else if (!(ft_strcmp(type, FILE_OBJECT)))
	{
		scene->active_object++;
		return (FILE_PARSE_OBJECT);
	}
	else
		return (-1);
	return (0);
}