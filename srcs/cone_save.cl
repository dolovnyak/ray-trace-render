#include "config_cl.h"

int		get_intersect_cone(const t_vector3d start_ray, const t_vector3d ray, const t_cone cone,
			float *intersect_dist, const float min_distance)
{
	const float intersect_tmp = *intersect_dist;
	float		intersect;

	// ray = mv_normalize(ray);
	t_vector3d	oc = mv_minus(start_ray, cone.center);
	float	card = mv_scalar_mult(ray, cone.axis);
	float	caoc = mv_scalar_mult(oc, cone.axis);

	float	k2 = cone.k * cone.k;
	float	a = 1.0 - (1 + k2) * card * card;
	float	b = mv_scalar_mult(ray, oc) - (1 + k2) * card * caoc;
	b = b * 2.0;
	float	c = mv_scalar_mult(oc, oc) - (1 + k2) * caoc * caoc; 
	float	d = b * b - 4.0 * a * c;

	if (d < 0.0)
		return (0);
	intersect = (-b - sqrt(d)) / (2.0 * a);
	

	if (intersect < *intersect_dist && intersect > min_distance)
		*intersect_dist = intersect;
	if (*intersect_dist == intersect_tmp)
		return (0);
	// float	m = card * intersect + caoc;
	// aa = 2;
	// *normal = (t_vector3d){0, 1, 0};
	// *normal = mv_normalize(mv_minus(mv_plus(mv_mult_num(ray, intersect), oc), mv_mult_num(cone.axis, (1.0 + k2) * m)));
	return (1);
}

t_vector3d	get_normal_vector_cone(const t_vector3d start_ray, const t_vector3d ray, const t_cone cone,
			const float intersect_dist)
{
	t_vector3d	retNormal;
	const t_vector3d	oc = mv_minus(start_ray, cone.center);

	float	card = mv_scalar_mult(ray, cone.axis);
	float	caoc = mv_scalar_mult(oc, cone.axis);
	float	k2 = cone.k * cone.k;
	float	m = card * intersect_dist + caoc;
	retNormal = mv_normalize(mv_minus(mv_plus(mv_mult_num(ray, intersect_dist), oc), mv_mult_num(cone.axis, (1 + k2) * m)));
	return (retNormal);
}
