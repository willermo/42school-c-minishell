/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 23:50:04 by doriani           #+#    #+#             */
/*   Updated: 2023/04/25 13:21:58 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*st_init(unsigned int capacity)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	return (stack);
}

t_stack	*st_build(int *array, int capacity)
{
	t_stack	*stack;
	int		i;

	stack = st_init(capacity);
	if (!stack)
		return (NULL);
	i = 0;
	while (array[i] && i < capacity)
	{
		stack->array[i] = array[i];
		i++;
	}
	stack->top = capacity - 1;
	return (stack);
}

int	st_is_full(t_stack *stack)
{
	if (stack->top == -1)
		return (0);
	return ((unsigned int)stack->top == stack->capacity - 1);
}

int	st_is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

void	st_free(t_stack *stack)
{
	free(stack->array);
	free(stack);
}
