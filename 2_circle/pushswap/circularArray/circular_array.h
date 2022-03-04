#ifndef CIRCULAR_ARRAY_H
# define CIRCULAR_ARRAY_H
# include <stdlib.h>

# define TRUE	1
# define FALSE	0
# define ERROR	-1

typedef struct s_element_type
{
	int data;
}	t_element;

typedef struct s_circular_array_type
{
	int max_size;
	int curr_element_count;
	int top_index;
	int bottom_index;
	int	*array;
}				t_mystack;

/*BASIC*/
t_mystack	*new_stack(int size);

void	delete_stack(t_mystack *stack);

int	convert_index(int idx, int max_size);

/*FUNCTIONS*/
int add_top(t_mystack *stack, int num);

int add_bot(t_mystack *stack, int num);

int rem_top(t_mystack *stack);

int rem_bot(t_mystack *stack);

/*check*/
int is_ascending(t_mystack *stack);

int is_descending(t_mystack *stack);

int not_duplicated(t_mystack *stack, int key);

/*ACTIONS*/
void act_push(t_mystack *from, t_mystack *to);

void act_sawp(t_mystack *stack);

void act_rot(t_mystack *stack);

void act_rrot(t_mystack *stack);
#endif
