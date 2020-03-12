/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:13:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/12 04:45:02 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	read_scene(t_scene *scene, char *file_name)
{
	char	buff[READ_BUFF_SIZE + 1];
	int		fd;
	int     ret;
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
	int		objects_count;
	int		object_size;
	char	*object_line;

	objects_count = count_objects(line);
printf("SCENE OBJECTS: %d\n", objects_count);
	i = -1;
	while (++i < objects_count)
	{
		object_size = count_object_size(line);
		object_line = (char *)(malloc(sizeof(char) * (object_size + 1)));
		ft_strncpy(object_line, line, object_size);
		object_line[object_size] = '\0';
printf("%d:\t%s\n", i, object_line);
		if (parse_object_line(scene, object_line) == -1)
			return (-1);
		while (--object_size >= 0)
			line++;
		ft_strdel(&object_line);
	}
	return (0);
}

int	count_objects(char *line)
{
	int	i;
	
	i = 0;
	while (*line++)
		i = *line == '{' ? i + 1 : i;
	return (i);
}

int	count_object_size(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] != '}')
		i++;
	i += 2;
	return (i);
}

int	parse_object_line(t_scene *scene, char *object_line)
{
	int	i;
	char *tmp;
	(void)scene;
	if (*object_line != '"')
		return (-1);
	object_line++;
	i = 0;
	while (object_line[i] != '"')
		i++;
	tmp = ft_strnew(i);
	ft_strncpy(tmp, object_line, i);
	printf("TYPE:\t%s\n", tmp);
	while (--i >= -1)
		object_line++;
	if (*object_line != ':')
		return (-1);
	object_line++;
	printf("PROP:\t%s\n", object_line);
	parse_object_by_type(scene, tmp, object_line);
	ft_strdel(&tmp);
	return (0);
}

int    parse_object_by_type(t_scene *scene, char *object_type, char *description)
{
	if (!(ft_strcmp(object_type, JSON_SCENE)))
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

int		parse_scene_description(t_scene *scene, char *description)
{
	(void)scene;
	(void)description;
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
