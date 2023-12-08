/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:55:39 by doriani           #+#    #+#             */
/*   Updated: 2023/03/30 03:00:10 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	number[11];
	int		i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	i = 0;
	while (n > 9)
	{
		number[i++] = '0' + n % 10;
		n /= 10;
	}
	number[i] = '0' + n;
	while (i >= 0)
		write(fd, &number[i--], 1);
}
