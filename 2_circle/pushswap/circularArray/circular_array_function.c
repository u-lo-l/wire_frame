/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_function.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:49:20 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/04 00:01:11 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_array.h"
#include <stdio.h>

int add_top(t_mystack *stack, int num)
{
	if (!stack)
		return (ERROR);
	if (stack->curr_element_count == stack->max_size)
		return (FALSE);
	if (stack->curr_element_count > 0)
	{
		stack->top_index++;
		stack->top_index %= stack->max_size;
	}
	stack->array[stack->top_index] = num;
	stack->curr_element_count++;
	return (TRUE);
}

int add_bot(t_mystack *stack, int num)
{
	if (!stack)
		return (ERROR);
	if (stack->curr_element_count == stack->max_size)
		return (FALSE);
	if (stack->curr_element_count > 0)
	{	
		stack->bottom_index--;
		stack->bottom_index %= stack->max_size;
	}
	stack->array[stack->bottom_index] = num;
	stack->curr_element_count++;
	return (TRUE);
}

int rem_top(t_mystack *stack)
{
	if (!stack)
		return (ERROR);
	if (stack->curr_element_count == 0)
		return (FALSE);
	if (stack->curr_element_count > 1)
	{
		stack->top_index--;
		stack->top_index %= stack->max_size;
	}
	stack->curr_element_count--;
	return (TRUE);
}

int rem_bot(t_mystack *stack)
{
	if (!stack)
		return (ERROR);
	if (stack->curr_element_count == 0)
		return (FALSE);
	if (stack->curr_element_count > 1)
	{
		stack->top_index--;
		stack->top_index %= stack->max_size;
	}
	stack->curr_element_count--;
	return (TRUE);
}
