/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_start_pixel_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 10:58:58 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/27 17:26:54 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void    init_pixel_buffer(t_scene *scene)
{
	if (!(scene->pixel_buffer = (t_pixel *)ft_memalloc(sizeof(t_pixel)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
}

void    clean_pixel_buffer(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pixel_buffer[i].object_id = EMPTY;
		ft_memset(&scene->pixel_buffer[i].color, 0, sizeof(t_color));
	}
}
