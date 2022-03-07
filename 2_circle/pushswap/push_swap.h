#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "circularArray/circular_array.h"
# include "args/args.h"

enum e_order_type
{
	not_ordered,
	acsending,
	decsending
};

/*utils*/
int	my_strlen(char *str);
char	*my_strndup(char *str, int size);
int	my_atoi(char *str, int *errer_check);

/*main function*/
t_mystack	*init_stack_a(t_arglst *arglst);

void	push_swap(t_arglst *arglst);

/*sort*/
void	sort3(t_mystack *stack_a);
#endif
