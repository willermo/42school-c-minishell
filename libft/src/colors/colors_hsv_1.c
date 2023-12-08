/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_hsv_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:12:52 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 10:50:29 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_hsv	rgb_to_hsv(t_rgb rgb)
{
	t_hsv	hsv;
	double	min;
	double	max;
	double	delta;

	min = fmin(fmin(rgb.r, rgb.g), rgb.b);
	max = fmax(fmax(rgb.r, rgb.g), rgb.b);
	delta = max - min;
	if (delta == 0)
		hsv.h = 0;
	else if (max == rgb.r)
		hsv.h = 60 * fmod(((rgb.g - rgb.b) / delta), 6);
	else if (max == rgb.g)
		hsv.h = 60 * (((rgb.b - rgb.r) / delta) + 2);
	else if (max == rgb.b)
		hsv.h = 60 * (((rgb.r - rgb.g) / delta) + 4);
	if (max == 0)
		hsv.s = 0;
	else
		hsv.s = delta / max;
	hsv.v = max;
	return (hsv);
}

int	hsv_to_int(double h, double s, double v)
{
	return (t_rgb_to_int(hsv_to_rgb((t_hsv){.h = h, .s = s, .v = v})));
}

int	t_hsv_to_int(t_hsv hsv)
{
	return (t_rgb_to_int(hsv_to_rgb(hsv)));
}

t_hsv	int_to_t_hsv(int color)
{
	return (rgb_to_hsv(int_to_t_rgb(color)));
}
