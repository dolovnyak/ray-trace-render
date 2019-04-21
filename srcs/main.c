#include "config.h"

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
	mlx_clear_window(conf->mlx.mlx, conf->mlx.win);
	mlx_put_image_to_window(conf->mlx.mlx, conf->mlx.win, conf->mlx.img_ptr, 0, 0);
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
	mlx_loop(conf.mlx.mlx);
	return (0);
}
