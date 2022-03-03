/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:07:16 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/03 16:20:43 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_LIST_H
# define ARG_LIST_H
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
	int				lst_size;
	t_arglst_node	*head;
}					t_arglst;

t_arglst	*new_arglst(void);

int			add_by_data(t_arglst *lst, int data);

int			find_data(t_arglst *lst, int key);

void		delete_arglst(t_arglst *lst);

#endif
