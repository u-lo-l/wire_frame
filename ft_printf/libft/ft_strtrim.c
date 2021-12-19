/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:11:00 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/07 18:55:13 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	size_t	s1_len;
	char	*trimed_str;

	if (!s1)
		return (NULL);
	if (!set || !(*set))
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	begin = 0;
	while (begin < s1_len && ft_strchr(set, s1[begin]) != NULL)
		begin++;
	end = 0;
	while (end < s1_len && ft_strchr(set, s1[s1_len - end - 1]) != NULL)
		end++;
	if (s1_len < begin + end + 1)
		return (ft_strdup(""));
	trimed_str = ft_substr(s1, begin, s1_len - begin - end);
	if (trimed_str == NULL)
		return (NULL);
	return (trimed_str);
}
