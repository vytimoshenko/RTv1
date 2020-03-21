/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 19:16:25 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/21 14:39:13 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTURES_H

# define RTV1_STRUCTURES_H

# include "rtv1.h"

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

#endif