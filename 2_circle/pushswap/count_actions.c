#include "push_swap.h"

void	count_ra(t_mystack *A, int a_idx, t_actions *actions)
{
	actions->ra = 0;
	actions->ra = convert_index(A->top_idx - a_idx, A->max_size);
	if (A->curr == 0)
		actions->rra = 0;
	else
		actions->rra = (A->curr - actions->ra) % A->curr;
}

void	count_rb(t_mystack *B, int target, t_actions *actions)
{
	int	b_idx;
	int	prev;

	actions->rb = 0;
	actions->rrb = 0;
	if (!B->curr)
		return ;
	if (target < B->array[B->top_idx])
	{
		b_idx = convert_index(B->top_idx, B->max_size);
		prev = 2147483647;
		while (target < B->array[b_idx] && prev >= B->array[b_idx])
		{
			prev = B->array[b_idx];
			actions->rb++;
			if (b_idx == B->bot_idx)
				break;
			b_idx = convert_index(b_idx - 1, B->max_size);
		}
		actions->rrb = (B->curr - actions->rb) % B->curr;
	}
	else if(target > B->array[B->top_idx])
	{
		b_idx = convert_index(B->bot_idx, B->max_size);
		prev = -2147483648;
		while (target > B->array[b_idx] && prev <= B->array[b_idx])
		{
			prev = B->array[b_idx];
			actions->rrb++;
			if (b_idx == B->top_idx)
				break;
			b_idx = convert_index(b_idx + 1, B->max_size);
		}
		actions->rb = (B->curr - actions->rrb) % B->curr;
	}
}

void	count_a2b_actions(t_mystack *A, int a_idx, t_mystack *B,
						t_actions *temp)
{
	int count_rr;
	int count_rrr;
	int count_else;
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
	int rb;

	prev = 2147483647;
	rb = 0;
	while (rb < B->curr)
	{
		b_idx = convert_index(B->top_idx - rb, B->max_size);
		if (prev < B->array[b_idx])
			break;
		prev = B->array[b_idx];
		rb++;
	}
	return (rb);
}

int	get_least_actions(t_mystack *A,	t_mystack *B,
						t_actions *actions,	int big3[3])
{
	int			a_idx;
	t_actions	temp_actions;

	a_idx = A->top_idx;
	while (TRUE)
	{
		if (A->array[a_idx] != big3[0] \
			&& A->array[a_idx] != big3[1] \
			&& A->array[a_idx] != big3[2])
		{
			count_a2b_actions(A, a_idx, B, &temp_actions);
			if (actions->total > temp_actions.total)
				(*actions) = temp_actions;
		}
		if (a_idx == A->bot_idx)
			break;
		a_idx = convert_index(a_idx - 1, A->max_size);
	}
}
