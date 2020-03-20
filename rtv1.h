/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 16:52:59 by mperseus         ###   ########.fr       */
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
// # include "rtv1_file.h"

# define PROGRAM_NAME					"RTv1"

# define SAVE_PATH						"./saves/"
# define SCREENSHOT_PATH				"./screenshots/"

// # define WIN_SIZE_W						1916
// # define WIN_SIZE_H						1064
// # define IMG_SIZE_W						1536.0
// # define IMG_SIZE_H						1024.0
# define WIN_SIZE_W						1340
# define WIN_SIZE_H						808
# define IMG_SIZE_W						960.0
# define IMG_SIZE_H						768.0
# define IMG_INDT_W						10
# define IMG_INDT_H						10

# define TEXT_COLOR 					0xFFFFFF

# define HELP_BOX_W						1000
# define HELP_BOX_H						500

# define INFO_BOX_W						500
# define INFO_BOX_H						400

# define INFO_BOX_INDENTATION			30

// # define MESSAGE_BOX_W					700
// # define MESSAGE_BOX_H					80
// # define MESSAGE_BOX_INDENTATION		10


// # define VIEWPORT_SIZE_W				1.5
# define VIEWPORT_SIZE_W				1.25
# define VIEWPORT_SIZE_H				1
# define VIEWPORT_DISTANCE				1

# define LIGHT_TYPE_AMBIENT				0
# define LIGHT_TYPE_POINT				1
# define LIGHT_TYPE_DIRECTIONAL			2

# define OBJECT_TYPE_PLANE				0
# define OBJECT_TYPE_SPHERE				1
# define OBJECT_TYPE_CYLINDER			2
# define OBJECT_TYPE_CONE				3

# define REFLECTION_DEPTH				3
# define DRAW_DISTANCE_MIN				0.00001
# define DRAW_DISTANCE_MAX				1000000

# define NOTHING_SELECTED				-1
# define LIGHT_SELECTED					0
# define OBJECT_SELECTED				1
# define SHADE_UNSELECTED				0.5

# define MOTION_BLUR_BUFFERS			20

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

# define CAMERA_MOVEMENT_INCREMENT		10
# define CAMERA_ROTATION_INCREMENT		15

# define LIGHT_INTENSITY_INCREMENT		0.1
# define LIGHT_INTENSITY_MAX			1.0
# define LIGHT_INTENSITY_MIN			0.0

# define OBJECT_MOVEMENT_INCREMENT		10
# define OBJECT_ROTATION_INCREMENT		30

# define BUTTON_UP						0
# define BUTTON_DOWN					1
# define IN_MOVE						2

# define LEFT_MOUSE_BUTTON				1
# define RIGHT_MOUSE_BUTTON				2
# define MIDDLE_MOUSE_BUTTON			3
# define MOUSE_SCROLL_UP				4
# define MOUSE_SCROLL_DOWN				5

# define A								0
# define S								1
# define D								2
# define H								4
# define Q								12
# define W								13
# define E								14
# define Y								16
# define T								17
# define PLUS							24
# define MINUS							27
# define O								31
# define U								32
# define I								34
# define P								35
# define RETURN							36
# define L								37
# define J								38
# define LESS							43
# define M								46
# define MORE							47
# define SPACE							49
# define ESC							53
# define HOME							115
# define PAGE_UP						116
# define END							119
# define PAGE_DOWN						121
# define ARROW_LEFT						123
# define ARROW_RIGHT					124
# define ARROW_DOWN						125
# define ARROW_UP						126

# define FALSE							0
# define TRUE							1

# define PI								3.14159265

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
	double				refractive;
	double				transparency;

	double				light;
	t_vector			n;

	double				light_intensity;
	t_color				final_color;
}						t_point;

typedef struct			s_pixel
{
	int					i;
	int					x;
	int					y;
	
	t_vector			pos;
	t_color				color;

	// int					object_id;
}						t_pixel;

typedef struct			s_camera
{
	int					id;
	t_vector			position;
	t_vector			direction;
	double				zoom;
	t_vector			sin;
	t_vector			cos;
}						t_camera;


