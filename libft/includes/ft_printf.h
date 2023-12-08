/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:10:56 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 20:48:30 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# ifdef __APPLE__
#  define NULLSTRING "(null)"
#  define NULLPOINTER "0x0"
# else
#  define NULLSTRING "(null)"
#  define NULLPOINTER "(nil)"
# endif

typedef struct s_format
{
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
	int		min_field;
	int		precision;
	char	specifier;
}	t_format;
int			ft_printf(const char *str, ...);
t_format	*parse_format(const char *str, int *i);
int			write_argument(t_format *format, va_list vargs);
int			write_char(int c, t_format *format);
int			write_string(char *str, t_format *format);
int			write_pointer(unsigned long long n, int is_upper, t_format *format);
int			write_integer(int n, t_format *format);
int			write_unsigned(unsigned int n, t_format *format);
int			write_hex(unsigned int n, int is_upper, t_format *format);
void		prefix_alternative(char **str, int is_upper);
char		*format_precision(char *str, t_format *format);
char		*format_plus_space(int n, char *str, t_format *format);
void		format_zero(char *str, char **in, t_format *format, int len);
char		*format_min_field(char *str, t_format *format);
#endif
