/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_insertions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:13:43 by doriani           #+#    #+#             */
/*   Updated: 2023/05/03 16:00:23 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cl_insert_begin(t_cl_list *head, void *data)
{
	register t_cl_list	*new_node;

	if (head == NULL)
		return ;
	new_node = cl_create_node(data);
	if (new_node)
	{
		new_node->next = head->next;
		head->next->prev = new_node;
		head->next = new_node;
		new_node->prev = head;
	}
}

void	cl_insert_end(t_cl_list *head, void *data)
{
	register t_cl_list	*new_node;

	if (head == NULL)
		return ;
	new_node = cl_create_node(data);
	if (new_node)
	{
		new_node->prev = head->prev;
		head->prev->next = new_node;
		head->prev = new_node;
		new_node->next = head;
	}
}

void	cl_insert_by_position(t_cl_list *head, void *data, int position)
{
	register t_cl_list	*new_node;
	register t_cl_list	*temp;
	register int		i;

	if (position < 1 || position > cl_size(head) + 1)
		return ;
	if (position == 1)
		return (cl_insert_begin(head, data));
	if (position == cl_size(head) + 1)
		return (cl_insert_end(head, data));
	new_node = cl_create_node(data);
	if (new_node == NULL)
		return ;
	temp = head;
	i = 0;
	while (i++ < position - 1)
		temp = temp->next;
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev = new_node;
	temp->next = new_node;
}
