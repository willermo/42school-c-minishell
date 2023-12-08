/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:13:32 by doriani           #+#    #+#             */
/*   Updated: 2023/06/10 10:21:16 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cl_size(t_cl_list *head)
{
	register t_cl_list	*temp;
	register int		count;

	if (head == NULL)
		return (-1);
	temp = head;
	count = 0;
	while (temp->next != head)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	cl_is_empty(t_cl_list *head)
{
	if (head->next == head)
		return (1);
	return (0);
}

void	cl_rotate(t_cl_list *head, t_direction direction)
{
	if (head == NULL || head->next == head)
		return ;
	if (direction == straight)
		cl_swap_list_nodes(head, head->next);
	else if (direction == reverse)
		cl_swap_list_nodes(head->prev, head);
}

void	cl_reverse(t_cl_list *head)
{
	register t_cl_list	*temp;
	register t_cl_list	*temp2;

	if (head == NULL)
		return ;
	temp = head->next;
	while (temp != head)
	{
		temp2 = temp->next;
		temp->next = temp->prev;
		temp->prev = temp2;
		temp = temp2;
	}
	temp = head->next;
	head->next = head->prev;
	head->prev = temp;
}

void	cl_sort(t_cl_list *head, t_sort_order order,
				int (*cmp_data)(void *, void *))
{
	register t_cl_list	*temp1;
	register t_cl_list	*temp2;

	if (head == NULL || cl_size(head) < 2)
		return ;
	temp1 = head->next;
	while (temp1->next != head)
	{
		temp2 = temp1->next;
		while (temp2 != head)
		{
			if ((cmp_data(temp1->data, temp2->data) > 0 && order == ascending) \
			|| (cmp_data(temp1->data, temp2->data) < 0 && order == descending))
			{
				cl_swap_list_nodes(temp1, temp2);
				temp1 = temp2;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
