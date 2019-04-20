#ifndef CONFIG_CL_H
# define CONFIG_CL_H

#include "math_vec.h"
#include "utilits.h"
#include "RTv1.h"

typedef struct  s_canvas
{
	float       width;
	float       height;
	float       nigh_distance;
	float       far_distance;
	t_vector3d  camera;
}               t_canvas;

typedef struct	s_conf
{
	int						objects_num;
	int						lights_num;
	t_canvas				canvas;
	t_vector3d				cam_ray;
	__global t_object3d*	objects;
	__global t_lights*		lights;
}				t_conf;

t_vector3d	get_cam_ray(int x, int y, t_canvas canvas, int width, int height);
t_color		ray_trace(t_conf *conf);

#endif
