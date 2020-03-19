/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_save_screenshot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:37:34 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 14:08:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	save_screenshot(t_scene *scene, t_mlx *mlx)
{
	char		*file_name;
	SDL_Surface	*surface;

	file_name = NULL;
	surface = NULL;
	create_screenshot_file_name(scene, &file_name);
	if (SDL_Init(SDL_INIT_EVERYTHING))
		put_error_pn("SDL_Init");
	if (!(surface = SDL_CreateRGBSurfaceFrom(mlx->data, IMG_SIZE_W, IMG_SIZE_H,
	32, sizeof(int) * IMG_SIZE_W, 0, 0, 0, 0)))
		put_error_pn("SDL_CreateRGBSurfaceFrom");
	if (IMG_SaveJPG(surface, file_name, 100))
		put_error_pn("IMG_SaveJPG");
	message_box(mlx, SCREENSHOT_MESSAGE_TITLE, file_name);
	free(file_name);
	SDL_FreeSurface(surface);
}

void	create_screenshot_file_name(t_scene *scene, char **file_name)
{
	int		i;
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	char	time_string[CURRENT_TIME_STR_LENGTH];

	tmp1 = ft_strdup(scene->name);
	i = 0;
	while (tmp1[i++])
		tmp1[i] = tmp1[i] == ' ' ? '_' : tmp1[i];
	get_current_time_string(time_string);
	tmp2 = ft_strjoin(time_string, SCREENSHOT_FILE_EXTENSION);
	tmp3 = ft_strjoin(tmp1, tmp2);
	*file_name = ft_strjoin(SCREENSHOT_PATH, tmp3);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	ft_strdel(&tmp3);
}