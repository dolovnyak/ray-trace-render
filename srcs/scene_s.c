/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:42:37 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/04 15:32:10 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static void	get_objs(t_object3d *objects)
{
	objects[0] = new_obj_plane((t_plane){{0, -2, 2}, {0, 1, 0},
			{150, 100, 100}, 200, 0, 0.25});
	objects[1] = new_obj_sphere((t_sphere){{0, 0.0, 7}, 2.0,
			{128, 128, 128}, 1000, 0, 0.7});
	objects[10] = new_obj_sphere((t_sphere){{0, 2.9, 7}, 0.9,
			{128, 128, 128}, 1000, 0, 0.9});
	objects[2] = new_obj_sphere((t_sphere){{4, -1.8, -1}, 0.2,
			{128, 128, 128}, 1000, 0, 0.3});
	objects[3] = new_obj_sphere((t_sphere){{4, -1.1, -1}, 0.5,
			{128, 128, 128}, 1000, 0, 0.5});
	objects[4] = new_obj_sphere((t_sphere){{4, -0.3, -1}, 0.3,
			{128, 128, 128}, 1000, 0, 0.4});
	objects[5] = new_obj_sphere((t_sphere){{4, 1.2, -1}, 1.2,
			{128, 128, 128}, 1000, 0, 0.7});
	objects[9] = new_obj_sphere((t_sphere){{4, 3.0, -1}, 0.6,
			{128, 128, 128}, 1000, 0, 0.6});
	objects[6] = new_obj_sphere((t_sphere){{-4, -1.7, 1}, 0.3,
			{128, 128, 128}, 1000, 0, 0.5});
	objects[7] = new_obj_sphere((t_sphere){{-4, -0.8, 1}, 0.6,
			{128, 128, 128}, 1000, 0, 0.7});
	objects[8] = new_obj_sphere((t_sphere){{-4, 0.0, 1}, 0.2,
			{128, 128, 128}, 1000, 0, 0.6});
	objects[11] = new_obj_sphere((t_sphere){{10, 1.0, 6}, 3.0,
			{128, 128, 128}, 1000, 0, 0.8});
}

void		scene_1(t_conf *conf)
{
	t_object3d	*objects;
	t_lights	*lights;

	conf->objects_num = 12;
	objects = (t_object3d*)malloc(sizeof(t_object3d) * conf->objects_num);
	get_objs(objects);
	conf->objects = objects;
	conf->lights_num = 4;
	lights = (t_lights*)malloc(sizeof(t_lights) * conf->lights_num);
	lights[0] = new_light_ambient(0.05);
	lights[1] = new_light_point(0.6, (t_vector3d){5, 7, 0});
	lights[2] = new_light_point(0.6, (t_vector3d){-4.3, 7, 2.5});
	lights[3] = new_light_point(0.6, (t_vector3d){2.5, 7, -4.3});
	conf->lights = lights;
}
