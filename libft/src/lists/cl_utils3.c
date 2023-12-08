/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:42:21 by doriani           #+#    #+#             */
/*   Updated: 2023/05/09 22:42:03 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cl_list	*cl_dup_node(t_cl_list *node, void *(*dup_data)(void *))
{
	register t_cl_list	*new_node;

	if (node == NULL)
		return (NULL);
	new_node = cl_create_node(dup_data(node->data));
	return (new_node);
}

t_cl_list	*cl_dup_node_by_position(t_cl_list *head, int position,
											void *(*dup_data)(void *))
{
	register t_cl_list	*temp;

	if (position < 1 || position > cl_size(head))
		return (NULL);
	temp = cl_get_node_by_position(head, position);
	return (cl_dup_node(temp, dup_data));
}

t_cl_list	*cl_dup_list(t_cl_list *head, void *(*dup_data)(void *))
{
	t_cl_list			*new;
	register t_cl_list	*runner;

	if (head == NULL || dup_data == NULL)
		return (NULL);
	new = cl_init_list();
	if (new == NULL)
		return (NULL);
	runner = head->next;
	while (runner != head)
	{
		cl_add_node_end(new, cl_dup_node(runner, dup_data));
		runner = runner->next;
	}
	if (cl_size(new) != cl_size(head))
	{
		cl_destroy_list(&new);
		return (NULL);
	}
	else
		return (new);
}

void	cl_foreach(t_cl_list *head, void (*f)(void *))
{
	if (head == NULL || head->next == head || f == NULL)
		return ;
	head = head->next;
	while (head != NULL)
	{
		f(head->data);
		head = head->next;
	}
}

t_cl_list	*cl_map(t_cl_list *head, void (*f)(void *),
					void *(*dup_data)(void *))
{
	register t_cl_list	*new;

	if (head == NULL || f == NULL)
		return (NULL);
	new = cl_dup_list(head, dup_data);
	if (new == NULL)
		return (NULL);
	cl_foreach(new, f);
	return (new);
}
