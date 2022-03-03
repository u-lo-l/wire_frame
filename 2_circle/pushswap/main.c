#include "push_swap.h"
#include "circularArray/circular_array.h"
#include "args/args.h"
#include <stdio.h>

static void show_arglst(t_arglst *lst)
{	t_arglst_node *curr = lst->head->next;
	while (curr)
	{
		printf("->(%d)",curr->data);
		curr = curr->next;
	}
	printf("\n");
}


int main(int argc, char *argv[])
{
	int preprocess_res;
	t_arglst *arglst;

	arglst = new_arglst();
	preprocess_res = preprocess_args(arglst, argc, argv);
	if(preprocess_res == ERROR)
	{
		delete_arglst(arglst);
		write(2, "Error\n", 6);
		exit(1);
	}
	else if(preprocess_res == TRUE)
	{
		push_swap(arglst);
	}
	else
		delete_arglst(arglst);
	return (0);
}
