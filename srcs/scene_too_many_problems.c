/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_too_many_problems.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:21:05 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/04 15:26:07 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void	get_objs(t_object3d *objects)
{
	objects[0] = new_obj_sphere((t_sphere){{0, 0, 50}, 10, {20, 20, 200},
			1000, 0, 0.7});
	objects[1] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){0, 1, 0}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[2] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){1, 0, 0}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[3] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){1, 1, 0}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[4] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){-1, 1, 0}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[5] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){1, 2, -1}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[6] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){1, 2, 1}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[7] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){-1, 2, -1}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[8] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){-1, 2, 1}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[9] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){1, 0, -1}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[10] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){-1, 0, -1}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[11] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){1, 0.5, -1}, (t_color){200, 20, 20}, 200, 0, 0});
}

void		scene_too_many_problems(t_conf *conf)
{
	t_object3d	*objects;
	t_lights	*lights;

	conf->objects_num = 13;
	objects = (t_object3d*)malloc(sizeof(t_object3d) * conf->objects_num);
	get_objs(objects);
	objects[12] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){-1, 0.5, -1}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[13] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){1, -0.5, -1}, (t_color){200, 20, 20}, 200, 0, 0});
	objects[14] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 0, 50},
		0.5, (t_vector3d){-1, -0.5, -1}, (t_color){200, 20, 20}, 200, 0, 0});
	conf->objects = objects;
	conf->lights_num = 8;
	lights = (t_lights*)malloc(sizeof(t_lights) * conf->lights_num);
	lights[0] = new_light_point(0.6, mv_get_vector3d(-100, 10, 200));
	lights[1] = new_light_point(0.6, mv_get_vector3d(-100, 10, 0));
	lights[2] = new_light_point(0.6, mv_get_vector3d(100, 10, 200));
	lights[3] = new_light_point(0.6, mv_get_vector3d(100, 10, 0));
	lights[4] = new_light_point(0.6, mv_get_vector3d(-100, -10, 200));
	lights[5] = new_light_point(0.6, mv_get_vector3d(-100, -10, 0));
	lights[6] = new_light_point(0.6, mv_get_vector3d(100, -10, 200));
	lights[7] = new_light_point(0.6, mv_get_vector3d(100, -10, 0));
	conf->lights = lights;
}
