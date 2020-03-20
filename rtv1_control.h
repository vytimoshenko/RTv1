/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_control.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 17:52:44 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/20 19:21:06 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_CONTROL_H

# define RTV1_CONTROL_H

# include "rtv1.h"

# define NOTHING_SELECTED				-1
# define LIGHT_SELECTED					0
# define OBJECT_SELECTED				1

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

void		change_light(t_scene *scene, int key);
void		change_light_intensity(t_scene *scene, int key);

void		get_material(int x, int y, t_global *global);
int			apply_material(int x, int y, t_global *global);

void		pick_color(t_scene *scene, int x, int y);

#endif