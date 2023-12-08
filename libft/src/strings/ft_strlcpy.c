/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:57:16 by doriani           #+#    #+#             */
/*   Updated: 2023/03/30 02:56:59 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*p;

	p = dst;
	if (dstsize != 0)
	{
		while (--dstsize != 0)
		{
			*p = *src;
			if (*p == '\0')
				return (p - dst);
			p++;
			src++;
		}
		*p = '\0';
	}
	return ((p - dst) + ft_strlen(src));
}
