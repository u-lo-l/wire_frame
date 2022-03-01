/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:57:26 by dkim2             #+#    #+#             */
/*   Updated: 2022/02/28 22:29:56 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque_node	*make_new_node(int data)
{
	t_deque_node	*new_node;

	new_node = malloc(sizeof(t_deque_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->pnext_node = NULL;
	new_node->pprev_node = NULL;
	return (new_node);
}

void	delete_node(t_deque_node **node)
{
	if (!*node|| !node)
		return ;
	free(*node);
	*node = NULL;
}

t_deque	*make_empty_deque(void)
{
	t_deque			*new_deque;
	t_deque_node	*header_node;

	new_deque = malloc(sizeof(t_deque));
	new_deque->curr_node_count = 0;
	if (!new_deque)
		return (NULL);
	header_node = make_new_node(0);
	if (!header_node)
	{
		free(new_deque);
		return (NULL);
	}
	header_node->pnext_node = header_node;
	header_node->pprev_node = header_node;
	new_deque->header_node = header_node;
	return (new_deque);
}

void			delete_deque(t_deque **deque)
{
	t_deque_node *curr;

	if (!*deque || !deque)
		return ;
	while (!is_deque_empty(*deque))
	{
		curr = dequeue_front(*deque);
		delete_node(&curr);
	}
	free((*deque)->header_node);
	free(*deque);
	*deque = NULL;
}


int	is_deque_empty(t_deque *deque)
{
	if (deque->header_node->pnext_node == deque->header_node)
		return (1);
	return (0);
}

int	enqueue_front(t_deque *deque, int data)
{
	t_deque_node *new_node;

	new_node = make_new_node(data);
	if (!new_node)
		return (0);
	new_node->pnext_node = deque->header_node->pnext_node;
	new_node->pprev_node = deque->header_node;
	new_node->pnext_node->pprev_node = new_node;
	deque->header_node->pnext_node = new_node;
	deque->curr_node_count++;
	return (1);
}

t_deque_node	*dequeue_front(t_deque *deque)
{
	t_deque_node *del_node;

	if (is_deque_empty(deque))
		return (NULL);
	del_node = deque->header_node->pnext_node;
	deque->header_node->pnext_node = del_node->pnext_node;
	del_node->pnext_node->pprev_node = deque->header_node;
	del_node->pnext_node = NULL;
	del_node->pprev_node = NULL;
	deque->curr_node_count--;
	return (del_node);
}

int	enqueue_rear(t_deque *deque, int data)
{
	t_deque_node *new_node;
	
	new_node = make_new_node(data);
	if (!new_node)
		return (0);
	new_node->pprev_node = deque->header_node->pprev_node;
	new_node->pnext_node = deque->header_node;
	new_node->pprev_node->pnext_node = new_node;
	deque->header_node->pprev_node = new_node;
	deque->curr_node_count++;
	return (1);
}

t_deque_node	*dequeue_rear(t_deque *deque)
{
	t_deque_node *del_node;

	if (is_deque_empty(deque))
		return (0);
	del_node = deque->header_node->pprev_node;
	deque->header_node->pprev_node = del_node->pprev_node;
	del_node->pprev_node->pnext_node = deque->header_node;
	del_node->pnext_node = NULL;
	del_node->pprev_node = NULL;
	deque->curr_node_count--;
	return (del_node);
}

void	print_deque(t_deque *deque)
{
	int 			i;
	t_deque_node	*node;
	if (!deque)
		return ;
	i = 0;
	node = deque->header_node->pnext_node;
	if (is_deque_empty(deque))
	{
		printf("EMPTY\n");
		return ;
	}
	while (i < deque->curr_node_count)
	{
		printf("[%- 5d]->", node->data);
		node = node->pnext_node;
		i++;
	}
	printf("END\n");
	return ;
}