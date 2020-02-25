/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:09:39 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/25 03:14:05 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int	main(int argc, char **argv)
{
	t_global	global;

	global.status = init_status(argc, argv);
	global.mlx = init_mlx();
	draw(&global);
	loop(&global);
	exit(0);
}
