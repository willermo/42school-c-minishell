/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 23:41:33 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 20:51:04 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	has_char(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	set_flags(t_format *format, char c)
{
	if (c == '-')
		format->minus = 1;
	else if (c == '+')
		format->plus = 1;
	else if (c == ' ')
		format->space = 1;
	else if (c == '#')
		format->hash = 1;
	else if (c == '0')
		format->zero = 1;
}

static t_format	*init_format(void)
{
	t_format	*format;

	format = (t_format *) malloc(sizeof(t_format));
	if (!format)
		return (NULL);
	format->minus = 0;
	format->plus = 0;
	format->space = 0;
	format->hash = 0;
	format->zero = 0;
	format->min_field = 0;
	format->precision = -1;
	format->specifier = 0;
	return (format);
}

t_format	*parse_format(const char *str, int *i)
{
	t_format	*format;

	format = init_format();
	while (has_char("-+ #0", str[*i]))
		set_flags(format, str[(*i)++]);
	if (ft_isdigit(str[*i]))
		format->min_field = ft_atoi(&str[*i]);
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i] == '.')
	{
		(*i)++;
		format->precision = ft_atoi(&str[*i]);
	}
	while (ft_isdigit(str[*i]))
		(*i)++;
	format->specifier = str[(*i)];
	return (format);
}

int	write_argument(t_format *format, va_list vargs)
{
	int	fmt;

	fmt = format->specifier;
	if (fmt == 'c')
		return (write_char(va_arg(vargs, int), format));
	else if (fmt == 's')
		return (write_string(va_arg(vargs, char *), format));
	else if (fmt == 'p')
		return (write_pointer(va_arg(vargs, unsigned long long int),
				0, format));
	else if (fmt == 'd' || fmt == 'i')
		return (write_integer(va_arg(vargs, int), format));
	else if (fmt == 'u')
		return (write_unsigned(va_arg(vargs, unsigned int), format));
	else if (fmt == 'x' || fmt == 'X')
		return (write_hex(va_arg(vargs, unsigned int), fmt == 'X', format));
	else if (fmt == '%')
		return (write(1, "%", 1));
	return (0);
}
