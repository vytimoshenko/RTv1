/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/04 02:55:15 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>
# include <sys/time.h>

# define PROGRAM_NAME				"RTv1"

# define WIN_SIZE_W					2180
# define WIN_SIZE_H					1240
# define IMG_SIZE_W					1800.0
# define IMG_SIZE_H					1200.0

# define IMG_INDT_W					10
# define IMG_INDT_H					10

# define VIEWPORT_SIZE_W			1.5
# define VIEWPORT_SIZE_H			1

// # define VIEWPORT_SIZE_W			6
// # define VIEWPORT_SIZE_H			4
// # define VIEWPORT_DISTANCE			3

# define NO_OBJECT_SELECTED			-1
# define SHADE_UNSELECTED			0.5

# define DRAW_DISTANCE_MIN			0.001
# define DRAW_DISTANCE_MAX			1000000

# define LIGHT_TYPE_AMBIENT			0
# define LIGHT_TYPE_POINT			1
# define LIGHT_TYPE_DIRECTIONAL		2

# define OBJECT_TYPE_PLANE			0
# define OBJECT_TYPE_SPHERE			1
# define OBJECT_TYPE_CONE			2
# define OBJECT_TYPE_CYLINDER		3

// enum					e_effects
// {
// 	o_object = 1,
// 	o_cylinder,
// 	o_cone,
// 	o_plane,
// 	o_parab,
// 	o_torus
// };

# define REFLECTION_DEPTH			3

# define TEXT_COLOR 				0xFFFFFF
# define BACKGROUND_COLOR  			{0x00, 0x00, 0x00}

// enum					e_effects
// {
// 	EFFECTS_QUANTITY = 3,
// 	NO_EFFECT,
// 	EFFECT_GRAYSCALE,
// 	EFFECT_NEGATIVE,
// 	EFFECT_CARTOON,
// };

# define MOTION_BLUR_BUFFERS		20

# define EFFECTS_QUANTITY			7
# define NO_EFFECT					0
# define EFFECT_PIXELATION			1
# define EFFECT_CARTOON				2
# define EFFECT_GRAYSCALE			3
# define EFFECT_NEGATIVE			4
# define EFFECT_RED_CHANNEL			5
# define EFFECT_GREEN_CHANNEL		6
# define EFFECT_BLUE_CHANNEL		7

# define CAMERA_ZOOM_INCREMENT		2
# define CAMERA_ZOOM_MIN			0.0625
# define CAMERA_ZOOM_MAX			16

# define CAMERA_MOVEMENT_INCREMENT	10
# define CAMERA_ROTATION_INCREMENT	15

# define OBJECT_MOVEMENT_INCREMENT	10
# define OBJECT_ROTATION_INCREMENT	30

# define FALSE						0
# define TRUE						1

# define BUTTON_UP					0
# define BUTTON_DOWN				1
# define IN_MOVE					2

# define LEFT_MOUSE_BUTTON			1
# define MIDDLE_MOUSE_BUTTON		3
# define MOUSE_SCROLL_UP			4
# define MOUSE_SCROLL_DOWN			5

# define A							0
# define S							1
# define D							2
# define Q							12
# define W							13
# define E							14
# define PLUS						24
# define MINUS						27
# define RETURN						36
# define LESS						43
# define M							46
# define MORE						47
# define SPACE						49
# define ESC						53
# define PAGE_UP					116
# define PAGE_DOWN					121
# define ARROW_LEFT					123
# define ARROW_RIGHT				124
# define ARROW_DOWN					125
# define ARROW_UP					126

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

typedef struct			s_point
{
	t_vector			xyz;
	t_color				color;
	double				specular;
	double				reflective;


	double				light;
	t_vector			n;

	double				light_intensity;
	t_color				final_color;
}						t_point;

typedef struct			s_pixel
{
	int					x;
	int					y;
	
	t_vector			position;
	t_color				color;

	// int					object_id;
}						t_pixel;

// typedef struct			s_light
// {
// 	t_vector			light;
// 	double				t_max;
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

typedef struct			s_object
{
	int					id;
	int					type;
	t_color				color;
	double				specular;
	double				reflective;
	double				transparency;
	double				radius;
	t_vector			center;
	t_vector			direction;
	double				k;

	double				t1;
	double				t2;
	double				closest;
	int					null;
}						t_object;

typedef struct			s_objects
{
	int					quantity;
	t_object			**array;
}						t_objects;

typedef struct			s_light
{
	int					num;

	int					type;

	double				intensity;
	t_vector			position;
	t_vector			direction;
}						t_light;

typedef struct			s_light_sources
{
	int					quantity;
	t_light				**array;
}						t_light_sources;

typedef struct			s_camera
{
	int					id;
	t_vector			position;
	t_vector			direction;
	double				zoom;
	t_vector			sin;
	t_vector			cos;
}						t_camera;

typedef struct			s_scene
{
	char				*file_name_with_path;

	char				*scene_name;
	int					cameras_quantity;
	int					current_camera;
	t_camera			**cameras;

	int					materials_quantity;

	t_light_sources		light_sources;
	t_objects			objects;

	t_color				*frame_buffer;

	int					in_motion_blur;
	int					motion_blur_key;
	int					buffer_id;
	t_color				**motion_blur_frame_buffers;

	int					*object_buffer;
	int					*got_object;
	int					active_object;

	int					effect;

	int					hide_info;

	double				zoom;

	int					total_objects_quantity;
	int					planes_quantity;
	int					objects_quantity;
	int					cylinders_quantity;
	int					cones_quantity;

	int					x_mouse_position;
	int					y_mouse_position;

	int					middle_mouse_button;
	double				x_move;
	double				y_move;
	double				x_shift;
	double				y_shift;
}						t_scene;

