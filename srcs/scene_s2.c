/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_s2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:14:12 by sbosmer           #+#    #+#             */
/*   Updated: 2019/07/04 16:33:59 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void		light(t_conf *conf)
{
	t_lights	*lights;

	conf->lights_num = 4;
	lights = (t_lights*)malloc(sizeof(t_lights) * conf->lights_num);
	lights[0] = new_light_point(0.8, (t_vector3d){10, 20, 0});
	lights[1] = new_light_point(0.8, (t_vector3d){0, 20, 10});
	lights[2] = new_light_point(0.8, (t_vector3d){-10, 20, 0});
	lights[3] = new_light_point(0.8, (t_vector3d){0, 20, -10});
	conf->lights = lights;
}

void		obj_1(t_object3d *objects)
{
	objects[6] = new_obj_cylinder((t_cylinder){{50, 5, 0}, 3,
	{1, 1, 0}, {200, 200, 0}, 1000, 0, 0.0});
	objects[7] = new_obj_cylinder((t_cylinder){{-50, 5, 0}, 3,
	{-1, 1, 0}, {200, 0, 200}, 1000, 0, 0.0});
	objects[8] = new_obj_cylinder((t_cylinder){{0, 5, 50}, 3,
	{0, 1, 1}, {200, 0, 200}, 1000, 0, 0.0});
	objects[9] = new_obj_cylinder((t_cylinder){{0, 5, -50}, 3,
	{1, 1, -1}, {200, 200, 0}, 1000, 0, 0.0});
	objects[10] = new_obj_cylinder((t_cylinder){{50, 35, 0}, 3,
	{-1, 1, 0}, {200, 200, 0}, 1000, 0, 0.0});
	objects[11] = new_obj_cylinder((t_cylinder){{-50, 35, 0}, 3,
	{1, 1, 0}, {0, 200, 200}, 1000, 0, 0.0});
	objects[12] = new_obj_cylinder((t_cylinder){{0, 35, 50}, 3,
	{0, 1, -1}, {200, 200, 0}, 1000, 0, 0.0});
	objects[13] = new_obj_cylinder((t_cylinder){{0, 35, -50}, 3,
	{0, 1, 1}, {0, 200, 200}, 1000, 0, 0.0});
	(void)objects;
}

void		scene_2(t_conf *conf)
{
	t_object3d	*objects;

	light(conf);
	conf->objects_num = 14;
	objects = (t_object3d*)malloc(sizeof(t_object3d) * conf->objects_num);
	objects[0] = new_obj_plane((t_plane){{0, -10, 0}, {0, 1, 0},
	{100, 0, 0}, 1000, 0, 1});
	objects[1] = new_obj_plane((t_plane){{0, 50, 0}, {0, -1, 0},
	{0, 0, 100}, 1000, 0, 1});
	objects[2] = new_obj_plane((t_plane){{50, -10, 0}, {-1, 0, 0},
	{0, 100, 0}, 1000, 0, 1});
	objects[3] = new_obj_plane((t_plane){{0, -10, 50}, {0, 0, -1},
	{100, 100, 0}, 1000, 0, 1});
	objects[4] = new_obj_plane((t_plane){{-50, -10, 0}, {1, 0, 0},
	{100, 0, 100}, 1000, 0, 1});
	objects[5] = new_obj_plane((t_plane){{0, -10, -50}, {0, 0, 1},
	{0, 100, 100}, 1000, 0, 1});
	obj_1(objects);
	conf->objects = objects;
}
