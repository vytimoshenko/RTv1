/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structures.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 19:16:25 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/27 22:49:22 by mperseus         ###   ########.fr       */
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
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

typedef struct			s_pixel
{
	int					i;
	int					x;
	int					y;
	t_vector			pos;
	t_color				color;
	double				depth;
	short				object_id;
	bool				aliasing;
	t_color				anaglyph;
	t_color				frame;
}						t_pixel;

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

typedef struct			s_t_min_max
{
	double				t;
	double				t_min;
	double				t_max;
}						t_t_min_max;

typedef struct			s_camera
{
	int					id;
	t_vector			position;
	t_vector			direction;
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
	char				*file_name_with_path;
	char				*name;
	char				*author;
	t_cameras			cameras;
	t_lights			lights;
	t_objects			objects;
	t_materials			materials;

	int					active_mode;
	int					active_camera;
	int					active_light;
	int					active_material;
	int					active_object;
	int					active_effect;

	t_pixel				*pixel_buffer;

	int					antialiasing;
	int					k_cartoon;
	int					k_pixelation;
	int					k_depth_map;

	int					got_color;
	t_color				picked_color;
	int					material_source;
	int					x_mouse_position;
	int					y_mouse_position;
	int					middle_mouse_button;

	int					show_help;
	int					show_info;
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
