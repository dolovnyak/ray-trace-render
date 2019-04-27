#include "config_cl.h"

int     get_intersect(t_object3d *obj, t_conf *conf, float *intersect_dist, float min_distance)
{
	if (obj->type == 1)
		return (get_intersect_sphere(obj->sphere, conf, intersect_dist, min_distance));
	return (0);
}

float       find_intersect(t_conf *conf, t_object3d *closest_obj)
{
	t_object3d object;
	int         i;
	int         intersection_flag;
	float       intersect_dist;

	intersection_flag = 0;
	intersect_dist = conf->canvas.max_distance;
	i = -1;
	while (++i < conf->objects_num)
	{
		object = conf->objects[i];
		if (get_intersect(&object, conf, &intersect_dist, conf->canvas.min_distance))
		{
			intersection_flag = 1;
			*closest_obj = object;
		}
	}
	if (intersect_dist > conf->canvas.min_distance && intersect_dist < conf->canvas.max_distance)
		return (intersect_dist);
	else
		return (0);
}

int     get_intersect_shadows(t_object3d *obj, t_vector3d intersect_point,
			t_vector3d direction, float *intersect_dist, float min_distance)
{
	if (obj->type == 1)
		return (get_intersect_sphere_for_shadows(obj->sphere, intersect_point,
				direction, intersect_dist, min_distance));
	return (0);
}

int			check_intersect_for_shadows(t_vector3d intersect_point, t_vector3d direction,
				float min_distance, float max_distance, t_conf *conf)
{
	int			i;
	t_object3d	object;
	float		intersect_dist;
	
	intersect_dist = max_distance;
	i = -1;
	while (++i < conf->objects_num)
	{
		object = conf->objects[i];
		if (get_intersect_shadows(&object, intersect_point, direction, &intersect_dist, min_distance))
			return (1);
	}
	return (0);
}

t_color     ray_trace(t_conf *conf)
{
	t_color     color;
	t_vector3d  intersect_point;
	float       intersect_dist;
	t_object3d  closest_obj;

	if ((intersect_dist = find_intersect(conf, &closest_obj)))
	{
		intersect_point = mv_plus(conf->canvas.camera, mv_mult_num(conf->cam_ray, intersect_dist));
		color = rgb_mult_num(closest_obj.color, get_light_intensity(&closest_obj, intersect_point, conf));
		return (color);
	}
	return (get_rgb(0, 0, 0));
}
