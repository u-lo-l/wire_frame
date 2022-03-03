#include "push_swap.h"
#include "arg_list.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	int preprocess_res;
	t_list *arglst;

	arglst = new_arglst();
	preprocess_res = preprocess_args(arglst, argc, argv);
	else if(preprocess_res == ERROR)
	{
		delete_arglst(alglst);
		write(2, "Error\n", 6);
		exit(1);
	}
	else if(preprocess_res == TRUE)
	{
		//push swap process here
	}
	else
		delete_arglst(arglst);
	return (0);
}
