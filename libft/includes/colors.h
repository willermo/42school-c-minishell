/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:12:47 by doriani           #+#    #+#             */
/*   Updated: 2023/06/10 10:24:12 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H
# include <math.h>

typedef enum e_color
{
	BLACK = 0x000000,
	WHITE = 0xFFFFFF,
	RED = 0xFF0000,
	GREEN = 0x00FF00,
	BLUE = 0x0000FF,
	YELLOW = 0xFFFF00,
	CYAN = 0x00FFFF,
	MAGENTA = 0xFF00FF
}				t_color;
typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_rgb;
typedef struct s_drgb
{
	double	r;
	double	g;
	double	b;
}				t_drgb;
typedef struct s_hsv
{
	double	h;
	double	s;
	double	v;
}				t_hsv;
t_rgb	hsv_to_rgb(t_hsv hsv);
void	set_drgb(t_drgb *drgb, t_hsv hsv);
void	set_drgb_case_1(t_drgb *drgb, t_hsv hsv, double q, double p);
void	set_drgb_case_0(t_drgb *drgb, t_hsv hsv, double t, double p);
void	set_drgb_case_2(t_drgb *drgb, t_hsv hsv, double p, double t);
void	set_drgb_case_3(t_drgb *drgb, t_hsv hsv, double p, double q);
void	set_drgb_case_4(t_drgb *drgb, t_hsv hsv, double t, double p);
void	set_drgb_default(t_drgb *drgb, t_hsv hsv, double p, double q);
t_hsv	rgb_to_hsv(t_rgb rgb);
int		rgb_to_int(unsigned char r, unsigned char g, unsigned char b);
int		t_rgb_to_int(t_rgb rgb);
t_rgb	int_to_t_rgb(int color);
int		hsv_to_int(double h, double s, double v);
int		t_hsv_to_int(t_hsv hsv);
t_hsv	int_to_t_hsv(int color);
t_rgb	rgb_add(t_rgb rgb1, t_rgb rgb2);
t_rgb	rgb_sub(t_rgb rgb1, t_rgb rgb2);
t_rgb	rgb_mult(t_rgb rgb1, t_rgb rgb2);
t_rgb	rgb_div(t_rgb rgb1, t_rgb rgb2);
t_rgb	rgb_mult_scalar(t_rgb rgb, double scalar);
t_rgb	rgb_div_scalar(t_rgb rgb, double scalar);
t_rgb	rgb_clamp(t_rgb rgb);
#endif
