/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:54:48 by doriani           #+#    #+#             */
/*   Updated: 2023/03/24 09:36:22 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	occurs(const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		if (((unsigned char *) src)[i++] == (unsigned char) c)
			return (1);
	return (0);
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	if (!occurs(src, c, n))
		return (NULL);
	i = 0;
	while (i < n && ((unsigned char *) src)[i] != (unsigned char) c)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest + i + 1);
}
