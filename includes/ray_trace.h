/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:39:06 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/03 19:39:22 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACE_H
# define RAY_TRACE_H

# include "math_vec.h"
# include "utilits.h"

typedef struct	s_sphere
{
	t_vector3d	center;
	float		radius;
	t_color		color;
	int			smoothness;
	int			light_source;
	float		reflectivity;
}				t_sphere;

typedef struct	s_cylinder
{
	t_vector3d	center;
	float		radius;
	t_vector3d	axis;
	t_color		color;
	int			smoothness;
	int			light_source;
	float		reflectivity;
}				t_cylinder;

typedef struct	s_cone
{
	t_vector3d	center;
	t_vector3d	axis;
	float		radius;
	t_color		color;
	int			smoothness;
	int			light_source;
	float		reflectivity;
}				t_cone;

typedef struct	s_plane
{
	t_vector3d	center;
	t_vector3d	normal;
	t_color		color;
	int			smoothness;
	int			light_source;
	float		reflectivity;
}				t_plane;

typedef struct	s_object3d
{
	int			type;
	t_color		color;
	int			smoothness;
	float		reflectivity;
	int			light_source;
	t_vector3d	center;
	t_vector3d	axis;
	float		radius;
	float		sq_radius;
	t_vector3d	normal;
}				t_object3d;

typedef struct	s_lights
{
	int			type;
	float		intensity;
	t_vector3d	position;
	t_vector3d	direction;
	float		sqrt_scalar_direction;
}				t_lights;

typedef struct	s_canvas
{
	float		width;
	float		height;
	float		min_distance;
	float		max_distance;
	float		x_rotation;
	float		y_rotation;
	float		z_rotation;
	float		cos_x_rotate;
	float		sin_x_rotate;
	float		cos_y_rotate;
	float		sin_y_rotate;
	float		cos_z_rotate;
	float		sin_z_rotate;
	t_vector3d	camera;
}				t_canvas;

/*
** types:
** 1 - ambient
** 2 - point
** 3 - directional
*/

t_object3d		new_obj_sphere(t_sphere sphere);
t_object3d		new_obj_cylinder(t_cylinder cylinder);
t_object3d		new_obj_plane(t_plane plane);
t_object3d		new_obj_cone(t_cone cone);
t_lights		new_light_ambient(float intensity);
t_lights		new_light_point(float intensity, t_vector3d position);
t_lights		new_light_directional(float intensity, t_vector3d direction);

#endif
