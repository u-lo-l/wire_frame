/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:57:01 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/02 19:25:32 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *str)
{
	if (!str)
		return (-1);
	if (*str)
		return (gnl_strlen(str + 1) + 1);
	else
		return (0);
}

char	*gnl_stralloc(int strlen)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * (strlen + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i <= strlen)
		new_str[i++] = 0;
	return (new_str);
}

char	*gnl_strchr(char *str, char c)
{
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

char	*gnl_strndup(char *str, size_t n)
{
	size_t	i;
	char	*new_str;

	new_str = gnl_stralloc(n + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}
