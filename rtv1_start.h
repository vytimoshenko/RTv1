/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_start.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 12:17:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/22 23:12:54 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_START_H

# define RTV1_START_H

# define FALSE			0
# define TRUE			1

//START
t_scene		*init_scene(int argc, char **argv);
void		set_initial_status(t_scene *scene);
void		get_lights_statistics(t_scene *scene);
void		get_objects_statistics(t_scene *scene);

//MLX
t_mlx		*init_mlx(void);
void		clean_mlx(t_mlx *mlx);
void		put_mlx_error(t_mlx *mlx, char *str);

//DRAW
void		draw(t_global *global);
void		count_frames(t_mlx *mlx, struct timeval start, struct timeval end);
void		update_interface_only(t_global *global);
void		put_error_pn(char *str);

//MAIN
int			main(int argc, char **argv);

#endif