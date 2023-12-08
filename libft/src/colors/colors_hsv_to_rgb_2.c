/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_hsv_to_rgb_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:04:49 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 10:32:23 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

void	set_drgb_case_0(t_drgb *drgb, t_hsv hsv, double t, double p)
{
	drgb->r = hsv.v;
	drgb->g = t;
	drgb->b = p;
}

void	set_drgb_case_1(t_drgb *drgb, t_hsv hsv, double q, double p)
{
	drgb->r = q;
	drgb->g = hsv.v;
	drgb->b = p;
}

void	set_drgb_case_2(t_drgb *drgb, t_hsv hsv, double p, double t)
{
	drgb->r = p;
	drgb->g = hsv.v;
	drgb->b = t;
}

void	set_drgb_case_3(t_drgb *drgb, t_hsv hsv, double p, double q)
{
	drgb->r = p;
	drgb->g = q;
	drgb->b = hsv.v;
}

void	set_drgb_case_4(t_drgb *drgb, t_hsv hsv, double t, double p)
{
	drgb->r = t;
	drgb->g = p;
	drgb->b = hsv.v;
}
