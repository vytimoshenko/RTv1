/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_effect.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:52:44 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 19:16:10 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_EFFECT_H

# define RTV1_EFFECT_H

# include "rtv1.h"

# define SHADE_UNSELECTED				0.5

# define EFFECTS_QUANTITY				6
# define NO_EFFECT						0
# define EFFECT_GRAYSCALE				1
# define EFFECT_NEGATIVE				2
# define EFFECT_CARTOON					3
# define EFFECT_PIXELATION				4
# define EFFECT_DEPTH					5
# define EFFECT_OUTLINE					6

# define ANTIALIASING_COLOR_THRESHOLD	16
# define ANTIALIASING_OUTLINE_WIDTH		3
# define MULTI_SAMPLING_RATE			8

# define CARTOON_INCREMENT				2
# define CARTOON_INIT					16
# define CARTOON_MAX					64
# define CARTOON_MIN					8

# define PIXELATION_INCREMENT			2
# define PIXELATION_INIT				16
# define PIXELATION_MAX					256
# define PIXELATION_MIN					4
		
# define DEPTH_MAP_INCREMENT			2
# define DEPTH_MAP_INIT					128
# define DEPTH_MAP_MIN					32
# define DEPTH_MAP_MAX					512

# define OUTLINE_INCREMENT				1
# define OUTLINE_INIT					2
# define OUTLINE_MIN					0
# define OUTLINE_MAX					4

t_color		effect_depth(t_scene *scene, int i);
void		fill_depth_buffer(t_scene *scene, t_pixel pixel, double closest);
t_color		effect_outline(t_scene *scene, int i);

void		change_effect_grade(t_scene *scene, int key);

void		effect_pixelation(t_scene *scene);
t_color		get_average_color(t_scene *scene, int pitch);
void	    draw_macro_pixel(t_scene *scene, t_color color, int pitch);

t_color		pixel_post_processing(t_scene *scene, int i, t_color color);
t_color		shade_unselesected(t_scene *scene, int i, t_color color);
t_color		effect_grayscale(t_color color);
t_color		effect_negative(t_color color);
t_color		effect_cartoon(t_scene *scene, t_color color);

void 	    effect_anaglyph(t_scene *scene, t_mlx *mlx);
void		final_processing(t_mlx *mlx, t_scene *scene);

void		fill_aliasing_buffer(t_scene *scene);
int			need_to_smooth(t_scene *scene, int i);
void		add_adjacent_pixels(t_scene *scene, int i);
void		get_multisample_color(t_scene *scene, t_pixel *pixel, double *rand);

void		run_antialiasing(t_scene *scene);
void		get_jitter(double *random);

//COLOR OPERATIONS
int			unite_color_channels(t_color color);
t_color		average_color_channels(t_color color);
t_color		split_color(int color);
t_color		get_channel_diff(t_color c1, t_color c2);

t_color		add_color(t_color c1, t_color c2);
t_color		multiply_color(double k, t_color c);
t_color		mix_color(t_color c1, t_color c2);
#endif