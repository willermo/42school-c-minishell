/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_hsv_to_rgb_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:55:54 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 10:53:31 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

void	set_drgb_default(t_drgb *drgb, t_hsv hsv, double p, double q)
{
	drgb->r = hsv.v;
	drgb->g = p;
	drgb->b = q;
}

void	set_drgb(t_drgb *drgb, t_hsv hsv)
{
	int		i;
	double	f;
	double	p;
	double	q;
	double	t;

	i = (int)trunc(hsv.h);
	f = hsv.h - i;
	p = hsv.v * (1.0 - hsv.s);
	q = hsv.v * (1.0 - (hsv.s * f));
	t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));
	if (i == 0)
		set_drgb_case_0(drgb, hsv, t, p);
	else if (i == 1)
		set_drgb_case_1(drgb, hsv, q, p);
	else if (i == 2)
		set_drgb_case_2(drgb, hsv, p, t);
	else if (i == 3)
		set_drgb_case_3(drgb, hsv, p, q);
	else if (i == 4)
		set_drgb_case_4(drgb, hsv, t, p);
	else
		set_drgb_default(drgb, hsv, p, q);
}

t_rgb	hsv_to_rgb(t_hsv hsv)
{
	t_drgb	drgb;
	t_rgb	rgb;

	drgb = (t_drgb){.r = 0, .g = 0, .b = 0};
	if (hsv.s == 0)
		drgb.r = hsv.v;
	else
	{
		if (hsv.h == 360)
			hsv.h = 0;
		else
			hsv.h = hsv.h / 60;
		set_drgb(&drgb, hsv);
	}
	rgb.r = drgb.r * 255;
	rgb.g = drgb.g * 255;
	rgb.b = drgb.b * 255;
	return (rgb);
}
