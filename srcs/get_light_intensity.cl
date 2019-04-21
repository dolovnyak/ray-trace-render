#include "config_cl.h"

t_vector3d  get_normal_vector(t_object3d *obj, t_vector3d intersect_point)
{
	if (obj->type == 1)
		return (get_normal_vector_sphere(obj->sphere, intersect_point));
	return (mv_get_vector3d(0, 0, 0));
}

float       get_light_intensity(t_object3d *obj, t_vector3d intersect_point, t_conf *conf)
{
	t_vector3d  N;
	float       intensity;
	float       intensity_tmp;
	t_lights    light;
	int         i;

	N = get_normal_vector(obj, intersect_point);
	intensity = 0.0;
	i = -1;
	while (++i < conf->lights_num)
	{
		light = conf->lights[i];
		if (light.type == 1)
			intensity += light.intensity;
		else
		{
			if (light.type == 2)
				light.direction = mv_minus(light.position, intersect_point);
			intensity_tmp = light.intensity * mv_scalar_mult(N, light.direction) /
				(sqrt(mv_scalar_mult(N, N)) * sqrt(mv_scalar_mult(light.direction, light.direction)));
			if (intensity_tmp > 0)
				intensity += intensity_tmp;
		}
	}
	return (intensity);
}
