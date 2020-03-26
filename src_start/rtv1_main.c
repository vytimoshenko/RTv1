/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:09:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/26 16:51:15 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int	main(int argc, char **argv)
{
	t_global	global;

	global.scene = init_scene(argc, argv);
	global.mlx = init_mlx();
	draw(&global);
	loop(&global);
	exit(0);
}
