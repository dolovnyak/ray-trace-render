#include "config_cl.h"

int		get_intersect_plane(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			float *intersect_dist, const float min_distance)
{
	float		intersect_tmp;
	float		intersect;

	intersect_tmp = *intersect_dist;
	float b = mv_scalar_mult(ray, obj.normal);
	if (b > 0.0)
		return (0);
	float a = mv_scalar_mult(mv_minus(start_ray, obj.center), obj.normal);
	intersect = -(a / b);
	if (intersect < *intersect_dist && intersect > min_distance)
		*intersect_dist = intersect;
	if (*intersect_dist == intersect_tmp)
		return (0);
	return (1);
}

int		get_intersect_plane_for_shadows(const t_vector3d start_ray, const t_vector3d ray,
			const t_object3d obj, float *intersect_dist, const float min_distance)
{
	float		intersect_tmp;
	float		intersect;

	intersect_tmp = *intersect_dist;
	float b = mv_scalar_mult(ray, obj.normal);
	if (b > 0)
		return (0);
	float a = mv_scalar_mult(mv_minus(obj.center, start_ray), obj.normal);
	intersect = -(a / b);
	if (intersect < *intersect_dist && intersect > min_distance)
		*intersect_dist = intersect;
	if (*intersect_dist == intersect_tmp)
		return (0);
	return (1);
}