typedef struct			s_object
{
	int					id;
	int					type;
	int					material;
	t_color				color;
	double				specular;
	double				reflective;
	double				refractive;
	double				transparency;
	double				radius;
	t_vector			position;
	t_vector			orientation;
	double				k;

	double				t1;
	double				t2;
	double				closest;
	int					null;
}						t_object;


typedef struct			s_light
{
	int					id;
	int					type;
	int					off;
	double				intensity;
	t_vector			position;
	t_vector			direction;
}						t_light;

typedef struct			s_material
{
	int					id;
	char				*name;
	t_color				color;
	double				specular;
	double				reflective;
	double				transparency;
	double				refractive;
}						t_material;

typedef struct			s_cameras
{
	int					quantity;
	t_camera			**array;
}						t_cameras;

typedef struct			s_lights
{
	int					quantity;
	int					quantity_ambient;
	int					quantity_directional;
	int					quantity_point;
	t_light				**array;
}						t_lights;

typedef struct			s_materials
{
	int					quantity;
	t_material			**array;
}						t_materials;

typedef struct			s_objects
{
	int					quantity;
	int					quantity_planes;
	int					quantity_spheres;
	int					quantity_cylinders;
	int					quantity_cones;
	t_object			**array;
}						t_objects;

typedef struct			s_scene
{
	int					active_camera;
	int					active_light;
	int					active_material;
	int					active_object;
	
	char				*file_name_with_path;
	char				*name;
	char				*author;

	t_color				background;

	t_cameras			cameras;
	t_lights			lights;
	t_objects			objects;
	t_materials			materials;

	t_color				*frame_buffer;

	t_color				*anaglyph_left_buffer;
	t_color				*anaglyph_right_buffer;

	t_color				*anaglif_left_buffer;

	double				*depth_buffer;
	int					*got_depth;
	t_color				*depth_frame_buffer;

	int					*object_buffer;
	int					*got_object;

	int					antialiasing;
	int					*aliasing_buffer;
	double				aliasing_rate;

	int					effect;

	int					k_cartoon;
	int					k_pixelation;
	int					k_depth_map;
	int					got_color;
	t_color				picked_color;

	int					x_mouse_position;
	int					y_mouse_position;

	int					middle_mouse_button;

	int					material_source;
	int					material_target;

	int					show_help;
	int					show_info;

	int					quantity_lines;
}						t_scene;

typedef struct			s_t_min_max
{
	double				t;
	double				t_min;
	double				t_max;
}						t_t_min_max;

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

typedef struct			s_global
{
	t_scene				*scene;
	t_mlx				*mlx;
}						t_global;

# include "rtv1_file.h"
# include "rtv1_interface.h"

int			main(int argc, char **argv);

//READ AND PARSE SCENE FILE
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

void		get_macro_pixel(t_scene *scene, int pitch);
void		pick_color(t_scene *scene, int x, int y);

void		get_material(int x, int y, t_global *global);
int			apply_material(int x, int y, t_global *global);

void		change_light(t_scene *scene, int key);
void		change_light_intensity(t_scene *scene, int key);
t_color		get_average_color(t_scene *scene, int pitch);

//EFFECTS
t_color		effect_fog(t_scene *scene, int i, t_color color);
t_color		effect_depth(t_scene *scene, int i);
void		fill_depth_buffer(t_scene *scene, t_pixel pixel, double closest);
t_color		effect_outline(t_scene *scene, int i);

t_color		mix_color(t_color c1, t_color c2);
void		change_effect_grade(t_scene *scene, int key);

void		effect_pixelation(t_scene *scene);

//ANTIALIASING
void		run_antialiasing(t_scene *scene);
void		get_multisample_color(t_scene *scene, t_pixel *pixel, double *rand);
int			need_to_smooth(t_scene *scene, int i);
void		add_adjacent_pixels(t_scene *scene, int i);
void		get_jitter(double *random);

void		get_normal(t_point *point, t_object *object);
void		get_point_properties(t_scene *scene, t_point *point, t_object *object);

void		init_frame_buffer(t_scene *scene);
void		init_object_buffer(t_scene *scene);
void		init_depth_buffer(t_scene *scene);
void		init_aliasing_buffer(t_scene *scene);

