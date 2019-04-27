#include "config_cl.h"

t_vector3d  get_normal_vector(t_object3d *obj, t_vector3d intersect_point)
{
	if (obj->type == 1)
		return (get_normal_vector_sphere(obj->sphere, intersect_point));
	return (mv_get_vector3d(0, 0, 0));
}

void		get_reflection(int smoothness, t_vector3d *N, t_vector3d *cam, float *intensity, t_lights light)
{
	t_vector3d	reflection_ray;

	if (smoothness != -1)
	{
		reflection_ray = mv_minus(mv_mult_num(mv_mult_num(*N, 2),
				mv_scalar_mult(*N, light.direction)), light.direction);
		if (mv_scalar_mult(*cam, reflection_ray) > 0)
			*intensity += light.intensity * pow(mv_scalar_mult(*cam, reflection_ray) /
					(mv_length(reflection_ray) * mv_length(*cam)), smoothness);
	}
}

float       get_light_intensity(t_object3d *obj, t_vector3d intersect_point, t_conf *conf)
{
	float	max_coef_ray_point;
	t_vector3d	cam;
	t_vector3d  N;
	float       intensity;
	float       intensity_tmp;
	t_lights    light;
	int         i;

	cam = mv_mult_num(conf->cam_ray, -1);
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
			{
				light.direction = mv_minus(light.position, intersect_point);
				max_coef_ray_point = 1;
				if (check_intersect_for_shadows(intersect_point, light.direction,
					0.00001, max_coef_ray_point, conf) == 0)
				{
					 intensity_tmp = light.intensity * mv_scalar_mult(N, light.direction) /
						(sqrt(mv_scalar_mult(N, N)) * sqrt(mv_scalar_mult(light.direction, light.direction)));
					if (intensity_tmp > 0)
						intensity += intensity_tmp;
					get_reflection(obj->smoothness, &N, &cam, &intensity, light);
				}
			}
			else
			{
				max_coef_ray_point = 999999;
				if (check_intersect_for_shadows(intersect_point, light.direction,
					0.00001, max_coef_ray_point, conf) == 0)
				{
					intensity_tmp = light.intensity * mv_scalar_mult(N, light.direction) /
						(sqrt(mv_scalar_mult(N, N)) * light.sqrt_scalar_direction);
					if (intensity_tmp > 0)
						intensity += intensity_tmp;
					get_reflection(obj->smoothness, &N, &cam, &intensity, light);
				}
			}
		}
	}
	return (intensity);
}
