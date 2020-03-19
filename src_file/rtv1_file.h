/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 12:30:34 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/19 13:57:07 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_FILE_H

# define RTV1_FILE_H

# include "../rtv1.h"

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

#endif

