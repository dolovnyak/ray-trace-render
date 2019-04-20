#include "config_cl.h"

t_vector3d  get_cam_ray(int x, int y, t_canvas canvas, int width, int height)
{
	t_vector3d  canvas_cell;
    t_vector3d  cam_ray;

	x -= (float)width / 2;
    y -= (float)height / 2;
	canvas_cell.x = (float)x * canvas.width / (float)width;
    canvas_cell.y = (float)y * canvas.height / (float)height;
    canvas_cell.z = 1;
	cam_ray = mv_minus(canvas_cell, canvas.camera);
    return (cam_ray);
}
