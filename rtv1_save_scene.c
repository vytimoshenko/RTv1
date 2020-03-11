/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_save_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 02:02:59 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/11 05:42:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	save_scene(t_scene *scene)
{
	int		fd;
	char	*file_name;

	file_name = NULL;
	// create_file_name(scene, &file_name);
	file_name = "Hello, world!";
	ft_putendl(file_name);
	if (!(fd = open(file_name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP
	| S_IWGRP | S_IROTH | S_IWOTH)))
		ft_put_errno(PROGRAM_NAME);
	// write(fd, (void *)status, sizeof(*status));
	// mlx_string_put(mlx->mlx, mlx->win, WIN_SIZE_W - 700, WIN_SIZE_H - 30,
	// TEXT_COLOR, "file saved:");
	// mlx_string_put(mlx->mlx, mlx->win, WIN_SIZE_W - 580, WIN_SIZE_H - 30,
	// TEXT_COLOR, file_name);
	write_scene_info(scene, fd);
	system("cat \"Hello, world!\"");
	// ft_strdel(&file_name);
	close(fd);
}

void	get_current_time_string(char *time_string)
{
	time_t		current_time;
	struct tm	*time_info;
	int			i;

	time(&current_time);
	time_info = localtime(&current_time);
	strftime(time_string, CURRENT_TIME_STR_LENGTH, "_%F_%T", time_info);
	i = 0;
	while (time_string[i++])
		time_string[i] = time_string[i] == ':' ? '-' : time_string[i];
}

void	create_file_name(t_scene *scene, char **file_name)
{
	int		i;
	char	*tmp1;
	char	*tmp2;
	char	time_string[CURRENT_TIME_STR_LENGTH];
	
	tmp1 = ft_strdup(scene->scene_name);
	i = 0;
	while (tmp1[i++])
		tmp1[i] = tmp1[i] == ' ' ? '_' : tmp1[i];
	get_current_time_string(time_string);
	tmp2 = ft_strjoin(time_string, SCENE_FILE_EXTENSION);
	*file_name = ft_strjoin(tmp1, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
}
