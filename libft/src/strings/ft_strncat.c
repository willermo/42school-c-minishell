/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:18:44 by doriani           #+#    #+#             */
/*   Updated: 2023/02/22 17:29:08 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*idx;
	unsigned int	len;

	idx = dest;
	len = 0;
	while (*idx++)
		;
	idx--;
	while (*src && len < nb)
	{
		*idx++ = *src++;
		len++;
	}
	*idx = '\0';
	return (dest);
}
