/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:57:01 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/10 20:33:21 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	if (!str)
		return (0);
	if (*str)
		return (gnl_strlen(str + 1) + 1);
	else
		return (0);
}

char	*gnl_strcalloc(int strlen)
{
	char	*new_str;
	int		i;

	if (strlen < 0)
		return (NULL);
	new_str = malloc(sizeof(char) * (strlen + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i <= strlen)
		new_str[i++] = 0;
	return (new_str);
}

char	*gnl_strrealloc(char *str, int size)
{
	char	*new;
	int		i;
	int		len;

	if (size < 0)
		return (NULL);
	len = gnl_strlen(str);
	if (size < len)
		len = size;
	new = gnl_strcalloc(size);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = str[i];
	free(str);
	return (new);
}

char	*gnl_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = gnl_strlen((char *)s);
	substr = gnl_strcalloc(len);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && start + i < size)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}