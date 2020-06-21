/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_clean_pix_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 11:45:06 by vitaly            #+#    #+#             */
/*   Updated: 2020/06/21 14:58:42 by vitaly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1.h"

void	clean_pix_buffer(t_scene *scene)
{
	int	i;

	i = -1;
	while (++i < IMG_SIZE_W * IMG_SIZE_H)
	{
		scene->pix_buff[i].obj_id = EMPTY;
		ft_memset(&scene->pix_buff[i].color, 0, sizeof(t_clr));
	}
}
