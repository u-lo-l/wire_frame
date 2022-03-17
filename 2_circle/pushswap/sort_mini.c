#include "push_swap.h"

void sort_two(t_mystack *stack)
{
	int first;
	int second;

	if (stack->curr != 2)
		return ;
	first = stack->array[stack->top_idx];
	second = stack->array[stack->bot_idx];
	if (first > second)
		act_swap(stack, NULL);
}

static void sort_three_case2(t_mystack *stack)
{
	act_rrot(stack, NULL);
	act_swap(stack, NULL);
}

static void sort_three_case5(t_mystack *stack)
{
	act_swap(stack, NULL);
	act_rrot(stack, NULL);
}

void sort_mini(t_mystack *stack)
{
	int first;
	int second;
	int third;

	if (stack->curr == 2)
		sort_two(stack);
	if (stack->curr != 3 || is_ascending(stack))
		return ;
	first = stack->top_idx;
	second = stack->array[convert_index(first - 1, stack->max_size)];
	third = stack->array[convert_index(first - 2, stack->max_size)];
	first = stack->array[first];
	if (first < second && first < third)
		sort_three_case2(stack);
	else if (third > first && third > second)
		act_swap(stack, NULL);
	else if (second > first && second > third)
		act_rrot(stack, NULL);
	else if (second > third)
		sort_three_case5(stack);
	else
		act_rot(stack, NULL);
}