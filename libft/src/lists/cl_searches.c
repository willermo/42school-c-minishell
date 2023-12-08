/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_searches.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:42:55 by doriani           #+#    #+#             */
/*   Updated: 2023/05/03 15:59:15 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cl_get_node_position(t_cl_list *head, void *data,
								int (*cmp_data)(void *, void *))
{
	register t_cl_list	*temp;
	register int		position;

	if (head == NULL || head->next == head)
		return (0);
	temp = head->next;
	position = 1;
	while (temp != head)
	{
		if (cmp_data(temp->data, data) == 0)
			return (position);
		temp = temp->next;
		position++;
	}
	return (0);
}

t_cl_list	*cl_get_node_by_position(t_cl_list *head, int pos)
{
	register t_cl_list	*temp;
	register int		i;

	if (pos < 1 || pos > cl_size(head) || head == NULL || cl_is_empty(head))
		return (NULL);
	temp = head->next;
	i = 1;
	while (i++ < pos)
		temp = temp->next;
	return (temp);
}

t_cl_list	*cl_get_node_by_data(t_cl_list *head, void *data,
									int (*cmp_data)(void *, void *))
{
	register t_cl_list	*temp;

	if (head == NULL || head->next == head)
		return (NULL);
	temp = head->next;
	while (temp != head)
	{
		if (cmp_data(temp->data, data) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
