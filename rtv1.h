/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/11 07:36:49 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>
# include <sys/time.h>

# define PROGRAM_NAME				"RTv1"

# define READ_BUFF_SIZE				10240

# define SCENE_FILE_EXTENSION		".rt"
# define CURRENT_TIME_STR_LENGTH	24
# define JSON_SCENE_NAME			"scene_name"
# define JSON_CAMERA				"camera"

# define WIN_SIZE_W					1916.0
# define WIN_SIZE_H					1064.0
# define IMG_SIZE_W					1536.0
# define IMG_SIZE_H					1024.0

# define IMG_INDT_W					10
# define IMG_INDT_H					10

# define MESSAGE_BOX_W				1000
# define MESSAGE_BOX_H				500
# define MESSAGE_BOX_IDNT			30

# define VIEWPORT_SIZE_W			1.5
# define VIEWPORT_SIZE_H			1
# define VIEWPORT_DISTANCE			1

# define LIGHT_TYPE_AMBIENT			0
# define LIGHT_TYPE_POINT			1
# define LIGHT_TYPE_DIRECTIONAL		2

# define OBJECT_TYPE_PLANE			0
# define OBJECT_TYPE_SPHERE			1
# define OBJECT_TYPE_CYLINDER		2
# define OBJECT_TYPE_CONE			3

# define REFLECTION_DEPTH			3
# define DRAW_DISTANCE_MIN			0.00001
# define DRAW_DISTANCE_MAX			1000000

# define TEXT_COLOR 				0xFFFFFF

# define NOTHING_SELECTED			-1
# define LIGHT_SELECTED				0
# define OBJECT_SELECTED			1
# define SHADE_UNSELECTED			0.5

# define MULTI_SAMPLING_RATE		8

# define MOTION_BLUR_BUFFERS		20

# define EFFECTS_QUANTITY			11
# define NO_EFFECT					0
# define EFFECT_PIXELATION			1
# define EFFECT_CARTOON				8
# define EFFECT_GRAYSCALE			3
# define EFFECT_NEGATIVE			4
# define EFFECT_RED_CHANNEL			5
# define EFFECT_GREEN_CHANNEL		6
# define EFFECT_BLUE_CHANNEL		7
# define EFFECT_DEPTH_MAP			10
# define EFFECT_FOG					9
# define EFFECT_OUTLINE_MAP			2

# define DEPTH_MAP_INCREMENT		2
# define DEPTH_MAP_MIN				8
# define DEPTH_MAP_MAX				1024

# define PIXELATION_INCREMENT		2
# define PIXELATION_MAX				200
# define PIXELATION_MIN				4

# define CAMERA_MOVEMENT_INCREMENT	10
# define CAMERA_ROTATION_INCREMENT	15


# define LIGHT_INTENSITY_INCREMENT	0.1
# define LIGHT_INTENSITY_MAX		1.0
# define LIGHT_INTENSITY_MIN		0.0

# define OBJECT_MOVEMENT_INCREMENT	10
# define OBJECT_ROTATION_INCREMENT	30

# define FALSE						0
# define TRUE						1

# define BUTTON_UP					0
# define BUTTON_DOWN				1
# define IN_MOVE					2

# define LEFT_MOUSE_BUTTON			1
# define RIGHT_MOUSE_BUTTON			2
# define MIDDLE_MOUSE_BUTTON		3
# define MOUSE_SCROLL_UP			4
# define MOUSE_SCROLL_DOWN			5

# define A							0
# define S							1
# define D							2
# define H							4
# define Q							12
# define W							13
# define E							14
# define PLUS						24
# define MINUS						27
# define O							31
# define I							34
# define P							35
# define RETURN						36
# define L							37
# define LESS						43
# define M							46
# define MORE						47
# define SPACE						49
# define ESC						53
# define HOME						115
# define PAGE_UP					116
# define END						119
# define PAGE_DOWN					121
# define ARROW_LEFT					123
# define ARROW_RIGHT				124
# define ARROW_DOWN					125
# define ARROW_UP					126

# define PI							3.14159265

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
	
	t_vector			position;
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
	t_vector			direction;
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
	int					active_object;
	
	char				*file_name_with_path;
	char				*scene_name;

	t_color				background;

	t_cameras			cameras;
	t_lights			lights;
	t_objects			objects;
	t_materials			materials;

	t_color				*frame_buffer;

	int					in_motion_blur;
	int					motion_blur_key;
	int					buffer_id;
	t_color				**motion_blur_buffers;

	double				*depth_buffer;
	int					*got_depth;
	int					depth_map_k;
	t_color				*depth_frame_buffer;

	int					*object_buffer;
	int					*got_object;

	int					anti_aliasing;
	int					*aliasing_buffer;

	int					effect;

	int					pixelation_k;

	int					got_color;
	t_color				picked_color;

	int					x_mouse_position;
	int					y_mouse_position;

	int					middle_mouse_button;

	int					material_source;
	int					material_target;

	int					show_help;

	int					quantity_lines;
}						t_scene;

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


void    write_scene_info(t_scene *scene, int fd);
void	write_cameras_info(t_scene *scene, int fd);
void	write_lights_info(t_scene *scene, int fd);
void	write_lights_info_extra(t_scene *scene, int fd, int i);
void	write_materials_info(t_scene *scene, int fd);
void	write_objects_info(t_scene *scene, int fd);
void	write_objects_info_extra(t_scene *scene, int fd, int i);

