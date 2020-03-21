/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_clean_buffers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:35:14 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 11:01:22 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	clean_frame_buffer(t_scene *scene)
{
	int i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
		scene->frame_buffer[i] = (t_color){0, 0, 0};
}








