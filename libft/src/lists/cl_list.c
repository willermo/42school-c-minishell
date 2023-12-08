/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 10:14:58 by doriani           #+#    #+#             */
/*   Updated: 2023/06/10 10:21:44 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cl_list	*cl_init_list(void)
{
	register t_cl_list	*head;

	head = (t_cl_list *)malloc(sizeof(t_cl_list));
	head->data = NULL;
	head->next = head;
	head->prev = head;
	return (head);
}

t_cl_list	*cl_create_node(void *data)
{
	register t_cl_list	*new_node;

	new_node = (t_cl_list *)malloc(sizeof(t_cl_list));
	if (new_node == NULL)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	cl_destroy_list(t_cl_list **head)
{
	cl_delete_list(*head);
	free(*head);
	*head = NULL;
}

t_cl_list	*cl_build_list(void **array, int size)
{
	register t_cl_list	*head;
	int					i;

	if (size <= 0)
		return (NULL);
	head = cl_init_list();
	i = 0;
	while (i < size)
		cl_insert_end(head, array[i++]);
	return (head);
}

void	cl_display(t_cl_list *head, t_direction verso,
						void (*display_data)(void *))
{
	register t_cl_list	*temp;

	temp = head;
	if (head == NULL)
		ft_putstr("List does not exist!");
	else if (cl_is_empty(head))
		ft_putstr("List is empty!");
	else if (verso == reverse)
	{
		while (temp->prev != head)
		{
			temp = temp->prev;
			display_data(temp->data);
			ft_putchar(' ');
		}
	}
	else
	{
		while (temp->next != head)
		{
			temp = temp->next;
			display_data(temp->data);
			ft_putchar(' ');
		}
	}
}
