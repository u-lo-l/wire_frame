/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:48:08 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 03:11:50 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/push_swap.h"

void	count_ra(t_mystack *A, int a_idx, t_actions *acts)
{
	acts->ra = convert_index(A->top_idx - a_idx, A->max_size);
	if (A->curr == 0)
		acts->rra = 0;
	else
		acts->rra = (A->curr - acts->ra) % A->curr;
}

void	count_rb(t_mystack *B, int target, t_actions *acts)
{
	int	b_idx;
	int	prev;

	acts->rb = 0;
	acts->rrb = 0;
	if (!B->curr)
		return ;
	if (target < B->array[B->top_idx])
		search_b_forward(B, target, acts);
	else if (target > B->array[B->top_idx])
		search_b_backward(B, target, acts);
}

void	count_a2b_actions(t_mystack *A, int a_idx, t_mystack *B,
						t_actions *temp)
{
	int	count_rr;
	int	count_rrr;
	int	count_else;

	count_ra(A, a_idx, temp);
	count_rb(B, A->array[a_idx], temp);
	count_rr = my_max(temp->ra, temp->rb);
	count_rrr = my_max(temp->rra, temp->rrb);
	count_else = my_min(temp->ra, temp->rra) + my_min(temp->rb, temp->rrb);
	temp->total = my_min(count_rr, count_rrr);
	temp->total = my_min(count_else, temp->total);
}

int	count_b2a_actions(t_mystack *B)
{
	int	b_idx;
	int	prev;
	int	rb;

	prev = 2147483647;
	rb = 0;
	while (rb < B->curr)
	{
		b_idx = convert_index(B->top_idx - rb, B->max_size);
		if (prev < B->array[b_idx])
			break ;
		prev = B->array[b_idx];
		rb++;
	}
	return (rb);
}
