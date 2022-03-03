#ifndef PREPROCESS_H
# define PREPROCESS_H

typedef struct s_arg_node_type
{
	int						data;
	struct s_arg_node_type	*next;
}							t_arg_node;

typedef struct s_arg_lst_type;
{
	int			size;
	t_arg_node	*first
}				t_arg_lst;


int count_args(char *str);

char **split_args*(int argc, char *str);


#endif
