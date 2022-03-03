#include "circular_array.h"

int add_top(t_mystack *stack, int num)
{
	if (!stack)
		return (ERROR);
	if (stack->curr_element_count == stack->max_size)
		return (FALSE);
	stack->top_index++;
	stack->top_indexs %= stack->max_size;
	stack->array[stack->top_index] = num;
	stack->curr_element_count++;
	return (TRUE);
}

int add_bot(t_mystack *stack, int num)
{
	if (!stack)
		return (ERROR);
	if (stack->curr_element_count == stack->max_size)
		return (FALSE);
	stack->bottom_index--;
	stack->bottom_index %= stack->max_size;
	stack->array[stack->bottom_index] = num;
	stack->curr_element_count++;
	return (TRUE);
}

int rem_top(t_mystack *stack, int num)
{
	if (!stack)
		return (ERROR);
	if (stack->curr_element_count == 0)
		return (FALSE);
	stack->top_index--;
	stack->top_index %= stack->max_size;
	stack->curr_element_count--;
}

int rem_bot(t_mystack *stack, int num)
{
	if (!stack)
		return (ERROR);
	if (stack->curr_element_count == 0)
		return (FALSE);
	stack->bottom_index++;
	stack->bottom_index %= stack->max_size;
	stack->curr_element_count--;
}