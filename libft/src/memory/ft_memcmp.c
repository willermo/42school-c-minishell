/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:23:47 by doriani           #+#    #+#             */
/*   Updated: 2023/04/04 16:21:47 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*uc1;
	unsigned char	*uc2;

	if (n == 0)
		return (0);
	uc1 = (unsigned char *) s1;
	uc2 = (unsigned char *) s2;
	i = 0;
	while (i < n && *uc1 == *uc2)
	{
		uc1++;
		uc2++;
		i++;
	}
	if (i == n)
	{
		uc1--;
		uc2--;
	}
	return (*uc1 - *uc2);
}
