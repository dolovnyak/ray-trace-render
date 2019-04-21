#include "config_cl.h"

void        put_pixel(int x, int y, t_color color, __global char* img, int width, int height)
{
    int a;

    y = height - y;
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        a = x * 4 + y * width * 4;
        img[a] = color.b;
        img[a + 1] = color.g;
        img[a + 2] = color.r;
        img[a + 3] = 0;
    }
}

__kernel void render(__global char* img, int width, int height, int objects_num, int lights_num,
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
	color = ray_trace(&conf);
	put_pixel(gid % width, gid / width, color, img, width, height);
}
