/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:22:23 by doriani           #+#    #+#             */
/*   Updated: 2023/11/02 19:47:46 by doriani          ###   ########.fr       */
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

static int	count_tokens(char *str, char *delimiters)
{
	int	tokens;

	tokens = 0;
	while (*str)
	{
		while (is_in_charset(*str, delimiters))
			str++;
		if (*str)
			tokens++;
		while (*str && ! is_in_charset(*str, delimiters))
			str++;
	}
	return (tokens);
}

static char	*add_token(char *str, char *delimiters, char **address)
{
	char		*token;
	char		*runner;
	char		*token_runner;

	while (*str && is_in_charset(*str, delimiters))
		str++;
	runner = str;
	while (*str && ! is_in_charset(*str, delimiters))
		str++;
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

char	**ft_split(char *str, char *delimiters)
{
	char	**strings;
	int		tokens;
	char	**strings_runner;

	tokens = count_tokens(str, delimiters);
	strings = (char **) malloc((tokens + 1) * sizeof(char *));
	strings_runner = strings;
	str = add_token(str, delimiters, strings_runner++);
	tokens --;
	while (tokens-- >= 0)
		str = add_token(str, delimiters, strings_runner++);
	return (strings);
}
