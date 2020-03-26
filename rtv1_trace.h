/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:37:02 by mperseus          #+#    #+#             */
/*   Updated: 2020/03/26 12:16:00 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_TRACE_H

# define RTV1_TRACE_H

// # define VIEWPORT_SIZE_W				1.5
# define VIEWPORT_SIZE_W				1.25
# define VIEWPORT_SIZE_H				1
# define VIEWPORT_DISTANCE				1

# define EMPTY							-2

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

# define PI								3.14159265

//MAIN
void		trace_rays(t_scene *scene);
void		get_centered_coordinates(t_pixel *pixel);
void		get_pixel_viewport_coordinates(t_scene *scene, t_pixel *pixel);
void		get_sin_cos(t_camera *camera);
void		rotate_pixel(t_pixel *pixel, t_camera *camera);

//CORE
void		trace_pixel(t_scene *scene, t_vector camera, t_pixel *pixel,
			int reflection_depth);
void		get_point_properties(t_scene *scene, t_point *point,
			t_object *object);
void		get_normal(t_point *point, t_object *object);

//INTERSECTIONS
t_object	get_intersection(t_objects	objects, t_vector camera,
			t_vector pixel, t_t_min_max t_min_max);
t_object	check_closest_object(t_object closest_object, double closest);
void		select_object_intersect_function(t_object *object, t_vector camera,
			t_vector pixel);

void		plane(t_object *object, t_vector camera, t_vector pixel);
void		sphere(t_object *object, t_vector camera, t_vector pixel);
void		cylinder(t_object *object, t_vector camera, t_vector pixel);
void		cone(t_object *object, t_vector camera, t_vector pixel);

//LIGHT
double		get_lightning(t_scene *scene, t_point point, t_vector pixel);
double		diffuse_and_specular_light(t_scene *scene, t_point point,
			t_vector pixel, int i);
double		diffuse(t_vector normal, t_vector light);
double		specular(t_vector normal, t_vector light, t_vector pixel,
			double specular);
t_vector	reflect_ray(t_vector ray, t_vector normal);

//VECTOR OPERATIONS
double		deg_to_rad(int degrees);
double		dot(t_vector v1, t_vector v2);
double		length(t_vector v1);
t_vector	normalize(t_vector v);

t_vector	add(t_vector v1, t_vector v2);
t_vector	substract(t_vector v1, t_vector v2);
t_vector	multiply_sv(double k, t_vector v);

#endif
