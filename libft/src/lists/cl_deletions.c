/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_deletions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:13:52 by doriani           #+#    #+#             */
/*   Updated: 2023/05/03 16:00:40 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cl_delete_begin(t_cl_list *head)
{
	register t_cl_list	*temp;

	if (head == NULL || head->next == head)
		return ;
	temp = head->next;
	head->next->next->prev = head;
	head->next = head->next->next;
	free(temp->data);
	temp->data = NULL;
	free(temp);
}

void	cl_delete_end(t_cl_list *head)
{
	register t_cl_list	*temp;

	if (head == NULL || head->next == head)
		return ;
	temp = head->prev;
	head->prev->prev->next = head;
	head->prev = head->prev->prev;
	free(temp->data);
	temp->data = NULL;
	free(temp);
}

void	cl_delete_node(t_cl_list *node)
{
	if (node == NULL)
		return ;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node->data);
	node->data = NULL;
	free(node);
}

void	cl_delete_node_by_position(t_cl_list *head, int position)
{
	register t_cl_list	*temp;
	register int		i;

	if (position <= 0 || position > cl_size(head))
		return ;
	if (position == 1)
		return (cl_delete_begin(head));
	if (position == cl_size(head))
		return (cl_delete_end(head));
	temp = head;
	i = 0;
	while (i++ < position)
		temp = temp->next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp->data);
	temp->data = NULL;
	free(temp);
}

void	cl_delete_list(t_cl_list *head)
{
	while (head->next != head)
		cl_delete_begin(head);
}
