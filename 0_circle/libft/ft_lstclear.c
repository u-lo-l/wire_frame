/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 03:18:30 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/29 14:02:03 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	if ((*lst)->next != NULL)
		ft_lstclear(&((*lst)->next), del);
	ft_lstdelone(*lst, del);
	(*lst) = NULL;
}
/*
#include <stdio.h>
void	showlst(t_list *lst)
{
	while(lst != NULL)
	{
		printf("[%s]->", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

void	ddd(void *str)
{
	if (!str)
		return ;
	return ;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	
	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		showlst(*lst);
		temp = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = temp;
	}
	(*lst) = NULL;
}

int main()
{
	void	(*del)(void *) = ddd;
	t_list	*l1 = ft_lstnew("ONE");
	t_list	*l2 = ft_lstnew("TWO");
	t_list	*l3 = ft_lstnew("THR");
	t_list	*l4 = ft_lstnew("FUR");
	t_list	*l5 = ft_lstnew("FVE");

	ft_lstadd_back(&l1, l2);
	ft_lstadd_back(&l1, l3);
	ft_lstadd_back(&l1, l4);
	ft_lstadd_back(&l1, l5);
	
	showlst(l1);
	printf("\nSTART\n\n");
	ft_lstclear(&l1, del);
	showlst(l1);
	printf("\nEND\n");
	return (0);
}
*/