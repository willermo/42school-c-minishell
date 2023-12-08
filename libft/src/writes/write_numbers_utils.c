/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_numbers_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:47:00 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 20:50:35 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	prefix_alternative(char **str, int is_upper)
{
	char	*tmp;

	tmp = *str;
	if (is_upper)
		*str = ft_strjoin("0X", *str);
	else
		*str = ft_strjoin("0x", *str);
	free(tmp);
}

char	*format_precision(char *str, t_format *format)
{
	char	*tmp;
	int		len;
	int		offset;
	int		pr;

	len = ft_strlen(str);
	offset = 0;
	if (format->precision == -1)
		pr = 1;
	else
		pr = format->precision;
	if (str[0] == '-')
		offset = 1;
	if (pr > len - offset)
	{
		tmp = (char *) ft_calloc(pr + offset + 1, sizeof(char));
		ft_memcpy(tmp, str, offset);
		ft_memset(tmp + offset, '0', pr);
		ft_memcpy(tmp + pr - len + 2 * offset, str + offset, len - offset);
		free(str);
		str = tmp;
	}
	return (str);
}

char	*format_plus_space(int n, char *str, t_format *format)
{
	char	*tmp;

	if (format->plus && n >= 0)
	{
		tmp = ft_strjoin("+", str);
		free(str);
		str = tmp;
	}
	else if (format->space && n >= 0)
	{
		tmp = ft_strjoin(" ", str);
		free(str);
		str = tmp;
	}
	return (str);
}

void	format_zero(char *str, char **in, t_format *format, int len)
{
	char	*tmp;

	tmp = *in;
	ft_memset(tmp, '0', format->min_field);
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
	{
		ft_memset(tmp, str[0], 1);
		ft_memcpy(tmp + format->min_field - len + 1, str + 1, len - 1);
	}
	else
		ft_memcpy(tmp + format->min_field - len, str, len);
}

char	*format_min_field(char *str, t_format *format)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (format->min_field > len)
	{
		tmp = (char *) ft_calloc(format->min_field + 1, sizeof(char));
		if (format->zero && !format->minus && format->precision == -1)
			format_zero(str, &tmp, format, len);
		else if (format->minus)
		{
			ft_memcpy(tmp, str, len);
			ft_memset(tmp + len, ' ', format->min_field - len);
		}
		else
		{
			ft_memset(tmp, ' ', format->min_field);
			ft_memcpy(tmp + format->min_field - len, str, len);
		}
		free(str);
		str = tmp;
	}
	return (str);
}
