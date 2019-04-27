/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:31:12 by sbecker           #+#    #+#             */
/*   Updated: 2019/04/27 04:36:13 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	key_press(int key, t_conf *conf)
{
	if (key == 13)
		conf->canvas.camera.z += 0.5;
	if (key == 1)
		conf->canvas.camera.z -= 0.5;
	if (key == 0)
		conf->canvas.camera.x -= 0.5;
	if (key == 2)
		conf->canvas.camera.x += 0.5;
	if (key == 126)
		conf->canvas.camera.y += 0.5;
	if (key == 125)
		conf->canvas.camera.y -= 0.5;
	if (key == 123)
		conf->canvas.nigh_distance -= 0.05;
	if (key == 124)
		conf->canvas.nigh_distance += 0.05;
	if (key == 53)
		exit(0);
	refresh(conf);
//	printf("cam: (%f, %f, %f)\n", conf->canvas.camera.x, conf->canvas.camera.y,
//			conf->canvas.camera.z);
	return (0);
}
