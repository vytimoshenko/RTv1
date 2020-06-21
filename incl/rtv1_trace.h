/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_trace.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitaly <vitaly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:37:02 by mperseus          #+#    #+#             */
/*   Updated: 2020/06/21 13:36:53 by vitaly           ###   ########.fr       */
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
void		prepare_pixels(t_scene *scene);
void		get_centered_coordinates(t_pix *pixel);
void		get_pixel_viewport_coordinates(t_scene *scene, t_pix *pixel);
void		rotate_pixel(t_pix *pixel, t_cam *camera);

//CORE
void		trace_pixel(t_scene *scene, t_vec camera, t_pix *pixel,
			int reflection_depth);
void		get_prop(t_scene *scene, t_vec pixel, t_pnt *point,
			t_obj *object);
void		get_normal(t_pnt *point, t_vec pixel, t_obj *object, t_vec camera);

//INTERSECTIONS
t_obj	get_intersection(t_objs	objects, t_vec camera,
			t_vec pixel, t_t_min_max t_min_max);
t_obj	check_closest_object(t_obj closest_object, double closest);
void		select_object_intersect_function(t_obj *object, t_vec camera,
			t_vec pixel);

void		plane(t_obj *object, t_vec camera, t_vec pixel);
void		sphere(t_obj *object, t_vec camera, t_vec pixel);
void		cylinder(t_obj *object, t_vec camera, t_vec pixel);
void		cone(t_obj *object, t_vec camera, t_vec pixel);

//LIGHT
double		get_lightning(t_scene *scene, t_pnt point, t_vec pixel);
double		diffuse_and_specular_light(t_scene *scene, t_pnt point,
			t_vec pixel, int i);
double		diffuse(t_vec normal, t_vec light);
double		specular(t_vec normal, t_vec light, t_vec pixel,
			double specular);
t_vec	reflect_ray(t_vec ray, t_vec normal);

//VECTOR OPERATIONS
double		deg_to_rad(int degrees);
double		dot(t_vec v1, t_vec v2);
double		length(t_vec v1);
t_vec	normalize(t_vec v);

t_vec	add(t_vec v1, t_vec v2);
t_vec	sub(t_vec v1, t_vec v2);
t_vec	mult_sv(double k, t_vec v);

#endif
