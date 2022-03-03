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
	while (TURE)
	{
		if (curr == bot_i)
			return (TRUE);
		next = convert_index(curr - 1);
		if (stack->array[curr] > stack->array[next])
			return (FALSE);
		curr = convert_index(--curr);
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
	while (TURE)
	{
		if (curr == bot_i)
			return (TRUE);
		next = convert_index(curr - 1);
		if (stack->array[curr] < stack->array[next])
			return (FALSE);
		curr = convert_index(--curr);
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
		curr = convert_index(--curr);
	}
	return (TRUE);
}

int	get_fst_pivot(t_mystack *stack)
{
	int total_size;
	int curr;
	int bot_i
	int ret;
	int count;

	total_size = stack->curr_element_count;
	curr = stack->top_index;
	bot_i = stack->bottom_index;
	count = 0;
	ret = stack->array[curr];
	while (count < total_size / 3)
	{
		if ()
		curr = convert_index(--curr);
	}
}

int	get_snd_pivot(t_mystack *stack);