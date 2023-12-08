/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:33:52 by doriani           #+#    #+#             */
/*   Updated: 2023/04/14 00:38:49 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_buffer_size_16(unsigned long long int n)
{
	int	size;

	size = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

char	*ft_itoa_16(unsigned long long int n, int uppercase)
{
	char	*str;
	int		i;
	char	*base_str;

	base_str = "0123456789abcdef";
	if (uppercase)
		base_str = "0123456789ABCDEF";
	i = 0;
	str = malloc(sizeof(char) * get_buffer_size_16(n));
	if (!str)
		return (NULL);
	while (n / 16 != 0)
	{
		str[i++] = base_str[n % 16];
		n /= 16;
	}
	str[i++] = base_str[n % 16];
	str[i] = '\0';
	return (ft_strrev(str));
}
