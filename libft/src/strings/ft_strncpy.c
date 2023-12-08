/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:15:20 by doriani           #+#    #+#             */
/*   Updated: 2023/03/25 09:09:06 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

// Line 29 makes ft_strncpy behavior different from standard strncpy
// This is requested by 42 Libft project specifications
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*runner;

	i = 0;
	runner = dest;
	while (*src && i < n)
	{
		*runner++ = *src++;
		i++;
	}
	*runner = '\0';
	while (i < n)
	{
		*runner++ = '\0';
		i++;
	}
	return (dest);
}
