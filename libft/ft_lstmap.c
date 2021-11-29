/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 03:27:16 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/29 22:59:18 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (lst->next != NULL)
	{
		temp = ft_lstmap(lst->next, f, del);
		if (temp == NULL)
		{
			free(new);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
	}
	return (new);
}
/*
#include <stdio.h>
static int	ft_isupper(char c)
{
	if (c >= 'A' || c <= 'Z')
		return (1);
	return (0);
}
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
	free(str);
	return ;
}

void	*fff(void *str)
{
	char	*newstr = ft_strdup(str);
	int		i = 0;
	while (newstr[i])
	{
		if (ft_isupper(newstr[i]))
			newstr[i] += 32;
		i++;	
	}
	return ((void *)newstr);
}
int main()
{
	void	*(*f)(void *) = fff;
	void	(*del)(void *) = ddd;
	t_list	*l1 = ft_lstnew("ONE");
	t_list	*l2 = ft_lstnew("TWO");
	t_list	*l3 = ft_lstnew("THR");
	t_list	*l4 = ft_lstnew("FUR");
	t_list	*l5 = ft_lstnew("FVE");
	t_list	*new;

	ft_lstadd_back(&l1, l2);
	ft_lstadd_back(&l1, l3);
	ft_lstadd_back(&l1, l4);
	ft_lstadd_back(&l1, l5);
	
	showlst(l1);
	printf("\nSTART\n\n");
	new = ft_lstmap(l1, f, del);
	showlst(new);
	printf("\nEND\n");

	ft_lstclear(&new, del);
	showlst(new);
	return (0);
}*/