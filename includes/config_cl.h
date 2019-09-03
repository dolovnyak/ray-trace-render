#ifndef CONFIG_CL_H
# define CONFIG_CL_H

#include "math_vec.h"
#include "utilits.h"
#include "ray_trace.h"

#define DEPTH 3

typedef struct  s_reflection
{
	t_color     local_color;
	float       reflectivity;
}               t_reflection;

typedef struct	s_scene
{
	int						objects_num;
	int						lights_num;
	float					min_distance;
	float					max_distance;
	__global t_object3d*	objects;
	__global t_lights*		lights;
}				t_scene;

t_vector3d	get_cam_ray(int x, int y, t_canvas canvas, int width, int height);
t_color		ray_trace(t_vector3d start_ray, t_vector3d ray, t_scene *scene);
float       find_intersect(t_vector3d *start_ray, t_vector3d *ray,
		t_scene *scene, t_object3d *closest_obj);
int			get_intersect(t_vector3d *start_ray, t_vector3d *ray, t_object3d *obj,
		float *intersect_dist, float min_distance);
int		get_intersect_sphere(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			float *intersect_dist, const float min_distance);
int		get_intersect_sphere_for_shadows(const t_vector3d start_ray, const t_vector3d ray,
			const t_object3d obj, const float max_distance, const float min_distance);
int		get_intersect_plane(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			float *intersect_dist, const float min_distance);
int		get_intersect_plane_for_shadows(const t_vector3d start_ray, const t_vector3d ray,
			const t_object3d obj, float *intersect_dist, const float min_distance);
int		get_intersect_cone(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			float *intersect_dist, const float min_distance);
t_vector3d	get_normal_vector_cone(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			const float intersect_dist);
t_vector3d	get_normal_vector_sphere(const t_object3d obj, const t_vector3d intersection_point);
int     	get_intersect_cylinder(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			float *intersect_dist, const float min_distance);
int     	check_intersect_cylinder_for_shadows(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			float *intersect_dist, const float min_distance);
t_vector3d	get_normal_vector_cylinder(const t_vector3d start_ray, const t_vector3d ray, const t_object3d obj,
			const t_vector3d intersect_point, const float intersect_dist);
float		get_light_intensity(t_object3d *obj, t_vector3d intersect_point,
		t_scene *scene, t_vector3d ray, t_vector3d N);
t_vector3d  get_normal_vector(const t_vector3d start_ray, const t_vector3d ray,
				t_object3d *obj, const t_vector3d intersect_point, const float intersect_dist);
void        put_pixel(int x, int y, t_color color, __global char* img, int width, int height);
void		get_reflection(int smoothness, t_vector3d N, t_vector3d negative_ray,
		float *intensity, t_lights light);
int			get_intersect_shadows(t_object3d *obj, const t_vector3d intersect_point, 
		const t_vector3d direction, const float max_distance, const float min_distance);
int         check_intersect_for_shadows(const t_vector3d intersect_point, const t_vector3d direction,
		const float min_distance, const float max_distance, t_scene *scene, t_vector3d l_pos);
t_vector3d	reflected_ray(t_vector3d ray, t_vector3d N);
t_vector3d	rotation(t_vector3d A, float cos_x_rotate, float sin_x_rotate,
		float cos_y_rotate, float sin_y_rotate, float cos_z_rotate, float sin_z_rotate);

#endif
