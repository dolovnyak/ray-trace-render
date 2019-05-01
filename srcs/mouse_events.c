/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:33:47 by sbecker           #+#    #+#             */
/*   Updated: 2019/05/01 05:52:44 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	exit_event(void *param)
{
	param = 0;
	exit(0);
}

int	mouse_move(int x, int y, t_conf *conf)
{
	if (x < conf->mouse_x)
		conf->canvas.y_rotation -= 0.05;
	else if (x > conf->mouse_x)
		conf->canvas.y_rotation += 0.05;
	else if (y < conf->mouse_y)
		conf->canvas.x_rotation -= 0.05;
	else if (y > conf->mouse_y)
		conf->canvas.x_rotation += 0.05;
	conf->mouse_x = x;
	conf->mouse_y = y;
	refresh(conf);
	return (0);
}
