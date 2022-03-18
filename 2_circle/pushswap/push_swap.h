/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 03:07:59 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/18 03:08:33 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "circularArray/circular_array.h"
# include "args/args.h"
# include <stdio.h>

typedef struct s_actions_number
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	total;
}		t_actions;

/*utils*/
int			my_min(int a, int b);
int			my_max(int a, int b);
int			my_strlen(char *str);
char		*my_strndup(char *str, int size);
int			my_atoi(char *str, int *errer_check);

/*main function*/
t_mystack	*init_stack_a(t_arglst *arglst);
void		push_swap(t_arglst *arglst);

/*sort*/
void		sort_mini(t_mystack *A);
void		sort_big(t_mystack *A, t_mystack *B);
/*prepara A and B before pb*/
void		case_rr(t_mystack *A, t_mystack *B, t_actions *acts);
void		case_rrr(t_mystack *A, t_mystack *B, t_actions *acts);
void		case_else(t_mystack *A, t_mystack *B, t_actions *acts);

/*count actions*/
void		count_ra(t_mystack *A, int index, t_actions *actions);
void		count_rb(t_mystack *B, int target, t_actions *actions);
void		count_a2b_actions(t_mystack *A, int index, t_mystack *B, \
							t_actions *temp);
int			count_b2a_actions(t_mystack *B);
void		get_least_actions(t_mystack *A,	t_mystack *B, t_actions *actions, \
							int big3[3]);

/*just for debug*/
void		printstack(t_mystack *stack);
void		show_arglst(t_arglst *lst);

#endif
