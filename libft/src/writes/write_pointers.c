/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:15:50 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 20:50:25 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	init_pointer_string(unsigned long long n, char **str, int is_upper)
{
	char	*tmp;

	if (n == 0)
		*str = ft_strdup(NULLPOINTER);
	else
	{
		tmp = ft_itoa_base(n, 16, is_upper);
		*str = ft_strjoin("0x", tmp);
		free(tmp);
	}
	return (ft_strlen(*str));
}

int	write_pointer(unsigned long long n, int is_upper, t_format *format)
{
	char	*str;
	int		count;
	int		len;

	len = init_pointer_string(n, &str, is_upper);
	if (format->minus == 1)
	{
		count = write(1, str, len);
		while (format->min_field > count)
			count += write(1, " ", 1);
	}
	else
	{
		count = 0;
		while (format->min_field-- > len + 2)
			count += write(1, " ", 1);
		count += write(1, str, len);
	}
	free(str);
	return (count);
}
