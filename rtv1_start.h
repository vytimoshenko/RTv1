/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_start.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 12:17:36 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/26 12:06:29 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_START_H

# define RTV1_START_H

# define FALSE	0
# define TRUE	1

//MAIN
int			main(int argc, char **argv);

//INIT SCENE
t_scene		*init_scene(int argc, char **argv);
void		set_initial_status(t_scene *scene);
void		get_lights_statistics(t_scene *scene);
void		get_objects_statistics(t_scene *scene);

//INIT MLX
t_mlx		*init_mlx(void);
void		clean_mlx(t_mlx *mlx);
void		put_mlx_error(t_mlx *mlx, char *str);

//PIXEL_BUFFER
void   		init_pixel_buffer(t_scene *scene);
void    	clean_pixel_buffer(t_scene *scene);

//DRAW
void		draw(t_global *global);
void		count_frames(t_mlx *mlx, struct timeval start, struct timeval end);
void		update_interface_only(t_global *global);
void		update_interface_and_frame(t_global *global);
void		put_error_pn(char *str);

#endif
