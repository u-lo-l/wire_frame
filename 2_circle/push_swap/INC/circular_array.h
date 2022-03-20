/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 02:44:29 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 02:45:17 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_ARRAY_H
# define CIRCULAR_ARRAY_H
# define TRUE	1
# define FALSE	0
# define ERROR	-1
# include <stdlib.h>

typedef struct s_element_type
{
	int	data;
}		t_element;

typedef struct s_circular_array_type
{
	int		max_size;
	int		curr;
	int		top_idx;
	int		bot_idx;
	int		*array;
	char	stack_name;
}			t_mystack;

/*BASIC*/
t_mystack	*new_stack(int size);
void		delete_stack(t_mystack *stack);
int			convert_index(int idx, int max_size);
int			is_ascending(t_mystack *stack);

/*FUNCTIONS*/
int			add_top(t_mystack *stack, int num);
int			add_bot(t_mystack *stack, int num);
int			rem_top(t_mystack *stack);
int			rem_bot(t_mystack *stack);

/*ACTIONS*/
int			act_push(t_mystack *from, t_mystack *to);
int			act_swap(t_mystack *stack1, t_mystack *stack2);
int			act_rot(t_mystack *stack1, t_mystack *stack2);
int			act_rrot(t_mystack *stack1, t_mystack *stack2);
#endif
