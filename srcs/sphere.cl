#include "config_cl.h"

int		get_intersect_sphere(t_sphere sphere, const t_vector3d cam_ray_start,
		const t_vector3d cam_ray, float *intersect_dist)
{
	float		intersect_dist1;
	float		intersect_dist2;
	float		k1, k2, k3;
	float		r;
	t_vector3d	C;
	t_vector3d	OC;
	t_vector3d	D;
	float		discriminant;
	float		intersect_tmp;

	intersect_tmp = *intersect_dist;
	intersect_dist1 = 1000;
	intersect_dist2 = 1000;
	D = cam_ray;
	C = sphere.center;
	r = sphere.radius;
	OC = mv_minus(cam_ray_start, C);
	k1 = mv_scalar_mult(D, D);
	k2 = 2 * mv_scalar_mult(OC, D);
	k3 = mv_scalar_mult(OC, OC) - r * r;
	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
		return(0);
	intersect_dist1 = (-k2 + sqrt(discriminant)) / (2 * k1);
	intersect_dist2 = (-k2 - sqrt(discriminant)) / (2 * k1);
	if (intersect_dist1 < *intersect_dist && intersect_dist1 > 1) //вместо 1 - поставить дистанцию камеры
		*intersect_dist = intersect_dist1;
	if (intersect_dist2 < *intersect_dist && intersect_dist2 > 1) //вместо 1 - поставить дистанцию камеры
		*intersect_dist = intersect_dist2;
	if (*intersect_dist == intersect_tmp)
		return (0);
	return (1);
}

t_vector3d	get_normal_vector_sphere(t_sphere sphere, const t_vector3d intersection_point)
{
	t_vector3d	N;

	N = mv_minus(intersection_point, sphere.center);
	N = mv_dev_num(N, sqrt(mv_scalar_mult(N, N)));
	return (N);
}
