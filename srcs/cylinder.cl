#include "config_cl.h"

int     	get_intersect_cylinder(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			float *intersect_dist, const float min_distance)
{
    float       intersect_check, intersect_tmp;
    float       a, b, c;
    float       discriminant;
    t_vector3d  OC;

	intersect_tmp = *intersect_dist;
    OC = mv_minus(start_ray, obj.center);
    a = 1 - mv_scalar_mult(ray, obj.axis) * mv_scalar_mult(ray, obj.axis);
    b = mv_scalar_mult(ray, OC) - mv_scalar_mult(ray, obj.axis) * mv_scalar_mult(OC, obj.axis);
    c = mv_scalar_mult(OC, OC) - mv_scalar_mult(OC, obj.axis) *
			mv_scalar_mult(OC, obj.axis) - obj.sq_radius;
    discriminant = b * b - a * c;
    if (discriminant < 0.001)
        return (0);
    intersect_check = (-b - sqrt(discriminant)) / a;
    if (intersect_check < *intersect_dist && intersect_check > min_distance)
        *intersect_dist = intersect_check;
    if (*intersect_dist == intersect_tmp)
        return (0);
    return (1);
}

int     	check_intersect_cylinder_for_shadows(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			float *intersect_dist, const float min_distance)
{
    float       intersect_check, intersect_tmp;
    float       a, b, c;
    float       discriminant;
    t_vector3d  OC;

	intersect_tmp = *intersect_dist;
    OC = mv_minus(start_ray, obj.center);
    a = 1 - mv_scalar_mult(ray, obj.axis) * mv_scalar_mult(ray, obj.axis);
    b = mv_scalar_mult(ray, OC) - mv_scalar_mult(ray, obj.axis) * mv_scalar_mult(OC, obj.axis);
    c = mv_scalar_mult(OC, OC) - mv_scalar_mult(OC, obj.axis) *
			mv_scalar_mult(OC, obj.axis) - obj.sq_radius;
    discriminant = b * b - a * c;
    if (discriminant < 0.001)
        return (0);
    intersect_check = (-b - sqrt(discriminant)) / a;
    if (intersect_check < *intersect_dist && intersect_check > min_distance)
        *intersect_dist = intersect_check;
    if (*intersect_dist == intersect_tmp)
        return (0);
    return (1);
}

t_vector3d	get_normal_vector_cylinder(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			const t_vector3d intersect_point, const float intersect_dist)
{
	float		m;
	t_vector3d	N;

	m = mv_scalar_mult(ray, obj.axis) * intersect_dist +
			mv_scalar_mult(mv_minus(start_ray, obj.center), obj.axis);
	N = mv_minus(mv_minus(intersect_point, obj.center), mv_mult_num(obj.axis, m));
	return (N);
}
