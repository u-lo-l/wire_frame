/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:18:06 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/02 22:18:07 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

void	delete_splited_charset(char **set, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(set[i++]);
	free(set);
}

int	count_words(char *str, char c)
{
	int		count;
	int		on_the_word;

	count = 0;
	on_the_word = 0;
	while (*str)
	{
		if (*str == c)
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

char	**ft_split(char *str, char c, int words)
{
	char	*start;
	char	**argset;
	int		i;

	i = -1;
	argset = malloc(sizeof(char *) * (words + 1));
	if (!argset)
		return (NULL);
	while (++i < words)
	{
		while (*str == c)
			str++;
		start = str;
		while (*str != c && *str != '\0')
			str++;
		argset[i] = ft_strndup(start, str - start);
		if (!argset[i])
		{
			delete_splited_charset(argset, i);
			return (NULL);
		}
	}
	argset[i] = NULL;
	return (argset);
}

int	ft_atoi_base(char *str, int radix, int *nbr)
{
	long	num;
	int		is_minus;

	is_minus = 0;
	num = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			is_minus = 1;
	if (*str == 0)
		return (FALSE);
	while (ft_strchr("0123456789abcdefABCDEF", *str))
	{
		if (*str >= '0' && *str <= '9')
			num = num * radix + (*(str++) - '0');
		else if (*str >= 'a' && *str <= 'f')
			num = num * radix + (*(str++) - 'a' + 10);
		else
			num = num * radix + (*(str++) - 'A' + 10);
	}
	if (*str != 0 || num > is_minus + 2147483647L)
		return (FALSE);
	if (is_minus)
		num *= -1;
	*nbr = num;
	return (TRUE);
}
