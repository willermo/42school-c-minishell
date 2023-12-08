/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:20:37 by doriani           #+#    #+#             */
/*   Updated: 2023/03/25 18:32:56 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_lowercase(int c)
{
	if (c < 'a' || c > 'z')
		return (0);
	return (1);
}

int	ft_toupper(int c)
{
	if (is_lowercase(c))
		return (c - 'a' + 'A');
	return (c);
}
