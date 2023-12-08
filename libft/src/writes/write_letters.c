/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:03:44 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 20:50:41 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	write_char(int c, t_format *format)
{
	int		count;
	char	pad;

	count = 0;
	pad = ' ';
	if (format->minus)
	{
		count += write(1, &c, 1);
		while (format->min_field-- > 1)
			count += write(1, &pad, 1);
	}
	else
	{
		while (format->min_field-- > 1)
			count += write(1, &pad, 1);
		count += write(1, &c, 1);
	}
	return (count);
}

int	write_string(char *s, t_format *format)
{
	char	*str;
	int		count;
	int		len;

	if (s == NULL)
		str = NULLSTRING;
	else
		str = s;
	len = ft_strlen(str);
	if (format->precision >= 0 && format->precision < len)
		len = format->precision;
	if (format->minus == 1)
	{
		count = write(1, str, len);
		while (format->min_field > count)
			count += write(1, " ", 1);
	}
	else
	{
		count = 0;
		while (format->min_field-- > len)
			count += write(1, " ", 1);
		count += write(1, str, len);
	}
	return (count);
}
