/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:57:46 by doriani           #+#    #+#             */
/*   Updated: 2023/04/23 20:19:07 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sl_delete_node(t_sl_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	lst->content = NULL;
	free(lst);
}

void	sl_destroy_list(t_sl_list **lst, void (*del)(void *))
{
	t_sl_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		sl_delete_node(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

void	sl_foreach(t_sl_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_sl_list	*sl_map(t_sl_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_sl_list	*new;
	t_sl_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = sl_create_node(f(lst->content));
	if (new == NULL)
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst != NULL)
	{
		new = sl_create_node(f(lst->content));
		if (new == NULL)
		{
			sl_destroy_list(&tmp, del);
			return (NULL);
		}
		sl_insert_end(&tmp, new);
		lst = lst->next;
	}
	return (tmp);
}
