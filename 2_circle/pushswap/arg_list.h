#ifndef ARG_LIST_H
# define ARG_LIST_H

typedef struct s_arglst_node_type
{
	int							data;
	struct s_arglst_node_type	*next;
}								t_arglst_node;

typedef struct s_arglst_type
{
	int				lst_size;
	t_arglst_node	*head;
}					t_arglst;


t_arglst	*new_arglst(void);

int	add_by_data(t_arglst *lst, int data);

int	rem_by_data(t_arglst *lst, int key);

int fine_data(t_arglst *lst, int key);

void delete_arglst(t_arglst *lst);

# endif"
