/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:20:38 by doriani           #+#    #+#             */
/*   Updated: 2023/04/04 19:54:11 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		bytes;

	if (count + size < count || count + size < size)
		return (NULL);
	bytes = count * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	while (bytes--)
		((char *)ptr)[bytes] = 0;
	return (ptr);
}
