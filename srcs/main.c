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

int		refresh(t_conf *conf)
{
	cl_mem		mem_img;
	cl_mem		mem_objects;
	cl_mem		mem_lights;
	size_t		global_size;
	t_color		color;
	t_vector3d	cam_ray;
	int			x;
	int			y;
	int			err;

	global_size = conf->mlx.width * conf->mlx.height;

	mem_img = clCreateBuffer(conf->cl.context, CL_MEM_READ_WRITE,
			conf->mlx.size_line * conf->mlx.height, NULL, &err);

	mem_objects = clCreateBuffer(conf->cl.context, CL_MEM_READ_ONLY,
			sizeof(t_object3d) * conf->objects_num, NULL, &err);
	err = clEnqueueWriteBuffer(conf->cl.queue, mem_objects, CL_TRUE, 0,
			sizeof(t_object3d) * conf->objects_num, conf->objects, 0, NULL, NULL);

	mem_lights = clCreateBuffer(conf->cl.context, CL_MEM_READ_ONLY,
			sizeof(t_lights) * conf->lights_num, NULL, &err);
	err = clEnqueueWriteBuffer(conf->cl.queue, mem_lights, CL_TRUE, 0,
			sizeof(t_lights) * conf->lights_num, conf->lights, 0, NULL, NULL);

	if (err != 0)
		printf ("create buffer - error\n");
	err = clSetKernelArg(conf->cl.kernel, 0, sizeof(cl_mem), &mem_img);
	err |= clSetKernelArg(conf->cl.kernel, 1, sizeof(int), &conf->mlx.width);
	err |= clSetKernelArg(conf->cl.kernel, 2, sizeof(int), &conf->mlx.height);
	err |= clSetKernelArg(conf->cl.kernel, 3, sizeof(int), &conf->objects_num);
	err |= clSetKernelArg(conf->cl.kernel, 4, sizeof(int), &conf->lights_num);
	err |= clSetKernelArg(conf->cl.kernel, 5, sizeof(t_canvas), &conf->canvas);
	err |= clSetKernelArg(conf->cl.kernel, 6, sizeof(cl_mem), &mem_objects);
	err |= clSetKernelArg(conf->cl.kernel, 7, sizeof(cl_mem), &mem_lights);
	if (err != 0)
		printf ("set kernel arg - error\n");
	err = clEnqueueNDRangeKernel(conf->cl.queue, conf->cl.kernel, 1, NULL, &global_size,
			NULL, 0, NULL, NULL);
	if (err != 0)
		printf("NDR - error\n");
	err = clEnqueueReadBuffer(conf->cl.queue, mem_img, CL_TRUE, 0,
			conf->mlx.size_line * conf->mlx.height, conf->mlx.img_data, 0, NULL, NULL);
	if (err != 0)
		printf ("read buffer - error\n");
/*	{
		cam_ray = get_cam_ray(x, y, conf);
		color = get_canvas_color(conf, cam_ray);
		put_pixel(x, y, color, &conf->mlx);
	}
	y = -1;
	mlx_clear_window(conf->mlx.mlx, conf->mlx.win);
	mlx_put_image_to_window(conf->mlx.mlx, conf->mlx.win, conf->mlx.img_ptr, 0, 0);*/
	return (0);
}

int main()
{
	t_conf		conf;

	initialization_cl(&conf.cl);
	initialization_mlx(&conf.mlx);
	initialization_canvas(&conf.canvas);
	initialization_scene(&conf);
	refresh(&conf);
//	mlx_loop_hook(conf.mlx.mlx, &refresh, &conf);
//	mlx_loop(conf.mlx.mlx);
	return (0);
}