void		clean_frame_buffer(t_scene *scene);
void		clean_object_buffer(t_scene *scene);
void		clean_depth_buffer(t_scene *scene);
void		clean_aliasing_buffer(t_scene *scene);

void		fill_frame_buffer(t_scene *scene, t_pixel pixel);
void		fill_aliasing_buffer(t_scene *scene);
void		final_processing(t_mlx *mlx, t_scene *scene);


//CONTROL
int			mouse_move(int x, int y, t_global *global);
int			mouse_key_press(int key, int x, int y, t_global *global);
int			mouse_key_release(int key, int x, int y, t_global *global);
int			close_window(t_global *global);

int			keyboard_key_press(int key, t_global *global);
void		keyboard_key_press_extra_1(int key, t_global *global);
void		keyboard_key_press_extra_2(int key, t_global *global);

void		move_camera(t_scene *scene, int key);
void		rotate_camera(t_scene *scene, int key);
void		move_object(t_scene *scene, int key);
void		rotate_object(t_scene *scene, int key);

void		move_light(t_scene *scene, int key);
void		rotate_light(t_scene *scene, int key);

void		get_mouse_position(t_scene *scene, int x, int y);
int			select_object(int x, int y, t_global *global);
void		change_camera(t_scene *scene);
void		change_effect(t_scene *scene);
void		change_material(t_scene *scene, int key);

t_color		pixel_post_processing(t_scene *scene, int i, t_color color);
t_color		shade_unselesected(t_scene *scene, int i, t_color color);
t_color		effect_grayscale(t_color color);
t_color		effect_negative(t_color color);
t_color		effect_cartoon(t_scene *scene, t_color color);

//RAYTRACING

void		trace_rays(t_scene *scene);
void		get_pixel_position(t_scene *scene, t_pixel *pixel);
void		get_sin_cos(t_camera *camera);
void		rotate_pixel(t_pixel *pixel, t_camera *camera);
void		put_pixel(t_mlx *mlx, int x, int y, int color);

void		get_pixel_color(t_scene *scene, t_vector camera, t_pixel *pixel, int reflection_depth);
// void		get_point_properties(t_point *point, t_object *object);
void		fill_object_buffer(t_scene *scene, t_pixel pixel, int id);
int			is_in_shadow(t_objects	objects_arr, t_vector point, t_vector light, double t_max);

//INTERSECTIONS
t_object	get_intersection(t_objects	objects, t_vector camera, t_vector pixel, t_t_min_max t_min_max);
t_object	check_closest_object(t_object closest_object, double closest);
void		select_object_intersect_function(t_object *object, t_vector camera, t_vector pixel);

void		plane(t_object *object, t_vector camera, t_vector pixel);
void		sphere(t_object *object, t_vector camera, t_vector pixel);
void		cylinder(t_object *object, t_vector camera, t_vector pixel);
void		cone(t_object *object, t_vector camera, t_vector pixel);

//LIGHT
double		get_lightning(t_scene *scene, t_point point, t_vector pixel);
double		diffuse_and_specular_light(t_scene *scene, t_point point, t_vector pixel, int i);
double		diffuse(t_vector normal, t_vector light);
double		specular(t_vector normal, t_vector light, t_vector pixel, double specular);
t_vector	reflect_ray(t_vector ray, t_vector normal);

//VECTOR OPERATIONS
double		deg_to_rad(int degrees);
double		dot(t_vector v1, t_vector v2);
double		length(t_vector v1);
t_vector	normalize(t_vector v);

t_vector	add(t_vector v1, t_vector v2);
t_vector	substract(t_vector v1, t_vector v2);
t_vector	multiply_sv(double k, t_vector v);

//COLOR OPERATIONS
int			unite_color_channels(t_color color);
t_color		split_color(int color);
t_color		get_channel_diff(t_color c1, t_color c2);
t_color		add_color(t_color c1, t_color c2);
t_color		multiply_color(double k, t_color c);



void   	 clean_anaglyph_buffers(t_scene *scene);
void   	 init_anaglyph_buffers(t_scene *scene);
void 		get_final_anaglyph(t_scene *scene, t_mlx *mlx);

t_color	effect_average(t_color color);


void	draw_macro_pixel(t_scene *scene, t_color color, int pitch);

#endif
