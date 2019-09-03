/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:14:38 by sbecker           #+#    #+#             */
/*   Updated: 2019/07/03 19:53:14 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

t_object3d	new_obj_sphere(t_sphere sphere)
{
	t_object3d	object;

	object.type = 1;
	object.color = sphere.color;
	object.smoothness = sphere.smoothness;
	object.reflectivity = sphere.reflectivity;
	object.light_source = sphere.light_source;
	object.center = sphere.center;
	object.radius = sphere.radius;
	object.sq_radius = sphere.radius * sphere.radius;
	return (object);
}

t_object3d	new_obj_cylinder(t_cylinder cylinder)
{
	t_object3d	object;

	object.type = 2;
	object.color = cylinder.color;
	object.smoothness = cylinder.smoothness;
	object.reflectivity = cylinder.reflectivity;
	object.light_source = cylinder.light_source;
	object.center = cylinder.center;
	object.axis = mv_normalize(cylinder.axis);
	object.radius = cylinder.radius;
	object.sq_radius = cylinder.radius * cylinder.radius;
	return (object);
}

t_object3d	new_obj_plane(t_plane plane)
{
	t_object3d	object;

	object.type = 3;
	object.color = plane.color;
	object.smoothness = plane.smoothness;
	object.reflectivity = plane.reflectivity;
	object.light_source = plane.light_source;
	object.center = plane.center;
	object.normal = mv_normalize(plane.normal);
	return (object);
}

t_object3d	new_obj_cone(t_cone cone)
{
	t_object3d	object;

	object.type = 7;
	object.color = cone.color;
	object.smoothness = cone.smoothness;
	object.reflectivity = cone.reflectivity;
	object.light_source = cone.light_source;
	object.center = cone.center;
	object.radius = cone.radius;
	object.sq_radius = cone.radius * cone.radius;
	object.axis = mv_normalize(cone.axis);
	return (object);
}
