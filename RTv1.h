/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/02/27 06:30:03 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>
# include <sys/time.h>

# define PROGRAM_NAME			"RTv1"

# define WIN_SIZE_W 			2170
# define WIN_SIZE_H				1240
# define IMG_SIZE_W				1800.0
# define IMG_SIZE_H				1200.0

# define IMG_INDT_W 			10
# define IMG_INDT_H 			10

# define VIEWPORT_SIZE_W		1.5
# define VIEWPORT_SIZE_H		1
# define VIEWPORT_DISTANCE		1

// # define VIEWPORT_SIZE_W		6
// # define VIEWPORT_SIZE_H		4
// # define VIEWPORT_DISTANCE		3

# define NO_OBJECT_SELECTED		-1
# define SHADE_UNSELECTED		0.5		

# define DRAW_DISTANCE_MIN		0.001
# define DRAW_DISTANCE_MAX		1000000

# define LIGHT_TYPE_AMBIENT		0
# define LIGHT_TYPE_POINT		1
# define LIGHT_TYPE_DIRECTIONAL	2

# define REFLECTION_DEPTH		3

# define TEXT_COLOR  			0xFFFFFF
# define BACKGROUND_COLOR  		{0x00, 0x00, 0x00}

# define EFFECTS_QUANTITY		3
# define NO_EFFECT				0
# define EFFECT_GRAYSCALE		1
# define EFFECT_NEGATIVE		2
# define EFFECT_CARTOON			3

# define FALSE					0
# define TRUE					1

# define BUTTON_UP				0
# define BUTTON_DOWN			1
# define IN_MOVE				2

# define LEFT_MOUSE_BUTTON		1
# define MIDDLE_MOUSE_BUTTON	3
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5

# define A						0
# define S						1
# define D						2
# define Q						12
# define W						13
# define E						14
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

# define PI 3.14159265

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_matrix
{
	double				a[3];
	double				b[3];
	double				c[3];
}						t_matrix;

typedef struct			s_point
{
	t_vector			xyz;
	t_color				color;
	double 				specular;
	double				reflective;
	
	double				light;
	t_vector			n;

	double				light_intensity;
	t_color				final_color;
}						t_point;

// typedef struct			s_light
// {
// 	t_vector			light;
// 	double 				t_max;
// }						t_light;

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
	float				frame_time;
}						t_mlx;




typedef struct			s_sphere
{
	int					id;
	t_color 			color;
	double				specular;
	double				reflective;
	double				radius;
	t_vector 			center;

	double				t1;
	double				t2;
	double				closest;
	int					null;
}						t_sphere;

typedef struct			s_spheres
{
	int					quantity;
	t_sphere			**array;
}						t_spheres;

typedef struct			s_planes
{
	int					quantity;
	// t_plane				**array;
}						t_planes;

typedef struct			s_cylinders
{
	int					quantity;
	// t_plane				**array;
}						t_cylinders;

typedef struct			s_cones
{
	int					quantity;
	// t_cone				**array;
}						t_cones;

typedef struct			s_light
{
	int					num;
	
	int					type;

	double				intensity;
	t_vector 			position;
	t_vector 			direction;
}						t_light;

typedef struct			s_light_sources
{
	int					quantity;
	t_light				**array;
}						t_light_sources;


typedef struct			s_camera
{
	int					id;
	t_vector 			position;
	t_vector 			direction;
	t_vector 			sin;
	t_vector 			cos;
}						t_camera;



typedef struct			s_status
{
	char				*file_name_with_path;
	
	int					cameras_quantity;
	int					current_camera;
	t_camera			**cameras;

	// double				x_rotation;
	// double				y_rotation;
	// double				z_rotation;
	// double				sin_x;
	// double				cos_x;
	// double				sin_y;
	// double				cos_y;
	// double				sin_z;
	// double				cos_z;

	t_matrix			m;
	t_light_sources		light_sources;
	t_spheres			spheres;
	t_planes			planes;
	t_cones				cones;
	t_cylinders			cylinders;

	int					*object_buffer;
	int					*got_object;
	int					active_object;

	int					effect;

	int					hide_info;

	double				zoom;

	int					total_objects_quantity;

	int					x_mouse_position;
	int					y_mouse_position;

	int					middle_mouse_button;
	double				x_move;
	double				y_move;
	double				x_shift;
	double				y_shift;
}						t_status;

typedef struct			s_global
{
	t_status			*status;
	t_mlx				*mlx;
}						t_global;

int						final_processing(t_status *status, int x, int y, t_color color);
t_color					shade_unselesected(t_status *status, int x, int y, t_color color);
t_color					effect_grayscale(t_color color);
t_color					effect_negative(t_color color);
t_color					effect_cartoon(t_color color);

void					get_sin_cos(t_camera *camera);



t_vector	rotate_direction(t_vector vector, t_camera *camera);



void					fill_object_buffer(t_status *status, int x, int y, int id);

void					get_image(t_status *status, t_mlx *mlx);
void					put_pixel(t_mlx *mlx, int x, int y, int color);
t_vector				canvas_to_viewport(int x, int y);

t_color       				get_color(t_spheres	spheres, t_light_sources lights_sources,
						t_vector camera, t_vector viewport_pixel, int reflection_depth,
						t_status *status, int x, int y);

t_sphere				get_intersection(t_spheres	spheres, t_vector camera, t_vector viewport_pixel, double t_min, double t_max);
void	    			sphere_intersection(t_sphere *sphere, t_vector camera, t_vector viewport_pixel);
double					get_lightning(t_point point, t_light_sources lights_sources,
t_vector view, t_spheres	spheres_arr);

int						is_in_shadow(t_spheres	spheres_arr, t_vector point, t_vector light, double t_max);
double					diffuse(t_vector normal, t_vector light);
double					specular(t_vector normal, t_vector light, t_vector pixel, double specular);
t_vector				reflect_ray(t_vector ray, t_vector normal);

double					deg_to_rad(int degrees);
double 					dot(t_vector v1, t_vector v2);
double      			length(t_vector v1);
t_vector    			add(t_vector v1, t_vector v2);
t_vector 				substract(t_vector v1, t_vector v2);
t_vector    			multiply_sv(double k, t_vector v);
t_vector    			multiply_mv(t_matrix m, t_vector v);

int						unite_color_channels(t_color color);
t_color    				add_color(t_color c1, t_color c2);
t_color    				multiply_color(double k, t_color c);


int						main(int argc, char **argv);

void					init_object_buffer(t_status *status);
void					clean_object_buffer(t_status *status);


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
int						keyboard_key_press(int key, t_global *global);
int						close_window(t_global *global);

void					move_camera(t_status *status, int key);
void					rotate_camera(t_status *status, int key);
void					move_object(t_status *status, int key);

void					get_mouse_position(t_status *status, int x, int y);
int						select_object(int x, int y, t_global *global);
void					change_camera(t_status *status);
void					change_effect(t_status *status);

void					put_scene_summary_1(t_status *status, t_mlx *mlx);
void					put_scene_summary_2(t_status *status, t_mlx *mlx);
void					put_status_1(t_status *status, t_mlx *mlx);
void					put_status_2(t_status *status, t_mlx *mlx);
void					put_status_3(t_status *status, t_mlx *mlx);

void					put_control_keys(t_mlx *mlx);
void					put_render_info_1(t_mlx *mlx);
void					put_render_info_2(t_mlx *mlx);
void					put_bottom_line(t_status *status, t_mlx *mlx);

#endif
