/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_rtv1_read_scene_file.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:13:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/10 04:24:05 by mperseus         ###   ########.fr       */
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
	printf("%s\n", line);
	// if (*line != '{')
	// 	return (-1);
	if (parse_string(scene, line) == -1)
		put_error_pn("invalid scene file data");
	free(line);
}

int	parse_string(t_scene *scene, char *line)
{
	char	*key;
	char	*value;
	char	*key_start;
	char	*value_start;
	int		i;

	if (*line != '"')
		return (-1);
	line++;
	key_start = line;
	i = 0;
	while (*line++ != '"')
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
		return (0);
        // scene->scene_name = get_text_value(value);
    // else if (!(ft_strcmp(key, JSON_CAMERA)))
    //     scene->cameras.array = get_value(value);
	else
		return (-1);
	return (0);
}

char    *get_text_value(char *line)
{
    int     i;
    char    *value;
    
    if (*(line++) != ':')
        return (NULL);
    if (*line != '"')
        return (NULL);
    line++;
    i = 0;
    while (line[i] != '"')
        i++;
    value = ft_strnew(i);
    ft_strncpy(value, line, i);
    return (value);
}
