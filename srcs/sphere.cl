#include "config_cl.h"

int		get_intersect_sphere(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			float *intersect_dist, const float min_distance)
{
	float		intersect_check, intersect_tmp;
	float		a, b, c;
	t_vector3d	OC;
	float		discriminant;

	intersect_tmp = *intersect_dist;
	OC = mv_minus(start_ray, obj.center);
	a = 1;
	b = mv_scalar_mult(OC, ray);
	c = mv_scalar_mult(OC, OC) - obj.sq_radius;
	discriminant = b * b - a * c;
	if (discriminant < 0.001)
		return(0);
	intersect_check = (-b - sqrt(discriminant)) / a;
	if (intersect_check < *intersect_dist && intersect_check > min_distance)
		*intersect_dist = intersect_check;
	if (*intersect_dist == intersect_tmp)
		return (0);
	return (1);
}

int		get_intersect_sphere_for_shadows(const t_vector3d start_ray, const t_vector3d ray,
			const t_object3d obj, const float max_distance, const float min_distance)
{
	float		intersect_check;
	float		a, b, c;
	t_vector3d	OC;
	float		discriminant;

	OC = mv_minus(start_ray, obj.center);
	a = 1;
	b = mv_scalar_mult(OC, ray);
	c = mv_scalar_mult(OC, OC) - obj.sq_radius;
	discriminant = b * b - a * c;
	if (discriminant < 0.001)
		return(0);
	intersect_check = (-b - sqrt(discriminant)) / a;
	if (intersect_check < max_distance && intersect_check > min_distance)
		return (1);
	return (0);
}

t_vector3d	get_normal_vector_sphere(const t_object3d obj, const t_vector3d intersection_point)
{
	t_vector3d	N;

	N = mv_minus(intersection_point, obj.center);
	return (N);
}
