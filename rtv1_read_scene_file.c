/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 07:13:29 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/09 07:14:20 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	read_scene(t_scene *scene, char *file_name)
{
	int		fd;
	char	*line;
	int		y;
	int ret;

	(void)scene;
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	y = -1;
	while (++y < 3)
	{
		if (!(ret = get_next_line(fd, &line)))
			break ;
		// split_line(map, line, y);
		if (parse_string(scene, line) == -1)
			put_error_pn("invalid scene file");
		ft_strdel(&line);
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
		if (!(ft_strcmp(tmp, "scene_name")))
		{
			if (*(line++) != ':')
				return (-1);
			if (!(line = skip_white_spaces(line)))
				return (-1);
			printf("%s GGGG", line);
			ft_strdel(&tmp);
			if (*line != '"')
				return (-1);
			line++;
			i = 0;
			start = line;
			while (*line++ != '"')
				i++;
			tmp = ft_strnew(i);
			ft_strncpy(tmp, start, i);
		}
			scene->scene_name = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	printf("%s\n", tmp);
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