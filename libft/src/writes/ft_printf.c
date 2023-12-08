/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:10:47 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 20:50:54 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	int			ret;
	va_list		vargs;
	t_format	*format;

	va_start(vargs, str);
	i = 0;
	ret = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			format = parse_format(str, &i);
			ret += write_argument(format, vargs);
			free(format);
		}
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(vargs);
	return (ret);
}
