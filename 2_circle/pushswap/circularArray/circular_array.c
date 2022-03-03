/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:49:08 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/03 23:03:31 by dkim2            ###   ########.fr       */
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
	stack->curr_element_count = 0;
	stack->top_index = 0;
	stack->bottom_index = 0;
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

/*
int	traverse(t_mystack *stack, (int)*func(int, int))
{
	int	i;
	int	top_i;
	int	bot_i;
	int res;

	if (!stack)
		return (ERROR);
	i = top_i;
	while (TRUE)
	{
		if (i == bot_i)
			break ;
		res = func(stack->array[i], stack->array[convert_index(i - 1)]);
		if (res == ERROR)
			return (ERROR);
		i = convert_index(--i);
	}
	return (res);
}
*/
