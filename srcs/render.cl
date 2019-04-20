#include "config_cl.h"

__kernel void render(__global int* img, int width, int height, int objects_num, int lights_num,
		t_canvas canvas, __global t_object3d* objects, __global t_lights* lights)
{
	int		gid;
	t_conf	conf;
	t_color	color;

	gid = get_global_id(0);
	conf.objects_num = objects_num;
	conf.lights_num = lights_num;
	conf.canvas = canvas;
	conf.objects = objects;
	conf.lights = lights;
	conf.cam_ray = get_cam_ray(gid % width, gid / width, canvas, width, height);

	printf("(%f, %f, %f)\n", conf.cam_ray.x, conf.cam_ray.y, conf.cam_ray.z);
	color = ray_trace(&conf)
}
