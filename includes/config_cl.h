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
int			get_intersect(t_object3d obj, t_vector3d camera, t_vector3d cam_ray, float *intersect_dist);
float       find_intersect(t_conf *conf, t_object3d *closest_obj);
float       get_light_intensity(t_object3d *obj, t_vector3d intersect_point, t_conf *conf);
t_vector3d  get_normal_vector(t_object3d *obj, t_vector3d intersect_point);
void        put_pixel(int x, int y, t_color color, __global char* img, int width, int height);

#endif
