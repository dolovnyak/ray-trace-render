/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_mario_eden.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:20:53 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/04 15:33:34 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	bottom(t_object3d *objects)
{
	objects[0] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 0},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[1] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 20},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[2] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 40},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[3] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 60},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[4] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 80},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[5] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 100},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[6] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 120},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[7] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 140},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[8] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 160},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[9] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 180},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[10] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 200},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[11] = new_obj_cylinder((t_cylinder){(t_vector3d){0, -40, 220},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
}

void	top(t_object3d *objects)
{
	objects[12] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 0},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[13] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 20},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[14] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 40},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[15] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 60},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[16] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 80},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[17] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 100},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[18] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 120},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[19] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 140},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[20] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 160},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[21] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 180},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[22] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 200},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[23] = new_obj_cylinder((t_cylinder){(t_vector3d){0, 40, 220},
			5, (t_vector3d){1, 0, 0}, (t_color){0, 200, 0}, 200, 0, 0});
}

void	left(t_object3d *objects)
{
	objects[24] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 10},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[25] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 30},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[26] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 50},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[27] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 70},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[28] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 90},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[29] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 110},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[30] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 130},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[31] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 150},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[32] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 170},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[33] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 190},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[34] = new_obj_cylinder((t_cylinder){(t_vector3d){-40, 0, 210},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
}

void	right(t_object3d *objects)
{
	objects[35] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 10},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[36] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 30},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[37] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 50},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[38] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 70},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[39] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 90},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[40] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 110},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[41] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 130},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[42] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 150},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[43] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 170},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[44] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 190},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
	objects[45] = new_obj_cylinder((t_cylinder){(t_vector3d){40, 0, 210},
			5, (t_vector3d){0, 1, 0}, (t_color){0, 200, 0}, 200, 0, 0});
}

void	scene_mario_eden(t_conf *conf)
{
	t_object3d	*objects;
	t_lights	*lights;

	conf->objects_num = 49;
	objects = (t_object3d*)malloc(sizeof(t_object3d) * conf->objects_num);
	bottom(objects);
	top(objects);
	left(objects);
	right(objects);
	objects[46] = new_obj_sphere((t_sphere){{0, 0, 150}, 20, {128, 128, 128},
			1000, 0, 0.7});
	objects[47] = new_obj_cone((t_cone){(t_vector3d){-300, 0, 100},
			(t_vector3d){0, 1, 0}, 0.5, get_rgb(20, 128, 20), 2000, 0, 0});
	objects[48] = new_obj_cone((t_cone){(t_vector3d){300, 0, 100},
			(t_vector3d){0, 1, 0}, 0.5, get_rgb(20, 128, 20), 2000, 0, 0});
	conf->objects = objects;
	conf->lights_num = 3;
	lights = (t_lights*)malloc(sizeof(t_lights) * conf->lights_num);
	lights[0] = new_light_ambient(0.2);
	lights[1] = new_light_point(0.4, (t_vector3d){0, 0, 200});
	lights[2] = new_light_point(0.4, (t_vector3d){0, 0, 0});
	conf->lights = lights;
}
