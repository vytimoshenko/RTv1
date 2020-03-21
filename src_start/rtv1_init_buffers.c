/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_init_buffers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 06:40:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 11:01:01 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void    init_frame_buffer(t_scene *scene)
{
	if (!(scene->frame_buffer = (t_color *)ft_memalloc(sizeof(t_color)
	* IMG_SIZE_W * IMG_SIZE_H)))
		ft_put_errno(PROGRAM_NAME);
}






