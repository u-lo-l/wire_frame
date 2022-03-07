/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:53:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/07 23:21:36 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circularArray/circular_array.h"
#include "push_swap.h"

void	sort_3_case_1(t_mystack *stack_a)
{
	act_rrot(stack_a);
	act_swap(stack_a);
	write(1, "rra\n", 4);
	write(1, "sa\n", 3);
}

void	sort_3_case_2(t_mystack *stack_a)
{
	act_rot(stack_a);
	act_swap(stack_a);
	act_rot(stack_a);
	write(1, "ra\n", 3);
	write(1, "sa\n", 3);
	write(1, "ra\n", 3);
}
void	sort_3_case_3(t_mystack *stack_a)
{
	act_rot(stack_a);
	act_rot(stack_a);
	write(1, "ra\n", 3);
	write(1, "ra\n", 3);
}

void	sort_3_case_4(t_mystack *stack_a)
{
	act_swap(stack_a);
	act_rrot(stack_a);
	write(1, "sa\n", 3);
	write(1, "rra\n", 4);
}

void	sort3(t_mystack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top_index;
	second = stack_a->array[convert_index(first - 1, stack_a->max_size)];
	third = stack_a->array[convert_index(first - 2, stack_a->max_size)];
	first = stack_a->array[first];
	if (is_ascending(stack_a))
		return ;
	else if (first < second && first < third)
		sort_3_case_1(stack_a);
	else if (third > first && third > second)
		sort_3_case_2(stack_a);
	else if (second > first && second > third)
		sort_3_case_3(stack_a);
	else if (second > third)
		sort_3_case_4(stack_a);
	else
	{
		act_rrot(stack_a);
		act_rrot(stack_a);
		write(1, "rra\n", 4);
		write(1, "rra\n", 4);
	}
}
