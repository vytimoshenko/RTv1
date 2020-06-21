/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_start_pixel_buffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 11:45:06 by vitaly            #+#    #+#             */
/*   Updated: 2020/06/21 13:26:43 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void    init_pixel_buffer(t_scene *scene)
{
	if (!(scene->pixel_buffer = (t_pix *)ft_memalloc(sizeof(t_pix)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
}

void    clean_pixel_buffer(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pixel_buffer[i].obj_id = EMPTY;
		ft_memset(&scene->pixel_buffer[i].color, 0, sizeof(t_clr));
	}
}
