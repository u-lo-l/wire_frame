#include "push_swap.h"

void	count_ra(t_mystack *stack_a, int a_idx, t_actions *actions)
{
	actions->ra = convert_index(stack_a->top_index - a_idx, stack_a->max_size);
	actions->rra = (stack_a->curr - actions->ra) % stack_a->curr;
}

void	count_rb(t_mystack *stack_b, int target, t_actions *actions)
{
	int b_idx;
	int count;
	
	actions->rb = 0;
	count = -1;
	while (++count < stack_b->curr)
	{
		b_idx = convert_index(stack_b->top_index - count, stack_b->max_size);
		if (stack_b->array[b_idx] > target)
			actions->rb = count;
	}
	actions->rrb = (stack_b->curr - actions->rb) % stack_b->curr;
}

void	count_a2b_actions(t_mystack *stack_a, int a_idx ,t_mystack *stack_b,
						t_actions *temp)
{
	int	target;
	int	b_idx;

	target = stack_a->array[a_idx];
	count_ra(stack_a, a_idx, temp);
	count_rb(stack_b, target, temp);
}

int	get_least_actions(t_mystack *stack_a,	t_mystack *stack_b,
						t_actions *actions,	int big3[3])
{
	int					a_idx;
	t_actions	temp_actions;

	a_idx = stack_a->top_index;
	while (a_idx != stack_a->bottom_index)
	{
		if (stack_a->array[a_idx] != big3[0] && stack_a->array[a_idx] != big3[1] \
			&& stack_a->array[a_idx] != big3[2])
		{
			count_a2b_actions(stack_a, a_idx, stack_b, &temp_actions);
		}
		a_idx = convert_index(a_idx - 1, stack_a->max_size);
	}
}