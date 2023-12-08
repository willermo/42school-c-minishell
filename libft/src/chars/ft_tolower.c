/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:20:37 by doriani           #+#    #+#             */
/*   Updated: 2023/03/25 18:34:08 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_uppercase(int c)
{
	if (c < 'A' || c > 'Z')
		return (0);
	return (1);
}

int	ft_tolower(int c)
{
	if (is_uppercase(c))
		return (c - 'A' + 'a');
	return (c);
}
