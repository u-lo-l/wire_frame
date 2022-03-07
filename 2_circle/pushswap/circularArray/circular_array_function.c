/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_function.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:49:20 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/07 23:12:52 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_array.h"
#include <stdio.h>

int add_top(t_mystack *stack, int num)
{
	if (!stack)
		return (ERROR);
	if (stack->curr == stack->max_size)
		return (FALSE);
	if (stack->curr > 0)
		stack->top_index = convert_index(stack->top_index + 1, stack->max_size);
	stack->array[stack->top_index] = num;
	stack->curr++;
	return (TRUE);
}

int add_bot(t_mystack *stack, int num)
{
	if (!stack)
		return (ERROR);
	if (stack->curr == stack->max_size)
		return (FALSE);
	if (stack->curr > 0)
		stack->bottom_index = convert_index(stack->bottom_index - 1, stack->max_size);
	stack->array[stack->bottom_index] = num;
	stack->curr++;
	return (TRUE);
}

int rem_top(t_mystack *stack)
{
	if (!stack)
		return (ERROR);
	if (stack->curr == 0)
		return (FALSE);
	if (stack->curr > 1)
		stack->top_index = convert_index(stack->top_index - 1, stack->max_size);
	stack->curr--;
	return (TRUE);
}

int rem_bot(t_mystack *stack)
{
	if (!stack)
		return (ERROR);
	if (stack->curr == 0)
		return (FALSE);
	if (stack->curr > 1)
		stack->bottom_index = convert_index(stack->bottom_index + 1, stack->max_size);
	stack->curr--;
	return (TRUE);
}
