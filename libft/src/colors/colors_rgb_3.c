/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_rgb_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:46:00 by doriani           #+#    #+#             */
/*   Updated: 2023/06/08 17:49:33 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_rgb	rgb_div_scalar(t_rgb rgb, double scalar)
{
	rgb.r /= scalar;
	rgb.g /= scalar;
	rgb.b /= scalar;
	return (rgb);
}

t_rgb	rgb_clamp(t_rgb rgb)
{
	rgb.r = fmin(fmax(rgb.r, 0), 255);
	rgb.g = fmin(fmax(rgb.g, 0), 255);
	rgb.b = fmin(fmax(rgb.b, 0), 255);
	return (rgb);
}
