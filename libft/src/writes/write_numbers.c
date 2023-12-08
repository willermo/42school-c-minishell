/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 19:59:58 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 20:50:30 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	write_integer(int n, t_format *format)
{
	char	*str;
	int		len;

	if (format->precision == 0 && n == 0)
		str = (char *) ft_calloc(1, sizeof(char));
	else
		str = ft_itoa(n);
	str = format_precision(str, format);
	str = format_plus_space(n, str, format);
	str = format_min_field(str, format);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	write_unsigned(unsigned int n, t_format *format)
{
	char	*str;
	int		len;

	if (format->precision == 0 && n == 0)
		str = (char *) ft_calloc(1, sizeof(char));
	else
		str = ft_uitoa(n);
	str = format_precision(str, format);
	str = format_plus_space(n, str, format);
	str = format_min_field(str, format);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	write_hex(unsigned int n, int is_upper, t_format *format)
{
	char	*str;
	int		len;

	if (format->precision == 0 && n == 0)
		str = (char *) ft_calloc(1, sizeof(char));
	else
	{
		str = ft_itoa_base(n, 16, is_upper);
		if (format->hash && n != 0)
			prefix_alternative(&str, is_upper);
	}
	str = format_precision(str, format);
	str = format_plus_space(n, str, format);
	str = format_min_field(str, format);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
