#ifndef CONFIG_CL_H
# define CONFIG_CL_H

#include "math_vec.h"
#include "utilits.h"
#include "RTv1.h"

typedef struct  s_canvas
{
	float       width;
	float       height;
	float       min_distance;
	float       max_distance;
	t_vector3d  camera;
}               t_canvas;

typedef struct	s_conf
{
	int						objects_num;
	int						lights_num;
	t_canvas				canvas;
	t_vector3d				cam_ray;
	float					scalar_cam_ray;
	__global t_object3d*	objects;
	__global t_lights*		lights;
}				t_conf;

t_vector3d	get_cam_ray(int x, int y, t_canvas canvas, int width, int height);
t_color		ray_trace(t_conf *conf);
int			get_intersect(t_object3d *obj, t_conf *conf, float *intersect_dist, float min_distance);
float       find_intersect(t_conf *conf, t_object3d *closest_obj);
float       get_light_intensity(t_object3d *obj, t_vector3d intersect_point, t_conf *conf);
t_vector3d  get_normal_vector(t_object3d *obj, t_vector3d intersect_point);
void        put_pixel(int x, int y, t_color color, __global char* img, int width, int height);
int			get_intersect_sphere(t_sphere sphere, t_conf *conf, float *intersect_dist, float min_distance);
void		get_reflection(int smoothness, t_vector3d *N, t_vector3d *cam, float *intensity, t_lights light);
int			get_intersect_shadows(t_object3d *obj, t_vector3d intersect_point,
		            t_vector3d direction, float *intersect_dist, float min_distance);
int			get_intersect_sphere_for_shadows(t_sphere sphere, t_vector3d start_point_ray,
		            t_vector3d ray, float *intersect_dist, float min_distance);
int         check_intersect_for_shadows(t_vector3d intersect_point, t_vector3d direction,
		                float min_distance, float max_distance, t_conf *conf);

#endif
