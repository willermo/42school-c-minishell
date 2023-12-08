/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_data_management2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:59:28 by doriani           #+#    #+#             */
/*   Updated: 2023/05/03 16:01:23 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cl_list	*cl_get_max_node(t_cl_list *head, int (*cmp_data)(void *, void *))
{
	register t_cl_list	*temp;
	register t_cl_list	*max;

	if (head == NULL || cl_is_empty(head))
		return (NULL);
	max = head->next;
	temp = max->next;
	while (temp != head)
	{
		if (cmp_data(temp->data, max->data) > 0)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

int	cl_get_max_node_position(t_cl_list *head, int (*cmp_data)(void *, void *))
{
	register t_cl_list	*temp;
	register t_cl_list	*max;
	register int		position;
	register int		max_position;

	if (head == NULL || cl_is_empty(head))
		return (-1);
	max = head->next;
	max_position = 1;
	temp = max->next;
	position = 2;
	while (temp != head)
	{
		if (cmp_data(temp->data, max->data) > 0)
		{
			max = temp;
			max_position = position;
		}
		temp = temp->next;
		position++;
	}
	return (max_position);
}

t_cl_list	*cl_get_min_node(t_cl_list *head, int (*cmp_data)(void *, void *))
{
	register t_cl_list	*temp;
	register t_cl_list	*min;

	if (head == NULL || cl_is_empty(head))
		return (NULL);
	min = head->next;
	temp = min->next;
	while (temp != head)
	{
		if (cmp_data(temp->data, min->data) < 0)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

int	cl_get_min_node_position(t_cl_list *head, int (*cmp_data)(void *, void *))
{
	register t_cl_list	*temp;
	register t_cl_list	*min;
	register int		position;
	register int		min_position;

	if (head == NULL || cl_is_empty(head))
		return (-1);
	min = head->next;
	min_position = 1;
	temp = min->next;
	position = 2;
	while (temp != head)
	{
		if (cmp_data(temp->data, min->data) < 0)
		{
			min = temp;
			min_position = position;
		}
		temp = temp->next;
		position++;
	}
	return (min_position);
}
