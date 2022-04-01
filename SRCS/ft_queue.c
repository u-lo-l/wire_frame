/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:36:02 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/01 18:27:33 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"
#include <stdlib.h>

t_queue	*ft_create_queque(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->pfront = NULL;
	queue->prear = NULL;
	queue->queue_size = 0;
	return (queue);
}

int	ft_enqueue(t_queue	*queue, t_ivec2	z_and_color)
{
	t_qnode	*new;

	if (!queue)
		return (FALSE);
	new = malloc(sizeof(t_qnode) * 1);
	if (!new)
		return (FALSE);
	new->data[0] = z_and_color[0];
	new->data[1] = z_and_color[1];
	if (is_queue_empty(queue))
	{
		queue->pfront = new;
		queue->prear = new;
	}
	else
	{
		queue->prear->next = new;
		queue->prear = new;
	}
	queue->queue_size++;
	return (TRUE);
}

t_qnode	*ft_dequeue(t_queue *queue)
{
	t_qnode	*p_return;

	if (!queue)
		return (NULL);
	if (is_queue_empty(queue))
		return (NULL);
	p_return = queue->pfront;
	if (queue->queue_size == 1)
	{
		queue->pfront = NULL;
		queue->prear = NULL;
	}
	else
	{
		queue->pfront = queue->pfront->next;
		p_return->next = NULL;
	}
	queue->queue_size--;
	return (p_return);
}

void	ft_delete_queue(t_queue *queue)
{
	t_qnode	*curr;
	t_qnode	*next;

	if (!queue)
		return ;
	curr = queue->pfront;
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free (queue);
	queue = NULL;
}

int	is_queue_empty(t_queue *queue)
{
	if (!queue)
		return (FALSE);
	if (queue->pfront == NULL && queue->prear == NULL)
		return (TRUE);
	return (FALSE);
}
