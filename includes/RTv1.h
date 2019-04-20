#ifndef RTV1_H
# define RTV1_H

#include "math_vec.h"
#include "utilits.h"

typedef struct	s_sphere
{
	t_vector3d  center;
	float       radius;
}               t_sphere;

typedef struct	s_object3d
{
	int			type;
	t_color		color;
	t_sphere	sphere;
}				t_object3d;

typedef struct	s_lights
{
	int			type;
	float		intensity;
	t_vector3d	position;
	t_vector3d	direction;
}				t_lights;

/* types:
 * 1 - ambient
 * 2 - point
 * 3 - directional
 */

t_object3d	new_obj_sphere(const t_vector3d center, const float radius, const t_color color);
int			get_intersect_sphere(t_sphere sphere, const t_vector3d cam_ray_start,
		const t_vector3d can_ray, float *intersect_dist);
t_vector3d	get_normal_vector_sphere(t_sphere sphere, const t_vector3d intersection_point);

#endif
