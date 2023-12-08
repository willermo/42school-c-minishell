/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_additions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:41:03 by doriani           #+#    #+#             */
/*   Updated: 2023/05/03 16:01:54 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cl_add_node_begin(t_cl_list *head, t_cl_list *new_node)
{
	if (head == NULL || new_node == NULL)
		return ;
	new_node->next = head->next;
	head->next->prev = new_node;
	head->next = new_node;
	new_node->prev = head;
}

void	cl_add_node_end(t_cl_list *head, t_cl_list *new_node)
{
	if (head == NULL || new_node == NULL)
		return ;
	new_node->prev = head->prev;
	head->prev->next = new_node;
	head->prev = new_node;
	new_node->next = head;
}

void	cl_add_node_by_position(t_cl_list *head, t_cl_list *new_node, int pos)
{
	register t_cl_list	*temp;
	register int		i;

	if (pos < 1 || pos > cl_size(head) + 1)
		return ;
	if (pos == 1)
		return (cl_add_node_begin(head, new_node));
	if (pos == cl_size(head) + 1)
		return (cl_add_node_end(head, new_node));
	temp = head->next;
	i = 1;
	while (i < pos - 1)
	{
		temp = temp->next;
		i++;
	}
	new_node->next = temp->next;
	temp->next->prev = new_node;
	temp->next = new_node;
	new_node->prev = temp;
}
