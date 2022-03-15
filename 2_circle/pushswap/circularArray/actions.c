/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 21:48:56 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/16 02:31:16 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_array.h"
#include <unistd.h>

static void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int act_push(t_mystack *from, t_mystack *to)
{
	int temp;
	
	if (from->curr == 0)
		return (FALSE);
	temp = from->array[from->top_index];
	rem_top(from);
	add_top(to, temp);
	if (to->stack_name == 'a')
		write(1, "pa\n", 3);
	else if (to->stack_name == 'b')
		write(1, "pb\n", 3);
	return (TRUE);
}

int act_swap(t_mystack *stack1, t_mystack *stack2)
{
	int temp;
	int first;
	int secnd;

	if (stack1 && stack1->curr >= 2)
	{
		first = stack1->top_index;
		secnd = convert_index(first - 1, stack1->max_size);
		swap(stack1->array + first, stack1->array + secnd);
		if (stack2 && stack2->curr >= 2)
		{
			first = stack2->top_index;
			secnd = convert_index(first - 1, stack2->max_size);
			swap(stack2->array + first, stack2->array + secnd);
			write(1, "ss\n", 3);
			return (TRUE);
		}
		if (stack1->stack_name == 'a')
			write(1, "sa\n", 3);
		else if (stack1->stack_name == 'b')
			write(1, "sb\n", 3);
		return (TRUE);
	}
	return (FALSE);
}

int act_rot(t_mystack *stack1, t_mystack *stack2)
{
	int temp;

	if (stack1 != NULL && stack1->curr >= 2)
	{
		temp = stack1->array[stack1->top_index];
		rem_top(stack1);
		add_bot(stack1, temp);
		if (stack2 != NULL && stack2->curr >= 2)
		{
			temp = stack2->array[stack1->top_index];
			rem_top(stack2);
			add_bot(stack2, temp);
			write(1, "rr\n", 3);
			return (TRUE);
		}
		if (stack1->stack_name == 'a')
			write(1, "ra\n", 3);
		else if (stack1->stack_name == 'b')
			write(1, "rb\n", 3);
		return (TRUE);
	}
	return (FALSE);
}

int act_rrot(t_mystack *stack1, t_mystack *stack2)
{
	int temp;

	if (stack1 != NULL && stack1->curr >= 2)
	{
		temp = stack1->array[stack1->bottom_index];
		rem_bot(stack1);
		add_top(stack1, temp);
		if (stack2 != NULL && stack2->curr >= 2)
		{
			temp = stack2->array[stack2->bottom_index];
			rem_bot(stack2);
			add_top(stack2, temp);
			write(1, "rrr\n", 4);
			return (TRUE);
		}
		if (stack1->stack_name == 'a')
			write(1, "rra\n", 4);
		else if (stack1->stack_name == 'b')
			write(1, "rrb\n", 4);
		return (TRUE);
	}
	return (FALSE);
}
