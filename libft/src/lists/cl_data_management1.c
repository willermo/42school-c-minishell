/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_data_management1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:14:01 by doriani           #+#    #+#             */
/*   Updated: 2023/05/03 16:01:43 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*cl_get_node_data(t_cl_list *node)
{
	if (node == NULL)
		return (NULL);
	return (node->data);
}

void	*cl_get_node_data_by_position(t_cl_list *head, int position)
{
	register t_cl_list	*temp;
	register int		i;

	if (position < 1 || position > cl_size(head))
		return (NULL);
	temp = head->next;
	i = 1;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}
	return (temp->data);
}

void	cl_set_node_data(t_cl_list *node, void *data)
{
	if (node == NULL)
		return ;
	if (node->data != NULL)
		free(node->data);
	node->data = data;
}

void	cl_set_node_data_by_position(t_cl_list *head, void *data,
											int position)
{
	register t_cl_list	*temp;
	register int		i;

	if (position < 1 || position > cl_size(head))
		return ;
	temp = head->next;
	i = 1;
	while (i < position)
	{
		temp = temp->next;
		i++;
	}
	if (temp->data != NULL)
		free(temp->data);
	temp->data = data;
}
