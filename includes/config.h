/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 02:46:07 by sbecker           #+#    #+#             */
/*   Updated: 2019/04/29 22:17:11 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <OpenCL/opencl.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "utilits.h"
# include "RTv1.h"
# include <stdio.h>

typedef struct	s_cl
{
	cl_command_queue	queue;
	cl_context			context;
	cl_kernel			kernel;
}				t_cl;

typedef struct	s_mlx
{
	void    *img_ptr;
	void    *mlx;
	void    *win;
	char    *img_data;
	int     bpp;
	int     endian;
	int     size_line;
	int     width;
	int     height;
}				t_mlx;

typedef struct  s_canvas
{
	float       width;
	float       height;
	float       min_distance;
	float		max_distance;
	t_vector3d  camera;
}               t_canvas;

typedef struct  s_config
{
	int         lights_num;
	int         objects_num;
	t_object3d  *objects;
	t_canvas    canvas;
	t_lights	*lights;
	t_mlx       mlx;
	t_cl		cl;
}               t_conf;

void		initialization_mlx(t_mlx *mlx);
void		initialization_canvas(t_canvas *canvas);
void		initialization_scene(t_conf *conf);
void		initialization_cl(t_cl *cl);
int			key_press(int keycode, t_conf *conf);
int			exit_event(void *param);
int			refresh(t_conf *conf); //TODO

#endif
