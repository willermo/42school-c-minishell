/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:29:29 by doriani           #+#    #+#             */
/*   Updated: 2023/03/25 13:01:14 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_substring(char *str, const char *sub)
{
	while (*sub)
		if (*str++ != *sub++)
			return (0);
	return (1);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*runner;

	runner = (char *) haystack;
	if (*needle == '\0')
		return (runner);
	while (*runner)
	{
		if (*runner == *needle && is_substring(runner, needle))
			return (runner);
		runner++;
	}
	return (0);
}
