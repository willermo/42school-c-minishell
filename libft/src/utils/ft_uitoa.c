/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:52:38 by doriani           #+#    #+#             */
/*   Updated: 2023/04/14 14:53:48 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_buffer_size(unsigned int n)
{
	int	size;

	size = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * get_buffer_size(n));
	if (!str)
		return (NULL);
	while (n / 10 != 0)
	{
		str[i++] = n % 10 + '0';
		n /= 10;
	}
	str[i++] = n % 10 + '0';
	str[i] = '\0';
	return (ft_strrev(str));
}
