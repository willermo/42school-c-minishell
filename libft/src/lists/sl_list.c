/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:12:42 by doriani           #+#    #+#             */
/*   Updated: 2023/04/23 20:14:34 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_sl_list	*sl_create_node(void *content)
{
	t_sl_list	*new;

	new = (t_sl_list *)malloc(sizeof(t_sl_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	sl_size(t_sl_list *lst)
{
	int			i;
	t_sl_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sl_insert_begin(t_sl_list **lst, t_sl_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	sl_insert_end(t_sl_list **lst, t_sl_list *new)
{
	t_sl_list	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = sl_last(*lst);
	tmp->next = new;
}

t_sl_list	*sl_last(t_sl_list *lst)
{
	t_sl_list	*tmp;

	tmp = lst;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
