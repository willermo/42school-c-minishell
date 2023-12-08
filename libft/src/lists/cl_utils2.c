/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:13:20 by doriani           #+#    #+#             */
/*   Updated: 2023/05/06 11:59:57 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// NULL checking is useless here, because it's a circular list
// and the head node is always present.
// nontheless it is a good practice to check for NULL pointers
// and it will be needed for non circular lists.
void	cl_swap_list_nodes(t_cl_list *a, t_cl_list *b)
{
	register t_cl_list	*temp;

	temp = a->next;
	a->next = b->next;
	b->next = temp;
	if (a->next != NULL)
		a->next->prev = a;
	if (b->next != NULL)
		b->next->prev = b;
	temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;
	if (a->prev != NULL)
		a->prev->next = a;
	if (b->prev != NULL)
		b->prev->next = b;
}

void	cl_swap_list_nodes_by_position(t_cl_list *head, int a, int b)
{
	register t_cl_list	*temp_a;
	register t_cl_list	*temp_b;

	if (a < 1 || a > cl_size(head) || b < 1 || b > cl_size(head))
		return ;
	temp_a = cl_get_node_by_position(head, a);
	temp_b = cl_get_node_by_position(head, b);
	cl_swap_list_nodes(temp_a, temp_b);
}

int	cl_is_sorted(t_cl_list *head, t_sort_order order,
			int (*cmp_data)(void *, void *))
{
	register t_cl_list	*temp;

	if (head == NULL || head->next == head)
		return (1);
	temp = head->next;
	while (temp->next != head)
	{
		if ((order == ascending && cmp_data(temp->data, temp->next->data) > 0) \
		|| (order == descending && cmp_data(temp->data, temp->next->data) < 0))
			return (0);
		temp = temp->next;
	}
	return (1);
}
