/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/20 06:21:02 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>
# include <sys/time.h>

# define PROGRAM_NAME			"fractol"

# define WIN_SIZE_W 			1000
# define WIN_SIZE_H				1000
# define IMG_SIZE_W				1000.0
# define IMG_SIZE_H				1000.0

# define VIEWPORT_SIZE_W		1
# define VIEWPORT_SIZE_H		1
# define VIEWPORT_DISTANCE		1

# define DRAW_DISTANCE_MIN		1
# define DRAW_DISTANCE_MAX		1000000

# define LIGHT_TYPE_AMBIENT		0
# define LIGHT_TYPE_POINT		1
# define LIGHT_TYPE_DIRECTIONAL	2

# define TEXT_COLOR  			0xFFFFFF
# define BACK_COLOR  			0x555555

# define MIDDLE_MOUSE_BUTTON	3
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5

# define D						2
# define H						4
# define C						8
# define R						15
# define PLUS					24
# define MINUS					27
# define RETURN					36
# define LESS					43
# define MORE					47
# define SPACE					49
# define ESC					53
# define ARROW_LEFT				123
# define ARROW_RIGHT			124
# define ARROW_DOWN				125
# define ARROW_UP				126

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	int					*data;

	int					bits_per_pixel;
	int					size_line;
	int					endian;

	int					frames;
	int					fps;
	float				frame_time;
}						t_mlx;

// typedef struct			s_open_cl
// {
// 	cl_platform_id		platform_id;
// 	cl_device_id		device_id;
// 	cl_context			context;
// 	cl_command_queue	command_queue;
// 	cl_program			program;
// 	cl_kernel			kernel;

// 	char				*platform_name;
// 	char				*device_name;
// 	char				*driver_ver;
// 	cl_uint				device_comp_units;
// 	cl_uint				device_frequency;

// 	size_t				source_size;
// 	char				*source_str;
// 	char				*program_build_log;

// 	size_t				global_work_size;
// 	size_t				local_work_size;

// 	cl_mem				buf;

// 	int					execution_time;
// }						t_open_cl;

typedef struct			s_sphere
{
	int					color;
	double				radius;
	t_vector 			center;

	double				t1;
	double				t2;
}						t_sphere;

typedef struct			s_light
{
	int					type;

	double				intensity;
	t_vector 			position;
	t_vector 			direction;
}						t_light;

typedef struct			s_status
{
	t_vector			camera;

	int					lights_quantity;
	t_light				**lights_arr;

	int					spheres_quantity;
	t_sphere			**spheres_arr;

	int					hide_info;
	int					iter;
	int					pause;
	double				zoom;

	int					x_mouse_position;
	int					y_mouse_position;

	int					middle_mouse_button;
	double				x_move;
	double				y_move;
}						t_status;


typedef struct			s_global
{
	t_status			*status;
	t_mlx				*mlx;
}						t_global;

typedef struct			s_kernel_arg
{
	int					img_size_x;

	int					fractal_type;

	int					color_theme;
	int					iter;
	int					pause;
	double				zoom;

	double				x_center;
	double				y_center;
	double				x_shift;
	double				y_shift;

	double				x_julia;
	double				y_julia;
}						t_kernel_arg;

void					get_image(t_status *status, t_mlx *mlx);
void					put_pixel(t_mlx *mlx, int x, int y, int color);
int	        get_color(t_sphere	**spheres_arr, int spheres_quantity,
			t_light **lights_arr, int lights_quantity,
			t_vector camera, t_vector viewport_pixel);
t_vector				canvas_to_viewport(int x, int y);
void	    			sphere_intersect(t_sphere *sphere, t_vector camera, t_vector viewport_pixel);
double					get_lightning(t_vector point, t_vector normal, t_light **lights_arr, int lights_quantity);

double 					dot(t_vector v1, t_vector v2);
double      			length(t_vector v1);
t_vector    			multiply(double k, t_vector v);
t_vector    			add(t_vector v1, t_vector v2);
t_vector 				substract(t_vector v1, t_vector v2);

int						main(int argc, char **argv);

t_status				*init_status(int argc, char **argv);
void					check_argument(t_status *status, char *arg);
void					error_wrong_argument(void);
void					reset_status(t_status *status);

t_mlx					*init_mlx(void);
void					reset_render_status(t_mlx *mlx);
void					clean_mlx(t_mlx *mlx);
void					put_mlx_error(t_mlx *mlx, char *str);

void					loop(t_global *global);
void					draw(t_global *global);
void					update_info_only(t_global *global);
void					put_info_to_window(t_global *global);
void					count_frames(t_mlx *mlx, struct timeval start,
						struct timeval end);

int						mouse_move(int x, int y, t_global *global);
int						mouse_key_press(int key, int x, int y,
						t_global *global);
int						mouse_key_release(int key, int x, int y,
						t_global *global);
int						keyboard_key_press(int key, t_global *global);
int						close_window(t_global *global);

void					get_mouse_position(t_status *status, int x, int y);
void					control_zoom(t_status *status, int key);
void					control_mouse_zoom(t_status *status, int x, int y,
						int key);
void					control_shift(t_status *status, int key);
void					control_mouse_shift(t_status *status, int x, int y);

void					control_type(t_status *status, t_mlx *mlx);
void					control_iteration(t_status *status, int key);
void					control_colors(t_status *status);
void					control_device(t_global *global);
void					set_julia(t_status *status, int x, int y);

void					put_status_1(t_mlx *mlx);
void					put_status_2(t_status *status, t_mlx *mlx);
void					put_status_3(t_status *status, t_mlx *mlx);
void					put_status_4(t_status *status, t_mlx *mlx);
void					put_status_5(t_status *status, t_mlx *mlx);

// void					put_open_cl_info(t_open_cl *open_cl, t_mlx *mlx);
void					put_render_info_1(t_mlx *mlx);
void					put_render_info_2(t_mlx *mlx);
void					put_control_keys_1(t_status *status, t_mlx *mlx);
void					put_control_keys_2(t_mlx *mlx);

#endif
