#include "push_swap.h"

/*THIS PART IS JUST FOR DEBUG*/
#include <stdio.h>
static void	printstack(t_mystack *stack)
{
	int i;
	int count;
	int bot;
	int max;

	i = stack->top_index;
	count = 1;
	bot = stack->bottom_index;
	max = stack->max_size;
	printf("\033[1;33m>>> STACK <<<\n");
	printf("  MAX : %d\n", stack->max_size);
	printf(" CURR : %d\n", stack->curr);
	printf(" DATA : ");
	while (1)
	{
		printf("[% 4d]", stack->array[i]);
		if (i == bot)
			break;
		if (count % 15 == 0)
			printf("\n        ");
		i = convert_index(i - 1, max);
		count++;
	}
	printf("\n\033[0m");
}

static void show_arglst(t_arglst *lst)
{	t_arglst_node *curr = lst->head->next;
	while (curr)
	{
		printf("->(%d)",curr->data);
		curr = curr->next;
	}
	printf("\n");
}

char *order_arr[3] = {"not ordered","acsending","decsending"};
/*===========================*/

t_mystack	*init_stack_a(t_arglst *arglst)
{
	t_mystack		*stack_a;
	int				size;
	t_arglst_node	*curr;
	
	if (!arglst)
		return (NULL);
	// show_arglst(arglst);
	size = arglst->lst_size;
	stack_a = new_stack(size);
	if (!stack_a)
		return (NULL);
	curr = arglst->head->next;
	while (curr)
	{
		add_top(stack_a, curr->data);
		curr = curr->next;
	}
	printstack(stack_a);
	delete_arglst(arglst);
	return (stack_a);
}

void	push_swap(t_arglst *arglst)
{
	int ordered_dir;
	t_mystack *stack_a;

	// show_arglst(arglst);
	stack_a = init_stack_a(arglst);
	ordered_dir = is_ascending(stack_a);
	if (!ordered_dir)
		ordered_dir = is_descending(stack_a);
	printf("%s \n", order_arr[ordered_dir]);
	if (stack_a->curr == 3)
		sort3(stack_a);
	printstack(stack_a);
	delete_stack(stack_a);
}