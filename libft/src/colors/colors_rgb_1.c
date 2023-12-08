/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_rgb_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:47:40 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 10:51:01 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

int	rgb_to_int(unsigned char r, unsigned char g, unsigned char b)
{
	return (r << 16 | g << 8 | b);
}

int	t_rgb_to_int(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb	int_to_t_rgb(int color)
{
	t_rgb	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}
