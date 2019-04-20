/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbecker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 05:13:21 by sbecker           #+#    #+#             */
/*   Updated: 2019/04/20 15:40:41 by sbecker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

t_color     get_rgb(int r, int g, int b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color		rgb_mult_num(t_color rgb, float num)
{
	rgb.r *= num;
	rgb.g *= num;
	rgb.b *= num;

	rgb.r = rgb.r > 255 ? 255 : rgb.r;
	rgb.g = rgb.g > 255 ? 255 : rgb.g;
	rgb.b = rgb.b > 255 ? 255 : rgb.b;
	return (rgb);
}
