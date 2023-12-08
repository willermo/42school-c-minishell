/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:01:22 by doriani           #+#    #+#             */
/*   Updated: 2023/03/24 21:11:58 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	char	*runner;

	runner = dest;
	while (*src)
		*runner++ = *src++;
	*runner = '\0';
	return (dest);
}
