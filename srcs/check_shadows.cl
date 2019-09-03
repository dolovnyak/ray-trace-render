#include "config_cl.h"

int		get_intersect_shadows(t_object3d *obj, const t_vector3d intersect_point,
		const t_vector3d direction, const float max_distance, const float min_distance)
{
	if (obj->light_source == 0)
	{
		if (obj->type == 1)
			return (get_intersect_sphere_for_shadows(intersect_point,
						direction, *obj, max_distance, min_distance));
		else if (obj->type == 2)
			return (check_intersect_cylinder_for_shadows(intersect_point,
						direction, *obj, &max_distance, min_distance));
		else if (obj->type == 3)
			return (get_intersect_plane_for_shadows(intersect_point,
						direction, *obj, &max_distance, min_distance));
		else if (obj->type == 7)
			return (get_intersect_cone(intersect_point,
						direction, *obj, &max_distance, min_distance));
	}
	return (0);
}

int		check_intersect_for_shadows(const t_vector3d intersect_point, const t_vector3d direction,
		const float min_distance, const float max_distance, t_scene *scene, t_vector3d l_pos)
{
	int         i;
	t_object3d  object;

	i = -1;
	while (++i < scene->objects_num)
	{
		object = scene->objects[i];
		if (get_intersect_shadows(&object, intersect_point, direction, max_distance, min_distance)
	       && mv_length(mv_minus(l_pos, intersect_point)) > mv_length(mv_minus(intersect_point, object.center)))
			return (1);
		//if (get_intersect_shadows(&object, intersect_point, direction, max_distance, min_distance))
		//	return (1);
	}
	return (0);
}
