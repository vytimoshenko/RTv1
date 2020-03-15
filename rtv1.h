/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:05:42 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/15 11:58:45 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H

# define RTV1_H

# include "rtv1_define.h"
# include "rtv1_struct.h"

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
void		show_interface(t_global *global);

//READ AND PARSE SCENE FILE
void		read_scene(t_scene *scene, char *file_name);
void		divide_to_items(t_scene *scene, char *line);
int			count_items(char *line);
int			parse_each_item(t_scene *scene, char **items_array);

int			count_items_by_type(t_scene *scene, char *item_line);
int    		define_item_type(t_scene *scene, char *type);
void		put_error_wrong_scene_data(char *wrong_data, char *message);
void		save_quantities(t_scene *scene);
void		allocate_memory(t_scene *scene);

int			parse_item_line(t_scene *scene, char *item_line);
int			parse_item_description(t_scene *scene, int type_id, char *description);
char		*prepare_value_to_write(char *value);
char		*any_whitespace_to_space(char *value);

void    	parse_item_by_property(t_scene *scene, int type_id, char *property, char *value);
void		parse_scene_description(t_scene *scene, char *property, char *value);
void		parse_camera_description(t_scene *scene, char *property, char *value);
void		parse_light_description(t_scene *scene, char *property, char *value);
int			find_light_type(char *value);

void		parse_material_description(t_scene *scene, char *property, char *value);
void		parse_object_description(t_scene *scene, char *property, char *value);
int    		find_object_type(char *value);
int     	find_object_material(t_scene *scene, char *value);

t_vector	parse_vector(char *value);
t_color		parse_color(char *value);
int			check_and_get_int_value(char *value);
void		validate_color(char *value, t_color color);

char		*delete_whitespaces(char *line);
int			count_whitespaces(char *line);
int			is_whitespace(char c);
void		copy_without_whitespaces(char *line, char *clean_line);

//SAVE SCENE FILE
void    	save_scene(t_scene *scene, t_mlx *mlx);
void		create_save_file_name(t_scene *scene, char **file_name);
void    	get_current_time_string(char *time_string);

void    	write_all_info(t_scene *scene, int fd);
void		write_scene_info(t_scene *scene, int fd);
void		write_cameras_info(t_scene *scene, int fd);
void		write_lights_info(t_scene *scene, int fd);
void		write_lights_info_extra(t_scene *scene, int fd, int i);

void		write_materials_info(t_scene *scene, int fd);
void		write_materials_info_extra(t_scene *scene, int fd, int i);
void		write_objects_info(t_scene *scene, int fd);
void		write_objects_info_extra_1(t_scene *scene, int fd, int i);
void		write_objects_info_extra_2(t_scene *scene, int fd, int i);

//SAVE SCREENSHOT
void		save_screenshot(t_scene *scene, t_mlx *mlx);
void		create_screenshot_file_name(t_scene *scene, char **file_name);

void		put_error_pn(char *str);

void		get_lights_statistics(t_scene *scene);
void		get_objects_statistics(t_scene *scene);

void    	init_motion_blur_buffer(t_scene *scene);

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

void		motion_blur_script(t_global *global);
void		motion_blur(t_color *frame_buffer, t_color **motion_blur_frame_buffers);
void		effect_pixelation(t_scene *scene);

//ANTIALIASING
void		anti_aliasing(t_scene *scene, t_pixel *pixel, double *rand);
int			need_to_smooth(t_scene *scene, int i);
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
t_color		effect_cartoon(t_color color);

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

//INTERFACE
void		put_scene_summary_1(t_scene *scene, t_mlx *mlx);
void		put_scene_summary_2(t_scene *scene, t_mlx *mlx);
void		put_scene_summary_3(t_scene *scene, t_mlx *mlx);
void		put_scene_summary_4(t_scene *scene, t_mlx *mlx);
void		put_scene_summary_5(t_scene *scene, t_mlx *mlx);

void		put_status_1(t_scene *scene, t_mlx *mlx);
void		put_status_2(t_scene *scene, t_mlx *mlx);
void		put_status_3(t_scene *scene, t_mlx *mlx);
void		object_info_1(t_scene *scene, t_mlx *mlx);
void		light_info(t_scene *scene, t_mlx *mlx);
void		put_status_5(t_scene *scene, t_mlx *mlx);
void		put_status_5a(t_scene *scene, t_mlx *mlx);
void		put_status_6(t_scene *scene, t_mlx *mlx);
void		put_status_7(t_scene *scene, t_mlx *mlx);

void		info_control_1(t_mlx *mlx);
void		info_control_2(t_mlx *mlx);
void		info_control_3(t_mlx *mlx);
void		info_control_4(t_mlx *mlx);
void		info_render_1(t_mlx *mlx);
void		info_render_2(t_mlx *mlx);

void		put_coordinates(t_scene *scene, t_mlx *mlx);
void		put_color(t_scene *scene, t_mlx *mlx);
void		put_color_sample(t_mlx *mlx, int color);
void		put_scene_file_name(t_scene *scene, t_mlx *mlx);

void		info_header_and_author(t_mlx *mlx);
void		info_help(t_mlx *mlx);
void		info_author(t_mlx *mlx);
void		show_help(t_global *global);
void		draw_box(t_mlx *mlx, int size_w, int size_h);
void		message_box(t_mlx *mlx, char *message_title, char *message_content);
void		put_material_color_sample(t_mlx *mlx, int color);

void		material_info(t_scene *scene, t_mlx *mlx);

#endif
