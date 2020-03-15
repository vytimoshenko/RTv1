/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_define.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 11:07:26 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/15 11:52:49 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_DEFINE_H

# define RTV1_DEFINE_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include "./SDL2/headers/SDL.h"
# include "./SDL2/headers/SDL_image.h"
# include <math.h>
# include <sys/time.h>

# define PROGRAM_NAME					"RTv1"

# define SAVE_PATH						"./saves/"
# define SCREENSHOT_PATH				"./screenshots/"

# define WIN_SIZE_W						1916.0
# define WIN_SIZE_H						1064.0
# define IMG_SIZE_W						1536.0
# define IMG_SIZE_H						1024.0
# define IMG_INDT_W						10
# define IMG_INDT_H						10

# define TEXT_COLOR 					0xFFFFFF

# define INFO_BOX_W						1000
# define INFO_BOX_H						500
# define INFO_BOX_INDENTATION			30

# define MESSAGE_BOX_W					700
# define MESSAGE_BOX_H					80
# define MESSAGE_BOX_INDENTATION		10

# define SCENE_FILE_EXTENSION			".rt"
# define SCREENSHOT_FILE_EXTENSION		".jpg"
# define CURRENT_TIME_STR_LENGTH		24

# define SAVE_MESSAGE_TITLE				"SCENE SAVED AS"
# define SCREENSHOT_MESSAGE_TITLE		"SCREENSHOT SAVED"

# define READ_BUFF_SIZE					8192

# define FILE_PARSE_SCENE				0
# define FILE_PARSE_CAMERA				1
# define FILE_PARSE_LIGHT				2
# define FILE_PARSE_MATERIAL			3
# define FILE_PARSE_OBJECT				4

# define FILE_SCENE						"scene"
# define FILE_SCENE_NAME				"name"
# define FILE_SCENE_AUTHOR				"author"
# define FILE_CAMERA					"camera"
# define FILE_CAMERA_POSITION			"position"
# define FILE_CAMERA_DIRECTION			"direction"
# define FILE_LIGHT						"light"
# define FILE_LIGHT_TYPE				"type"
# define FILE_LIGHT_TYPE_AMBIENT		"ambient"
# define FILE_LIGHT_TYPE_DIRECTIONAL	"directional"
# define FILE_LIGHT_TYPE_POINT			"point"
# define FILE_LIGHT_INTENSITY			"intensity"
# define FILE_LIGHT_POSITION			"position"
# define FILE_MATERIAL					"material"
# define FILE_MATERIAL_NAME				"name"
# define FILE_MATERIAL_COLOR			"color"
# define FILE_MATERIAL_SPECULAR			"specular"
# define FILE_MATERIAL_REFLECTIVE		"reflective"
# define FILE_OBJECT					"object"
# define FILE_OBJECT_TYPE				"type"
# define FILE_OBJECT_TYPE_PLANE			"plane"
# define FILE_OBJECT_TYPE_SPHERE		"sphere"
# define FILE_OBJECT_TYPE_CYLINDER		"cylinder"
# define FILE_OBJECT_TYPE_CONE			"cone"
# define FILE_OBJECT_MATERIAL			"material"
# define FILE_OBJECT_POSITION			"position"
# define FILE_OBJECT_ORIENTATION		"orientation"
# define FILE_OBJECT_RADIUS				"radius"

# define VIEWPORT_SIZE_W				1.5
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

# define EFFECTS_QUANTITY				11
# define NO_EFFECT						0
# define EFFECT_PIXELATION				1
# define EFFECT_CARTOON					8
# define EFFECT_GRAYSCALE				3
# define EFFECT_NEGATIVE				4
# define EFFECT_RED_CHANNEL				5
# define EFFECT_GREEN_CHANNEL			6
# define EFFECT_BLUE_CHANNEL			7
# define EFFECT_DEPTH_MAP				10
# define EFFECT_FOG						9
# define EFFECT_OUTLINE_MAP				2

# define ANTIALIASING_COLOR_THRESHOLD	8
# define MULTI_SAMPLING_RATE			8

# define DEPTH_MAP_INCREMENT			2
# define DEPTH_MAP_MIN					8
# define DEPTH_MAP_MAX					1024

# define PIXELATION_INCREMENT			2
# define PIXELATION_MAX					200
# define PIXELATION_MIN					4

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
# define PLUS							24
# define MINUS							27
# define O								31
# define U								32
# define I								34
# define P								35
# define RETURN							36
# define L								37
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

#endif