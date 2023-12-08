/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:41:40 by doriani           #+#    #+#             */
/*   Updated: 2023/04/14 00:44:28 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_buffer_size_8(int n)
{
	int	size;

	size = 1;
	if (n == 0)
		return (2);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n /= 8;
		size++;
	}
	return (size);
}

char	*ft_itoa_8(int n)
{
	char	*str;
	int		i;
	char	*base_str;

	base_str = "01234567";
	i = 0;
	str = malloc(sizeof(char) * get_buffer_size_8(n));
	if (!str)
		return (NULL);
	while (n / 8 != 0)
	{
		str[i++] = base_str[n % 8];
		n /= 8;
	}
	str[i++] = base_str[n % 8];
	str[i] = '\0';
	return (ft_strrev(str));
}
