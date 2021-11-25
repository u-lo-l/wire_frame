/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:40:46 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/25 00:47:41 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_delimeter(char const *s, char c)
{
	int	i;
	int	is_delimeter;
	int	count;

	i = 0;
	is_delimeter = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			is_delimeter = 1;
		else
		{
			if (is_delimeter == 1)
				count++;
			is_delimeter = 0;
		}
		i++;
	}
	return (count);
}

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	size_t	size;
	char	*copy;

	size = ft_strlen(s1);
	if (size < n)
		n = size;
	copy = malloc(sizeof(char) * (n + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	int		set_idx;
	int		begin;
	int		end;
	int		count;
	char	**str_set;

	if (s == NULL)
		return (NULL);
	count = count_delimeter(s, c);
	str_set = malloc(sizeof(char *) * (count + 1));
	set_idx = 0;
	begin = 0;
	while (set_idx < count)
	{
		while (s[begin] == c && s[begin])
			begin++;
		end = begin + 1;
		while (s[end] != c && s[end])
			end++;
		str_set[set_idx] = ft_strndup(s + begin, end - begin);
		begin = end;
	}
	str_set[count] = NULL;
	return (str_set);
}
