/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:46:23 by doriani           #+#    #+#             */
/*   Updated: 2023/04/16 12:46:34 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_buffer_size(unsigned long long int n, int base)
{
	int	size;

	size = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char	*ft_uitoa_base(unsigned long long int n, int base, int is_upper)
{
	char	*str;
	int		i;
	char	*base_str;

	i = 0;
	base_str = "0123456789abcdef";
	if (is_upper)
		base_str = "0123456789ABCDEF";
	str = malloc(sizeof(char) * get_buffer_size(n, base));
	if (!str)
		return (NULL);
	while (n / base != 0)
	{
		str[i++] = base_str[n % base];
		n /= base;
	}
	str[i++] = base_str[n % base];
	str[i] = '\0';
	return (ft_strrev(str));
}
