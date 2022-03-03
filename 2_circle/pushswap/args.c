#include "push_swap.h"
#include <stdlib.h>

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

static void	delete_argset(char **set, int size)
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

// int	*save_arg_as_int(int size, char **pstr)
// {
// 	int		i;
// 	long	temp_num;
// 	int		*ret_array;

// 	ret_array = malloc(sizeof(int) * size);
// 	if (ret_array)
// 		return (NULL);
// 	if (!pstr)
// 		return (-1);
// 	i = 0;
// 	while (i < size)
// 	{

// 	}

// }