void	create_file_name(t_scene *scene, char **file_name);
void    get_current_time_string(char *time_string);
void    save_scene(t_scene *scene);

void	check_file(t_scene *scene, char *file_name);

char	*delete_whitespaces(char *line);
void	copy_without_whitespaces(char *line, char *clean_line);
int	count_whitespaces(char *line);
int	is_whitespace(char c);

int    compare_key(t_scene *scene, char *key, char *value);
char    *get_text_value(char *line);

char	*skip_white_spaces(char *line);
int	parse_string(t_scene *scene, char *line);

void	read_scene(t_scene *scene, char *file_name);

void					put_error_pn(char *str);

void	get_lights_statistics(t_scene *scene);
void	get_objects_statistics(t_scene *scene);

void	info_header_and_author(t_mlx *mlx);

void	info_help(t_mlx *mlx);
void	info_author(t_mlx *mlx);

void	show_help(t_global *global);
void	put_help_rect(t_mlx *mlx);

void	put_material_color_sample(t_mlx *mlx, int color);
int		mouse_key_release(int key, int x, int y, t_global *global);
void	get_material(int x, int y, t_global *global);
void	apply_material(int x, int y, t_global *global);

void	change_light_intensity(t_scene *scene, int key);

void	change_light(t_scene *scene, int key);

void	pick_color(t_scene *scene, int x, int y);

void    init_motion_blur_buffer(t_scene *scene);

void	get_macro_pixel(t_scene *scene, int pitch);
t_color	get_average_color(t_scene *scene, int pitch);

t_color	effect_outline(t_scene *scene, int i);


t_color	get_channel_diff(t_color c1, t_color c2);
int	need_to_smooth(t_scene *scene, int i);

t_color	mix_color(t_color c1, t_color c2);

void	change_effect_grade(t_scene *scene, int key);

void	anti_aliasing(t_scene *scene, t_pixel *pixel, double *rand);

t_color	effect_depth(t_scene *scene, int i);

void		fill_depth_buffer(t_scene *scene, t_pixel pixel, double closest);

void	get_jitter(double *random);
void		get_point_properties(t_scene *scene, t_point *point, t_object *object);

void	motion_blur_script(t_global *global);

void	motion_blur(t_color *frame_buffer, t_color **motion_blur_frame_buffers);

void		get_normal(t_point *point, t_object *object);

t_color	effect_fog(t_scene *scene, int i, t_color color);

void					init_frame_buffer(t_scene *scene);
void					init_object_buffer(t_scene *scene);
void					init_depth_buffer(t_scene *scene);
void					init_aliasing_buffer(t_scene *scene);

void					clean_frame_buffer(t_scene *scene);
void					clean_object_buffer(t_scene *scene);
void					clean_depth_buffer(t_scene *scene);
void					clean_aliasing_buffer(t_scene *scene);

void					fill_frame_buffer(t_scene *scene, t_pixel pixel);
void					fill_aliasing_buffer(t_scene *scene);
void					final_processing(t_mlx *mlx, t_scene *scene);

void					effect_pixelation(t_scene *scene);


double					direct_and_diffuse_light(t_scene *scene,
						t_point point, t_vector pixel, int i);

int						main(int argc, char **argv);

t_scene					*init_scene(int argc, char **argv);

void	check_scene(char *file_name);
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

void					get_pixel_color(t_scene *scene, t_vector camera, t_pixel *pixel, int reflection_depth);
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

void					move_camera(t_scene *scene, int key);
void					rotate_camera(t_scene *scene, int key);
void					move_object(t_scene *scene, int key);
void					rotate_object(t_scene *scene, int key);

void					move_light(t_scene *scene, int key);
void					rotate_light(t_scene *scene, int key);

void					get_mouse_position(t_scene *scene, int x, int y);
int						select_object(int x, int y, t_global *global);
void					change_camera(t_scene *scene);
void					change_effect(t_scene *scene);

void					put_scene_summary_1(t_scene *scene, t_mlx *mlx);
void					put_scene_summary_2(t_scene *scene, t_mlx *mlx);
void					put_scene_summary_3(t_scene *scene, t_mlx *mlx);
void					put_scene_summary_4(t_scene *scene, t_mlx *mlx);

void					put_status_1(t_scene *scene, t_mlx *mlx);
void					put_status_2(t_scene *scene, t_mlx *mlx);
void					put_status_3(t_scene *scene, t_mlx *mlx);
void					object_info_1(t_scene *scene, t_mlx *mlx);
void					light_info(t_scene *scene, t_mlx *mlx);
void					put_status_5(t_scene *scene, t_mlx *mlx);
void					put_status_5a(t_scene *scene, t_mlx *mlx);
void					put_status_6(t_scene *scene, t_mlx *mlx);
void					put_status_7(t_scene *scene, t_mlx *mlx);

void					info_control_1(t_mlx *mlx);
void					info_control_2(t_mlx *mlx);
void					info_control_3(t_mlx *mlx);
void					info_control_4(t_mlx *mlx);
void					info_render_1(t_mlx *mlx);
void					info_render_2(t_mlx *mlx);

void					put_coordinates(t_scene *scene, t_mlx *mlx);
void					put_color(t_scene *scene, t_mlx *mlx);
void					put_color_sample(t_mlx *mlx, int color);
void					put_scene_file_name(t_scene *scene, t_mlx *mlx);

#endif
