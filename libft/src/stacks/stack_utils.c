/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 00:16:23 by doriani           #+#    #+#             */
/*   Updated: 2023/04/25 13:22:01 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	st_push(t_stack *stack, int item)
{
	if (st_is_full(stack))
		return ;
	stack->array[++stack->top] = item;
}

int	st_pop(t_stack *stack)
{
	if (st_is_empty(stack))
		return (0);
	return (stack->array[stack->top--]);
}

int	st_peek(t_stack *stack)
{
	if (st_is_empty(stack))
		return (0);
	return (stack->array[stack->top]);
}

void	st_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (st_is_empty(stack))
		return ;
	tmp = stack->array[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = tmp;
}

void	st_reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (st_is_empty(stack))
		return ;
	tmp = stack->array[0];
	i = 0;
	while (i < stack->top)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
	stack->array[stack->top] = tmp;
}
