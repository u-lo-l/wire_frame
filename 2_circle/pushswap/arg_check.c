/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:24:06 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/03 16:44:19 by dkim2            ###   ########.fr       */
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

/*complete :
	split strset to strs
	atoi str;

 */

int	preprocess_args(t_arglst *arglst, int argc, char **argv)
{
	int		i;
	int		j;
	int		num;
	int		error_check;
	int		temp_argcnt;
	char	**temp_argset;

	error_check = 0;
	i = 0;
	while (++i < argc)
	{
		temp_argcnt = count_args(argv[i]);
		temp_argset = split_args(temp_argcnt, argv[i]);
		j = -1;
		while (++j < temp_argcnt)
		{
			num = my_atoi(temp_argset[j], &error_check);
			if (error_check == 1)
			{
				delete_argset(temp_argset, temp_argcnt);
				return (ERROR);
			}
			if (find_data(arglst, num))
			{
				delete_argset(temp_argset, temp_argcnt);
				return (ERROR);
			}
			if (add_by_data(arglst, num) == -1)
			{
				delete_argset(temp_argset, temp_argcnt);
				return (ERROR);
			}
		}
		delete_argset(temp_argset, temp_argcnt);
	}
	return (TRUE);
}

int main(int argc, char **argv)
{
	t_arglst *testlist;

	testlist = new_arglst();

	if (argc < 2)
		return (0);
	if (preprocess_args(testlist, argc, argv) == TRUE)
	{
		t_arglst_node *curr = testlist->head->next;
		while (curr != NULL)
		{
			printf("[%d] ", curr->data);
			curr = curr->next;
		}
	}
	else
		printf("err");
	printf("\n");
	delete_arglst(testlist);
	return (0);
}

















