/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:49:08 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/16 02:31:27 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_array.h"
#include <stdlib.h>

t_mystack	*new_stack(int size)
{
	t_mystack	*stack;

	stack = malloc(sizeof(t_mystack));
	if (!stack)
		return (NULL);
	stack->max_size = size;
	stack->curr = 0;
	stack->top_index = 0;
	stack->bottom_index = 0;
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