#include "config.h"

void		put_pixel(int x, int y, t_color color, t_mlx *mlx)
{
	int	a;

	y = mlx->height - y;
	if (x >= 0 && x < mlx->width && y >= 0 && y < mlx->height)
	{
		a = x * 4 + y * mlx->width * 4;
		mlx->img_data[a] = color.b;
		mlx->img_data[a + 1] = color.g;
		mlx->img_data[a + 2] = color.r;
		mlx->img_data[a + 3] = 0;
	}
}

int		get_intersect(t_object3d obj, t_vector3d camera, t_vector3d cam_ray, float *intersect_dist)
{
	if (obj.type == 1)
		return (get_intersect_sphere(obj.sphere, camera, cam_ray, intersect_dist));
	return (0);
}

float		find_intersect(t_conf *conf, t_vector3d cam_ray, t_object3d *closest_obj)
{
	int			i;
	int			intersection_flag;
	float		intersect_dist;

	intersection_flag = 0;
	intersect_dist = conf->canvas.far_distance;
	i = -1;
	while (++i < conf->objects_num)
	{
		if (get_intersect(conf->objects[i], conf->canvas.camera, cam_ray, &intersect_dist))
		{
			intersection_flag = 1;
			*closest_obj = conf->objects[i];
		}
	}
	if (intersect_dist > conf->canvas.nigh_distance && intersect_dist < conf->canvas.far_distance)
		return (intersect_dist);
	else
		return (0);
}

t_vector3d	get_normal_vector(t_object3d *obj, t_vector3d intersect_point)
{
	if (obj->type == 1)
		return (get_normal_vector_sphere(obj->sphere, intersect_point));
	return (mv_get_vector3d(0, 0, 0));
}

float		get_light_intensity(t_object3d *obj, t_vector3d intersect_point, t_conf *conf)
{
	t_vector3d	N;
	float		intensity;
	float		intensity_tmp;
	t_lights	light;
	int			i;
	
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
				(sqrtf(mv_scalar_mult(N, N)) * sqrtf(mv_scalar_mult(light.direction, light.direction)));
			if (intensity_tmp > 0)
				intensity += intensity_tmp;
		}
	}
	return (intensity);
}


t_color		get_canvas_color(t_conf *conf, t_vector3d cam_ray)
{
	t_vector3d	intersect_point;
	float		intersect_dist;
	t_object3d	closest_obj;
	t_color		color;

	if ((intersect_dist = find_intersect(conf, cam_ray, &closest_obj)))
	{
		intersect_point = mv_plus(conf->canvas.camera, mv_mult_num(cam_ray, intersect_dist));
		color = rgb_mult_num(closest_obj.color, get_light_intensity(&closest_obj, intersect_point, conf));
		return (color);
	}
	return (get_rgb(0, 0, 0));
}

int		refresh(t_conf *conf)
{
	size_t		global_size;
	t_color		color;
	t_vector3d	cam_ray;
	int			x;
	int			y;

	ft_bzero((void*)conf->mlx.img_data, conf->mlx.size_line * conf->mlx.height);
	x = -1;
	y = -1;
	while (++x < conf->mlx.width)
	{
		while (++y < conf->mlx.height)
		{
			cam_ray = get_cam_ray(x, y, conf);
			color = get_canvas_color(conf, cam_ray);
			put_pixel(x, y, color, &conf->mlx);
		}
		y = -1;
		mlx_clear_window(conf->mlx.mlx, conf->mlx.win);
		mlx_put_image_to_window(conf->mlx.mlx, conf->mlx.win, conf->mlx.img_ptr, 0, 0);
	}
	return (0);
}

int main()
{
	t_conf		conf;

	initialization_mlx(&conf);
	initialization_canvas(&conf);
	initialization_scene(&conf);
	mlx_hook(conf.mlx.win, 2, 0, &keyboard_events, &conf);
	mlx_loop_hook(conf.mlx.mlx, &refresh, &conf);
	mlx_loop(conf.mlx.mlx);
	return (0);
}
