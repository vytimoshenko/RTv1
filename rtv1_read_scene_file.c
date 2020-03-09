/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:13:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/10 01:39:48 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	read_scene(t_scene *scene, char *file_name)
{
	int		fd;
	int     ret;
	char	*line;

	(void)scene;
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	ret = 1;
	while (ret > 0)
	{
		if (!(ret = get_next_line(fd, &line)))
			break ;
		printf("dirty line:%s\n", line);
		line = delete_whitespaces(&line);
		// ft_strdel(&line);
		// printf("whitespaces: %d\n", count_whitespaces(line));
		printf("clean line:%s\n", line);
		// if (parse_string(scene, line) == -1)
		// 	put_error_pn("invalid scene file");
	}
	if (line)
		free(line);
	close(fd);
}

int	parse_string(t_scene *scene, char *line)
{
	char	*tmp;
	char	*start;
	int i;

	tmp = NULL;
	if (!(line = skip_white_spaces(line)))
		return (-1);
	if (*line == '{')
		return (0);
	if (*line == '"')
	{
		line++;
		i = 0;
		start = line;
		while (*line++ != '"')
			i++;
		tmp = ft_strnew(i);
		ft_strncpy(tmp, start, i);
        get_key(scene, tmp, line);
		ft_strdel(&tmp);
	}
	return (0);
}

char	*skip_white_spaces(char *line)
{
	while (*line && (*line == '\t' || *line == '\n' || *line == '\v' ||
				*line == '\r' || *line == '\f' || *line == ' '))
		line++;
	if (!line)
		return (NULL);
	return (line);
}

void    get_key(t_scene *scene, char *key, char *value)
{
    if (!(ft_strcmp(key, JSON_SCENE_NAME)))
        scene->scene_name = get_value(value);
    // else if (!(ft_strcmp(key, JSON_CAMERA)))
    //     scene->cameras.array = get_value(value);
}

char    *get_value(char *line)
{
    int     i;
    char    *value;
    
    if (*(line++) != ':')
        return (NULL);
    if (!(line = skip_white_spaces(line)))
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

char	*delete_whitespaces(char **line)
{
	int		len;
	char	*clean_line;

	len = ft_strlen(*line) - count_whitespaces(*line);
	clean_line = ft_strnew(len);
	copy_without_whitespaces(*line, clean_line);
	ft_strdel(line);
	return (clean_line);
}

void	copy_without_whitespaces(char *line, char *clean_line)
{
	int	in_quotes;
	
	in_quotes = FALSE;
	while (*line)
	{
		if (in_quotes == FALSE)
		{
			while (is_whitespace(*line))
				line++;
		}
		if (*line == '"')
			in_quotes = in_quotes == FALSE ? TRUE : FALSE;
		*clean_line = *line;
		line++;
		clean_line++;
	}
}

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f' ||
	c == ' ')
		return (1);
	return (0);
}

int	count_whitespaces(char *line)
{
	int i;
	int	in_quotes;

	i = 0;
	in_quotes = FALSE;
	while (*line)
	{
		if (*line == '"')
			in_quotes = in_quotes == FALSE ? TRUE : FALSE;
		if (in_quotes == FALSE)
			i += is_whitespace(*line);
		line++;
	}
	printf("number %d\n", i);
	return (i);
}