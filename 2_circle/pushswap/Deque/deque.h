/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:49:51 by dkim2             #+#    #+#             */
/*   Updated: 2022/02/28 22:23:01 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

#include <stdlib.h>
#include <stdio.h>
typedef struct s_deque_node_type
{
	int							data;
	struct s_deque_node_type	*pnext_node;
	struct s_deque_node_type	*pprev_node;
}								t_deque_node;

typedef struct s_deque_type
{
	int				curr_node_count;
	t_deque_node	*header_node;
}					t_deque;

t_deque_node	*make_new_node(int value);

void			delete_node(t_deque_node **node);

t_deque			*make_empty_deque(void);

void			delete_deque(t_deque **queue);

int				is_deque_empty(t_deque *deque);

int				enqueue_front(t_deque *deque, int data);

t_deque_node	*dequeue_front(t_deque *deque);

int				enqueue_rear(t_deque *deque, int data);

t_deque_node	*dequeue_rear(t_deque *deque);

void			print_deque(t_deque *deque);

#endif
