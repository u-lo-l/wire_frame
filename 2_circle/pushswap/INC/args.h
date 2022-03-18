/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:07:16 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 02:42:57 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H
# define TRUE	1
# define FALSE	0
# define ERROR	-1

typedef struct s_arglst_node_type
{
	int							data;
	struct s_arglst_node_type	*next;
}								t_arglst_node;

typedef struct s_arglst_type
{
	unsigned int	lst_size;
	t_arglst_node	*head;
}					t_arglst;

/*arg_list*/
t_arglst		*new_arglst(void);
int				add_by_data(t_arglst *lst, int data);
int				find_data(t_arglst *lst, int key);
void			delete_arglst(t_arglst *lst);

/*arg_check*/
unsigned int	count_args(char *str);
void			delete_argset(char **argset, unsigned int size);
char			**split_args(int argc, char *str);
int				push_args_to_list(t_arglst *arglst, int argcnt, char **argset);
int				preprocess_args(t_arglst *arglst, int argc, char **argv);

#endif
