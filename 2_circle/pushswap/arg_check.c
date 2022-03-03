/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:24:06 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/03 17:57:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "arg_list.h"
#include "arg_check.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	count_args(char *str)
{
	char	space;
	int		count;
	int		on_the_word;

	space = ' ';
	count = 0;
	on_the_word = 0;
	while (*str)
	{
		if (*str == space)
			on_the_word = 0;
		else
		{
			if (on_the_word == 0)
				count++;
			on_the_word = 1;
		}
		str++;
	}
	return (count);
}

void	delete_argset(char **set, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(set[i++]);
	free(set);
}

/* 마지막에 널보인터가 없는 이중배열을 반환한다.. 꼭 개수로 접근하자 */
char	**split_args(int argc, char *str)
{
	char	*start;
	char	**argset;
	int		i;

	i = -1;
	argset = malloc(sizeof(char *) * (argc));
	if (!argset)
		return (NULL);
	while (++i < argc)
	{
		while (*str == ' ')
			str++;
		if (*str == '\n')
			break ;
		start = str;
		while (*str != ' ' && *str != '\0')
			str++;
		argset[i] = my_strndup(start, str - start);
		if (!argset[i])
		{
			delete_argset(argset, i);
			return (NULL);
		}
	}
	return (argset);
}

static int	push_args_to_list(t_arglst *arglst, int argcnt, char **argset)
{
	int	i;
	int	err_check;
	int	num;

	err_check = 0;
	i = -1;
	while (++i < argcnt)
	{
		num = my_atoi(argset[i], &err_check);
		if (err_check == 1)
			delete_argset(argset, argcnt);
		else if (find_data(arglst, num) == TRUE)
			delete_argset(argset, argcnt);
		else if (add_by_data(arglst, num) == ERROR)
			delete_argset(argset, argcnt);
		else
			continue ;
		return (ERROR);
	}
	return (TRUE);
}

int	preprocess_args(t_arglst *arglst, int argc, char **argv)
{
	int		i;
	int		temp_argcnt;
	int		total_argcnt;
	char	**temp_argset;

	i = 0;
	total_argcnt = 0;
	while (++i < argc)
	{
		temp_argcnt = count_args(argv[i]);
		total_argcnt += temp_argcnt;
		temp_argset = split_args(temp_argcnt, argv[i]);
		if (temp_argset == NULL)
			return (ERROR);
		if (push_args_to_list(arglst, temp_argcnt, temp_argset) == ERROR)
			return (ERROR);
		delete_argset(temp_argset, temp_argcnt);
	}
	if (total_argcnt == 0)
		return (FALSE);
	return (TRUE);
}

/*
int main(int argc, char **argv)
{
	t_arglst *testlist;

	testlist = new_arglst();

	if (argc < 2)
	{
		printf("few args\n");
		return (0);
	}
	int res = preprocess_args(testlist, argc, argv);
	if (res == TRUE)
	{
		t_arglst_node *curr = testlist->head->next;
		while (curr != NULL)
		{
			printf("[%d] ", curr->data);
			curr = curr->next;
		}
		printf("\n");
	}
	else if (res == FALSE)
		printf("few args\n");
	else if (res == ERROR)
	{
		printf("err\n");
		delete_arglst(testlist);
		exit(1);
	}
	delete_arglst(testlist);
	return (0);
}
*/
