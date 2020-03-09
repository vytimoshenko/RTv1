/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_read_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:47:48 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/29 20:09:42 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// void	trim_map_name(t_map *map, char *file_name)
//  {
//  	char *trimmed_file_name;
//  	char *file_name_end;
//  @@ -45,29 +34,29 @@ void	trim_file_name(t_view *view, char *file_name)
//  		file_name_end[0] = '.';
//  		file_name_end[1] = '.';
//  		file_name_end[2] = '.';
//  		file_name = ft_strjoin(trimmed_file_name, file_name_end);
//  		file_name = ft_strjoin(trimmed_file_name, (char *)file_name_end);
//  		ft_strdel(&trimmed_file_name);
//  		ft_strdel(&file_name_end);
//  	}
//  	view->map_name = file_name;
//  	map->map_name = file_name;
//  }

// void	trim_file_name(t_map *map, char *file_name_with_path)
// {
// 	char	*tmp;

// 	map->map_name_with_path = ft_strdup(file_name_with_path);
// 	if ((ft_strrchr(file_name_with_path, '/')))
// 	{
// 		tmp = ft_strrchr(file_name_with_path, '/');
// 		tmp++;
// 		map->map_name = ft_strdup(tmp);
// 	}
// 	else
// 		map->map_name = ft_strdup(file_name_with_path);
// }

void	split_line(t_map *map, char *line, int y)
{
	char	**split_line;

	if (!(map->xyz[y] = malloc(sizeof(int) * map->x_size)))
		ft_put_errno(PROGRAM_NAME);
	if (!(map->clr[y] = malloc(sizeof(int) * map->x_size)))
		ft_put_errno(PROGRAM_NAME);
	split_line = ft_strsplit(line, ' ');
	free(line);
	save_map_line(map, split_line, y);
	ft_arrdel(split_line);
	free(split_line);
}

void	read_map(t_scene *scene, char *file_name)
{
	int		fd;
	char	*line;
	int		y;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) == -1)
		ft_put_errno(PROGRAM_NAME);
	if (!(map->xyz = malloc(sizeof(int *) * map->y_size)))
		ft_put_errno(PROGRAM_NAME);
	if (!(map->clr = malloc(sizeof(int *) * map->y_size)))
		ft_put_errno(PROGRAM_NAME);
	y = -1;
	while (++y < map->y_size)
	{
		if (!(get_next_line(fd, &line)))
			break ;
		split_line(map, line, y);
	}
	map->points = map->y_size * map->x_size;
	trim_file_name(map, file_name);
	close(fd);
}
