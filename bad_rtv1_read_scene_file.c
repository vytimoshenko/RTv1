/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:13:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/10 05:06:01 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	read_scene(t_scene *scene, char *file_name)
{
	int		fd;
	int		y;
	char	*line;

	check_file(scene, file_name);
	fd = open(file_name, O_RDONLY);
	y = -1;
	while (++y < scene->quantity_lines)
	{
		if (!(get_next_line(fd, &line)))
			break ;
		// if (parse_string(scene, line) == -1)
		// 	put_error_pn("invalid scene file data");
		ft_memdel((void *)&line);
	}
	close(fd);
}

void	check_file(t_scene *scene, char *file_name)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 1;
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		if (ret == -1)
			ft_put_errno(PROGRAM_NAME);
		if (ret == 0 && scene->quantity_lines == 0)
			put_error_pn("scene file is empty");
		if (ret == 0)
			break ;
		ft_memdel((void *)&line);
		scene->quantity_lines++;
	}
	ft_memdel((void *)&line);
	close(fd);
}

int	parse_string(t_scene *scene, char *line)
{
	char	*key;
	char	*key_start;
	int		i;

	key_start = line;
	i = 0;
	while (*line++ != ':')
		i++;
	key = ft_strnew(i);
	ft_strncpy(key, key_start, i);
	if (compare_key(scene, key, line) == -1)
		return (-1);
	ft_strdel(&key);
	return (0);
}

int    compare_key(t_scene *scene, char *key, char *value)
{
    if (!(ft_strcmp(key, JSON_SCENE_NAME)))
    	if (!(scene->scene_name = get_text_value(value)))
			return (-1);
    // else if (!(ft_strcmp(key, JSON_CAMERA)))
    //     scene->cameras.array = get_value(value);
	// else
	// 	return (-1);
	return (0);
}

char    *get_text_value(char *line)
{
    int     i;
    char    *value;
    
    // if (*line++ != ':')
    //     return (NULL);
	// line++;
    // if (*line != '"')
    //     return (NULL);
    // line++;
    i = 0;
    while (line[i] != '"')
        i++;
    value = ft_strnew(i);
    ft_strncpy(value, line, i);
    return (value);
}
