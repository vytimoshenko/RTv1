/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 11:35:07 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./SDL2/headers/SDL.h"
# include "./SDL2/headers/SDL_image.h"
# include <math.h>
# include <sys/time.h>

# include "rtv1_structures.h"
# include "rtv1_file.h"
# include "rtv1_trace.h"
# include "rtv1_effect.h"
# include "rtv1_control.h"
# include "rtv1_interface.h"

# define PROGRAM_NAME	"RTv1"

# define FALSE			0
# define TRUE			1

int			main(int argc, char **argv);

t_scene		*init_scene(int argc, char **argv);
void		set_initial_status(t_scene *scene);

//MLX
t_mlx		*init_mlx(void);
void		clean_mlx(t_mlx *mlx);
void		put_mlx_error(t_mlx *mlx, char *str);

void		loop(t_global *global);
void		draw(t_global *global);
void		count_frames(t_mlx *mlx, struct timeval start, struct timeval end);
void		update_interface_only(t_global *global);

void		put_error_pn(char *str);

void		get_lights_statistics(t_scene *scene);
void		get_objects_statistics(t_scene *scene);

void		init_frame_buffer(t_scene *scene);

void		clean_frame_buffer(t_scene *scene);

void		fill_frame_buffer(t_scene *scene, t_pixel pixel);

#endif
