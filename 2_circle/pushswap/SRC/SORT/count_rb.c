#include "../../INC/push_swap.h"

void	search_b_forward(t_mystack *B, int target, t_actions *acts)
{
	int	prev;
	int	b_idx;

	b_idx = convert_index(B->top_idx, B->max_size);
		prev = 2147483647;
		while (target < B->array[b_idx] && prev >= B->array[b_idx])
		{
			prev = B->array[b_idx];
			acts->rb++;
			if (b_idx == B->bot_idx)
				break ;
			b_idx = convert_index(b_idx - 1, B->max_size);
		}
		acts->rrb = (B->curr - acts->rb) % B->curr;
}

void	search_b_backward(t_mystack *B, int target, t_actions *acts)
{
	int	prev;
	int	b_idx;
	
	b_idx = convert_index(B->bot_idx, B->max_size);
	prev = -2147483648;
	while (target > B->array[b_idx] && prev <= B->array[b_idx])
	{
		prev = B->array[b_idx];
		acts->rrb++;
		if (b_idx == B->top_idx)
			break ;
		b_idx = convert_index(b_idx + 1, B->max_size);
	}
	acts->rb = (B->curr - acts->rrb) % B->curr;
}