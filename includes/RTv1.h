#ifndef RTV1_H
# define RTV1_H

#include "math_vec.h"
#include "utilits.h"

typedef struct	s_sphere
{
	t_vector3d  center;
	float       radius;
	float		sq_radius;
}               t_sphere;

typedef struct	s_object3d
{
	int			type;
	t_color		color;
	int			smoothness;
	float		reflectivity;
	int			light_source;
	t_sphere	sphere;
}				t_object3d;

typedef struct	s_lights
{
	int			type;
	float		intensity;
	t_vector3d	position;
	t_vector3d	direction;
	float		sqrt_scalar_direction;
}				t_lights;

/* types:
 * 1 - ambient
 * 2 - point
 * 3 - directional
 */

t_object3d	new_obj_sphere(const t_vector3d center, const float radius, const t_color color,
		const int smoothness, int light_source, float reflectivity);
t_vector3d	get_normal_vector_sphere(t_sphere sphere, const t_vector3d intersection_point);

#endif