typedef struct			s_global
{
	t_scene				*scene;
	t_mlx				*mlx;
}						t_global;

void		get_point_properties(t_point *point, t_object *object);

void	motion_blur_script(t_global *global);

void	motion_blur(t_color *frame_buffer, t_color **motion_blur_frame_buffers);

void		get_normal(t_point *point, t_object *object);


// void					put_pixel_into_buffer(t_scene *scene, int x, int y, t_color color);
void					init_frame_buffer(t_scene *scene);
void					put_pixel_into_buffer(t_scene *scene, t_pixel pixel);
void					final_processing(t_mlx *mlx, t_scene *scene);

void					effect_pixelation(t_scene *scene);


double					add_direct_and_diffuse_light(t_scene *scene,
						t_point point, t_vector pixel, int i);

int						main(int argc, char **argv);

t_scene					*init_scene(int argc, char **argv);
void					init_object_buffer(t_scene *scene);
void					clean_object_buffer(t_scene *scene);
// void					check_argument(t_scene *scene, char *arg);
void					reset_scene(t_scene *scene);

t_mlx					*init_mlx(void);
void					reset_render_scene(t_mlx *mlx);
void					clean_mlx(t_mlx *mlx);
void					put_mlx_error(t_mlx *mlx, char *str);

void					loop(t_global *global);
void					draw(t_global *global);
void					update_info_only(t_global *global);
void					put_info_to_window(t_global *global);
void					count_frames(t_mlx *mlx, struct timeval start,
						struct timeval end);

void					trace_rays(t_scene *scene);
void				get_pixel_position(t_scene *scene, t_pixel *pixel);
void					get_sin_cos(t_camera *camera);
void				rotate_pixel(t_pixel *pixel, t_camera *camera);
void					put_pixel(t_mlx *mlx, int x, int y, int color);

t_color					get_pixel_color(t_scene *scene, t_vector camera, t_pixel *pixel, int reflection_depth);
// void					get_point_properties(t_point *point, t_object *object);

t_object				get_intersection(t_objects	objects, t_vector camera, t_vector pixel, double t_min, double t_max);
void					select_object_function(t_object *object, t_vector camera, t_vector pixel);
void					plane(t_object *object, t_vector camera, t_vector pixel);
void					sphere(t_object *object, t_vector camera, t_vector pixel);
void					cylinder(t_object *object, t_vector camera, t_vector pixel);
void					cone(t_object *object, t_vector camera, t_vector pixel);

double					get_lightning(t_scene *scene, t_point point, t_vector pixel);
void					fill_object_buffer(t_scene *scene, t_pixel pixel, int id);

int						is_in_shadow(t_objects	objects_arr, t_vector point, t_vector light, double t_max);
double					diffuse(t_vector normal, t_vector light);
double					specular(t_vector normal, t_vector light, t_vector pixel, double specular);
t_vector				reflect_ray(t_vector ray, t_vector normal);

double					dot(t_vector v1, t_vector v2);
double					length(t_vector v1);
t_vector				normalize(t_vector v);
t_vector				add(t_vector v1, t_vector v2);
t_vector				substract(t_vector v1, t_vector v2);
t_vector				multiply_sv(double k, t_vector v);

double					deg_to_rad(int degrees);
int						unite_color_channels(t_color color);
t_color					split_color(int color);
t_color					add_color(t_color c1, t_color c2);
t_color					multiply_color(double k, t_color c);

t_color					pixel_post_processing(t_scene *scene, int i, t_color color);
t_color					shade_unselesected(t_scene *scene, int i,
						t_color color);
t_color					effect_grayscale(t_color color);
t_color					effect_negative(t_color color);
t_color					effect_cartoon(t_color color);

int						mouse_move(int x, int y, t_global *global);
int						mouse_key_press(int key, int x, int y,
						t_global *global);
int						keyboard_key_press(int key, t_global *global);
void					extra_keyboard_key_press(int key, t_global *global);
int						close_window(t_global *global);

void					zoom_camera(t_scene *scene, int key);
void					move_camera(t_scene *scene, int key);
void					rotate_camera(t_scene *scene, int key);
void					move_object(t_scene *scene, int key);
void					rotate_object(t_scene *scene, int key);

void					get_mouse_position(t_scene *scene, int x, int y);
int						select_object(int x, int y, t_global *global);
void					change_camera(t_scene *scene);
void					change_effect(t_scene *scene);

void					put_scene_summary_1(t_scene *scene, t_mlx *mlx);
void					put_scene_summary_2(t_scene *scene, t_mlx *mlx);
void					put_scene_summary_3(t_scene *scene, t_mlx *mlx);
void					put_scene_summary_4(t_scene *scene, t_mlx *mlx);

void					put_scene_1(t_scene *scene, t_mlx *mlx);
void					put_scene_2(t_scene *scene, t_mlx *mlx);
void					put_scene_3(t_scene *scene, t_mlx *mlx);
void					put_scene_4(t_scene *scene, t_mlx *mlx);
void					put_scene_5(t_scene *scene, t_mlx *mlx);
void					put_scene_6(t_scene *scene, t_mlx *mlx);

void					put_control_keys(t_mlx *mlx);
void					put_render_info_1(t_mlx *mlx);
void					put_render_info_2(t_mlx *mlx);
void					put_bottom_line(t_scene *scene, t_mlx *mlx);

#endif
