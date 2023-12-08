/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:24:46 by doriani           #+#    #+#             */
/*   Updated: 2023/06/09 20:15:57 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	manage_afterdot(char *nptr, double *scale, double *val)
{
	*scale = *scale / 10;
	*val = *val + (*nptr - '0') * (*scale);
}

static void	manage_beforedot(char *nptr, int *afterdot, double *val)
{
	if (*nptr == '.')
		*afterdot = 1;
	else
		*val = *val * 10.0 + (*nptr - '0');
}

double	ft_atod(char *nptr)
{
	double	val;
	int		afterdot;
	double	scale;
	int		neg;

	val = 0;
	afterdot = 0;
	scale = 1;
	neg = 0;
	if (*nptr == '-')
	{
		nptr++;
		neg = 1;
	}
	while (*nptr && (ft_isdigit(*nptr) || (*nptr == '.' && !afterdot)))
	{
		if (afterdot)
			manage_afterdot(nptr, &scale, &val);
		else
			manage_beforedot(nptr, &afterdot, &val);
		nptr++;
	}
	if (neg)
		val *= -1;
	return (val);
}
