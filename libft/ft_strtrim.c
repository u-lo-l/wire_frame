/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:11:00 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/26 22:46:39 by dkim2            ###   ########.fr       */
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
	if (!set)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	begin = 0;
	while (ft_strchr(set, s1[begin]) != NULL)
		begin++;
	end = 0;
	while (ft_strchr(set, s1[s1_len - end - 1]) && end + 1 < s1_len)
		end++;
	if (begin >= s1_len - end - 1)
		return (ft_strdup(""));
	trimed_str = malloc(sizeof(char) * (s1_len - begin - end + 1));
	if (trimed_str == NULL)
		return (NULL);
	ft_strlcpy(trimed_str, (s1 + begin), s1_len - begin - end + 1);
	return (trimed_str);
}
