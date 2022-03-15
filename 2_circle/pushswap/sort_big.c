#include "push_swap.h"

static void	set_big_three(t_mystack *stack, int big3[3])
{
	int	i;

	i = stack->top_index;
	while (i != stack->bottom_index)
	{
		if (big3[0] < stack->array[i])
			big3[0] = stack->array[i];
		i = convert_index(i - 1, stack->max_size);
	}
	i = stack->top_index;
	while (i != stack->bottom_index)
	{
		if ((big3[1] < stack->array[i]) && (stack->array[i] < big3[0]))
			big3[1] = stack->array[i];
		i = convert_index(i - 1, stack->max_size);
	}
	i = stack->top_index;
	while (i != stack->bottom_index)
	{
		if (big3[2] < stack->array[i] && stack->array[i] < big3[1])
			big3[2] = stack->array[i];
		i = convert_index(i - 1, stack->max_size);
	}
}

int	sort_big(t_mystack *stack_a, t_mystack *stack_b)
{
	t_actions	actions;
	int			big_three[3];

	big_three[0] = -2147483648;
	big_three[1] = -2147483648;
	big_three[2] = -2147483648;
	set_big_three(stack_a, big_three);
	actions.total = 2147483647;
	printf("%d, %d, %d\n", big_three[0], big_three[1], big_three[2]);
}
