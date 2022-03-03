/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:07:30 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/03 23:06:01 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include <stdlib.h>

t_arglst	*new_arglst(void)
{
	t_arglst	*lst;

	lst = malloc(sizeof(t_arglst));
	if (!lst)
		return (NULL);
	lst->lst_size = 0;
	lst->head = malloc(sizeof(t_arglst_node));
	if (lst->head == NULL)
	{
		free(lst);
		return (NULL);
	}
	lst->head->next = NULL;
	return (lst);
}

int	add_by_data(t_arglst *lst, int data)
{
	t_arglst_node	*new;

	if (!lst)
		return (ERROR);
	new = malloc(sizeof(t_arglst_node));
	if (!new)
		return (ERROR);
	new->data = data;
	new->next = lst->head->next;
	lst->head->next = new;
	lst->lst_size++;
	return (TRUE);
}

int	find_data(t_arglst *lst, int key)
{
	t_arglst_node	*curr;

	if (!lst)
		return (0);
	curr = lst->head->next;
	while (curr != 0)
	{
		if (curr->data == key)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

void	delete_arglst(t_arglst *lst)
{
	t_arglst_node	*target;
	t_arglst_node	*next;

	if (!lst)
		return ;
	target = lst->head;
	while (target != NULL)
	{
		next = target->next;
		free(target);
		target = next;
	}
	free(lst);
}
