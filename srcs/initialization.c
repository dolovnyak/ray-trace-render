/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 04:47:49 by sbecker           #+#    #+#             */
/*   Updated: 2019/04/29 23:46:29 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void    initialization_mlx(t_mlx *mlx)
{
	mlx->width = 2560;
	mlx->height = 1440;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "ray-trace");
	mlx->img_ptr = mlx_new_image(mlx->mlx, mlx->width, mlx->height);
	mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp, &mlx->size_line, &mlx->endian);
}

void	initialization_canvas(t_canvas *canvas)
{
	canvas->width = 1.77777;
	canvas->height = 1;
	canvas->min_distance = 1;
	canvas->max_distance = 9999999;
	canvas->camera = (mv_get_vector3d(0, 0, 0));
}

t_lights	new_light_ambient(float intensity)
{
	t_lights light;

	light.type = 1;
	light.intensity = intensity;
	return (light);
}

t_lights	new_light_point(float intensity, t_vector3d position)
{
	t_lights light;

	light.type = 2;
	light.intensity = intensity;
	light.position = position;
	return (light);
}

t_lights	new_light_directional(float intensity, t_vector3d direction)
{
	t_lights light;

	light.type = 3;
	light.intensity = intensity;
	light.direction = direction;
	light.sqrt_scalar_direction = sqrtf(mv_scalar_mult(direction, direction));
	return (light);
}

void    initialization_scene(t_conf *conf)
{
	t_object3d	*objects;
	t_lights	*lights;

	conf->objects_num = 22;
	objects = (t_object3d*)malloc(sizeof(t_object3d) * conf->objects_num);
	objects[0] = new_obj_sphere(mv_get_vector3d(0, -5002, 0), 5000, get_rgb(255, 255, 255), 100, 0, 1);
	objects[1] = new_obj_sphere(mv_get_vector3d(50, 0, 15), 30, get_rgb(0, 0, 255), 30000, 0, 1);
	objects[2] = new_obj_sphere(mv_get_vector3d(-10, 0, 0), 2, get_rgb(0, 255, 0), 100, 0, 0.5);
	objects[3] = new_obj_sphere(mv_get_vector3d(2, 0, 8), 1, get_rgb(0, 255, 255), 500, 0, 0.5);
	objects[4] = new_obj_sphere(mv_get_vector3d(2, -2, 2), 1, get_rgb(255, 255, 0), 10, 0, 0.5);
	objects[5] = new_obj_sphere(mv_get_vector3d(-8, 2, 0), 3, get_rgb(255, 0, 0), 100, 0, 0.5);
	objects[6] = new_obj_sphere(mv_get_vector3d(-50, 0, 15), 30, get_rgb(0, 0, 255), 30000, 0, 1);
	objects[7] = new_obj_sphere(mv_get_vector3d(10, 0, 0), 2, get_rgb(0, 255, 0), 100, 0, 0.5);
	objects[8] = new_obj_sphere(mv_get_vector3d(-2, 0, 8), 1, get_rgb(0, 255, 255), 500, 0, 0.5);
	objects[9] = new_obj_sphere(mv_get_vector3d(-2, -2, 2), 1, get_rgb(255, 255, 0), 10, 0, 0.5);
	objects[10] = new_obj_sphere(mv_get_vector3d(8, 2, 0), 3, get_rgb(255, 0, 0), 100, 0, 0.5);
	objects[11] = new_obj_sphere(mv_get_vector3d(50, 0, -15), 30, get_rgb(0, 0, 255), 30000, 0, 1);
	objects[12] = new_obj_sphere(mv_get_vector3d(-10, 10, 0), 2, get_rgb(0, 255, 0), 100, 0, 0.5);
	objects[13] = new_obj_sphere(mv_get_vector3d(2, 0, -8), 1, get_rgb(0, 255, 255), 500, 0, 0.5);
	objects[14] = new_obj_sphere(mv_get_vector3d(2, 2, 2), 1, get_rgb(255, 255, 0), 10, 0, 0.5);
	objects[15] = new_obj_sphere(mv_get_vector3d(-8, -2, 0), 3, get_rgb(255, 0, 0), 100, 0, 0.5);
	objects[16] = new_obj_sphere(mv_get_vector3d(-50, 0, -15), 30, get_rgb(0, 0, 255), 30000, 0, 1);
	objects[17] = new_obj_sphere(mv_get_vector3d(10, 10, 0), 2, get_rgb(0, 255, 0), 100, 0, 0.5);
	objects[18] = new_obj_sphere(mv_get_vector3d(-2, 0, -8), 1, get_rgb(0, 255, 255), 500, 0, 0.5);
	objects[19] = new_obj_sphere(mv_get_vector3d(-2, 2, 2), 1, get_rgb(255, 255, 0), 10, 0, 0.5);
	objects[20] = new_obj_sphere(mv_get_vector3d(8, -2, 0), 3, get_rgb(255, 0, 0), 100, 0, 0.5);
	objects[21] = new_obj_sphere(mv_get_vector3d(0, 3, -5), 1.5, get_rgb(99999999, 99999999, 99999999), -1, 1, 1);
	conf->objects = objects;
	conf->lights_num = 3;
	lights = (t_lights*)malloc(sizeof(t_lights) * conf->lights_num);
	lights[0] = new_light_ambient(0.1);
	lights[1] = new_light_point(0.6, mv_get_vector3d(0, 3, -5));
	lights[2] = new_light_directional(0.3, mv_get_vector3d(1, 4, 4));
	conf->lights = lights;
}
