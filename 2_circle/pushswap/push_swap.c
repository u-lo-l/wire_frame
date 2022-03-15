#include "push_swap.h"

t_mystack	*init_stack_a(t_arglst *arglst)
{
	t_mystack		*stack_a;
	int				size;
	t_arglst_node	*curr;
	
	if (!arglst)
		return (NULL);
	size = arglst->lst_size;
	stack_a = new_stack(size);
	if (!stack_a)
	{
		delete_arglst(arglst);
		return (NULL);
	}
	stack_a->stack_name = 'a';
	curr = arglst->head->next;
	while (curr)
	{
		add_top(stack_a, curr->data);
		curr = curr->next;
	}
	delete_arglst(arglst);
	return (stack_a);
}

t_mystack	*init_stack_b(int size)
{
	t_mystack	*stack_b;

	stack_b = new_stack(size);
	if (!stack_b)
		return (NULL);
	stack_b->stack_name = 'b';
	return (stack_b);
}

void	push_swap(t_arglst *arglst)
{
	t_mystack *stack_a;
	t_mystack *stack_b;

	stack_a = init_stack_a(arglst);
	stack_b = init_stack_b(stack_a->max_size);
	printstack(stack_a);
	printstack(stack_b);
	if (!stack_a || !stack_b)
	{
		delete_stack(stack_a);
		delete_stack(stack_b);
		return ;	
	}
	if (is_ascending(stack_a) != TRUE)
	{
		if (stack_a->curr == 3)
			sort_mini(stack_a);
		else
			sort_big(stack_a, stack_b);
	}
	delete_stack(stack_a);
	delete_stack(stack_b);
}