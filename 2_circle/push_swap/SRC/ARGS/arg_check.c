/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:24:06 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/03 22:29:48 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INC/args.h"
#include "../../INC/push_swap.h"

unsigned int	count_args(char *str)
{
	char				space;
	unsigned int		count;
	int					on_the_word;

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

void	delete_argset(char **set, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		free(set[i++]);
	free(set);
}

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

int	push_args_to_list(t_arglst *arglst, int argcnt, char **argset)
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
	int					i;
	unsigned int		temp_argcnt;
	unsigned int		total_argcnt;
	char				**temp_argset;

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
