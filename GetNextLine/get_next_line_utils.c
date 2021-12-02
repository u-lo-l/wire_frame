/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:57:01 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/02 18:24:55 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*gnl_strdup(char *str)
{
	int		size;
	char	*new_str;
	
	size = 0;
	while (str[size])
		size++;
	new_str = gnl_stralloc(size + 1);
	size = -1;
	while (str[++size])
		new_str[size] = str[size];
	return (new_str);
}
