#include "config.h"

t_lights    new_light_ambient(float intensity)
{
	t_lights light;

	light.type = 1;
	light.intensity = intensity;
	return (light);
}

t_lights    new_light_point(float intensity, t_vector3d position)
{
	t_lights light;

	light.type = 2;
	light.intensity = intensity;
	light.position = position;
	return (light);
}

t_lights    new_light_directional(float intensity, t_vector3d direction)
{
	t_lights light;

	light.type = 3;
	light.intensity = intensity;
	light.direction = direction;
	light.sqrt_scalar_direction = sqrtf(mv_scalar_mult(direction, direction));
	return (light);
}
