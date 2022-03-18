/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:49:08 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 02:47:15 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/circular_array.h"

t_mystack	*new_stack(int size)
{
	t_mystack	*stack;

	stack = malloc(sizeof(t_mystack));
	if (!stack)
		return (NULL);
	stack->max_size = size;
	stack->curr = 0;
	stack->top_idx = 0;
	stack->bot_idx = 0;
	stack->stack_name = 0;
	stack->array = malloc(sizeof(int) * size);
	if (!(stack->array))
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

void	delete_stack(t_mystack *stack)
{
	free(stack->array);
	free(stack);
}

int	convert_index(int idx, int max_size)
{
	idx += max_size;
	idx %= max_size;
	return (idx);
}

int	is_ascending(t_mystack *stack)
{
	int	curr;
	int	next;
	int	bot_i;

	if (!stack)
		return (ERROR);
	curr = stack->top_idx;
	bot_i = stack->bot_idx;
	while (TRUE)
	{
		if (curr == bot_i)
			return (TRUE);
		next = convert_index(curr - 1, stack->max_size);
		if (stack->array[curr] > stack->array[next])
			return (FALSE);
		curr = convert_index(--curr, stack->max_size);
	}
}