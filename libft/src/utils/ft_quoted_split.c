/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quoted_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:32:54 by doriani           #+#    #+#             */
/*   Updated: 2023/10/27 17:54:21 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_in_charset(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

static char	*skip_quotes(char *str)
{
	char	quote;

	quote = *str++;
	while (*str && *str != quote)
		str++;
	return (str);
}

static int	count_tokens(char *str, char *delims, char *quotes)
{
	int		tokens;

	tokens = 0;
	while (*str)
	{
		while (is_in_charset(*str, delims))
			str++;
		if (*str)
			tokens++;
		while (*str && !is_in_charset(*str, delims))
		{
			if (is_in_charset(*str, quotes))
				str = skip_quotes(str);
			str++;
		}
	}
	return (tokens);
}

static char	*add_token(char *str, char *delims, char **address, char *quotes)
{
	char	*token;
	char	*runner;
	char	*token_runner;

	while (*str && is_in_charset(*str, delims))
		str++;
	runner = str;
	while (*str && ! is_in_charset(*str, delims))
	{
		if (is_in_charset(*str, quotes))
			str = skip_quotes(str);
		str++;
	}
	if (runner == str)
	{
		*address = 0;
		return (str);
	}
	token = (char *) malloc((str - runner + 1) * sizeof(char));
	token_runner = token;
	while (runner < str)
		*token_runner++ = *runner++;
	*token_runner = '\0';
	*address = token;
	return (str);
}

char	**ft_quoted_split(char *str, char *delims, char *quotes)
{
	char	**strings;
	int		tokens;
	char	**strings_runner;

	tokens = count_tokens(str, delims, quotes);
	strings = (char **) malloc((tokens + 1) * sizeof(char *));
	strings_runner = strings;
	str = add_token(str, delims, strings_runner++, quotes);
	tokens --;
	while (tokens-- >= 0)
		str = add_token(str, delims, strings_runner++, quotes);
	return (strings);
}
