/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_rgb_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:44:11 by doriani           #+#    #+#             */
/*   Updated: 2023/06/08 17:49:35 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_rgb	rgb_add(t_rgb rgb1, t_rgb rgb2)
{
	t_rgb	rgb;

	rgb.r = rgb1.r + rgb2.r;
	rgb.g = rgb1.g + rgb2.g;
	rgb.b = rgb1.b + rgb2.b;
	return (rgb);
}

t_rgb	rgb_sub(t_rgb rgb1, t_rgb rgb2)
{
	t_rgb	rgb;

	rgb.r = rgb1.r - rgb2.r;
	rgb.g = rgb1.g - rgb2.g;
	rgb.b = rgb1.b - rgb2.b;
	return (rgb);
}

t_rgb	rgb_mult(t_rgb rgb1, t_rgb rgb2)
{
	t_rgb	rgb;

	rgb.r = rgb1.r * rgb2.r;
	rgb.g = rgb1.g * rgb2.g;
	rgb.b = rgb1.b * rgb2.b;
	return (rgb);
}

t_rgb	rgb_div(t_rgb rgb1, t_rgb rgb2)
{
	t_rgb	rgb;

	rgb.r = rgb1.r / rgb2.r;
	rgb.g = rgb1.g / rgb2.g;
	rgb.b = rgb1.b / rgb2.b;
	return (rgb);
}

t_rgb	rgb_mult_scalar(t_rgb rgb, double scalar)
{
	rgb.r *= scalar;
	rgb.g *= scalar;
	rgb.b *= scalar;
	return (rgb);
}
