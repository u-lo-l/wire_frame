/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:48:56 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/07 22:59:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_array.h"

void act_push(t_mystack *from, t_mystack *to)
{
	int temp;

	if (from->curr == 0)
		return ;
	temp = from->array[from->top_index];
	rem_top(from);
	add_top(to, temp);
}

void act_swap(t_mystack *stack)
{
	int temp;
	int first;
	int secnd;

	if (!stack)
		return ;
	if (stack->curr < 2)
		return ;
	first = stack->top_index;
	secnd = convert_index(first - 1, stack->max_size);
	temp = stack->array[first];
	stack->array[first] = stack->array[secnd];
	stack->array[secnd] = temp;
}

void act_rot(t_mystack *stack)
{
	int temp;

	if (stack->curr < 2)
		return ;
	temp = stack->array[stack->top_index];
	rem_top(stack);
	add_bot(stack, temp);
}

void act_rrot(t_mystack *stack)
{
	int temp;

	if (stack->curr < 2)
		return ;
	temp = stack->array[stack->bottom_index];
	rem_bot(stack);
	add_top(stack, temp);
}
