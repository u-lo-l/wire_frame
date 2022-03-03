#include "push_swap.h"





/*
 * main함수에서 처리할 것.
 * 1) 들어온 인자가 유효한가?
 * 
 */
typedef struct arg_list_node_type
{
	int							data;
	struct arg_list_node_type	*next;
}								arg_list_node;

typedef struct arg_vec_type
{
	int				curr_element_cout;
	arg_list_node	*p_head;
}					arg_list;

int	find_data(arg_list *list, int key)
{
	arg_list_node *curr;

	curr = list->header;
}
void add_to_list(arg_list *list, int data)
{
		
}

#include <stdio.h>
int main(int argc, char *argv[])
{
	char	*actions;
	int		count;
	int		i
	int		error_check;
	char	**temp
	
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		count = count_args(argv[i]);
		temp = my_split(count, argv[i]);:
	}
	// actions = push_swap(int argc, char **argv);
	return (0);
}
