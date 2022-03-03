/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:49:14 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/03 23:58:34 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_array.h"

int	is_ascending(t_mystack *stack)
{
	int	curr;
	int	next;
	int	bot_i;

	if (!stack)
		return (ERROR);
	curr = stack->top_index;
	bot_i = stack->bottom_index;
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

int	is_descending(t_mystack *stack)
{
	int	curr;
	int	next;
	int	bot_i;

	if (!stack)
		return (ERROR);
	curr = stack->top_index;
	bot_i = stack->bottom_index;
	while (TRUE)
	{
		if (curr == bot_i)
			return (TRUE);
		next = convert_index(curr - 1, stack->max_size);
		if (stack->array[curr] < stack->array[next])
			return (FALSE);
		curr = convert_index(--curr, stack->max_size);
	}
}

int	not_duplicated(t_mystack *stack, int key)
{
	int	curr;
	int	bot_i;

	if (!stack)
		return (ERROR);
	curr = stack->top_index;
	bot_i = stack->bottom_index;
	while (curr != bot_i)
	{
		if (stack->array[curr] == key)
			return (FALSE);
		curr = convert_index(--curr, stack->max_size);
	}
	return (TRUE);
}