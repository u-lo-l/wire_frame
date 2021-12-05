/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:56:54 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/06 02:04:46 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>

char	*gnl_strappend(char *front, char *end)
{
	int		f_size;
	int		e_size;
	int		i;

	if (!front && !end)
		return (NULL);
	f_size = gnl_strlen(front);
	e_size = gnl_strlen(end);
	front = gnl_strrealloc(front, f_size + e_size);
	if (!front)
		return (NULL);
	i = -1;
	while (++i < e_size)
		front[f_size + i] = end[i];
	return (front);
}

char	*temp_f(char **next_line);
{
	int			read_status;
	char		*temp;
	char		*curr_line;
	
	curr_line = NULL;
	temp = gnl_strcalloc(BUFFER_SIZE);
	if (!temp)
		return (NULL);
	read_status = read(fd, temp, BUFFER_SIZE);
	*next_line = gnl_strappend(*next_line, temp);
	free(temp);
	temp = gnl_strchr(*next_line, '\n');
	if (temp != NULL)
	{
		curr_line = gnl_substr(*next_line, 0, temp + 1 - *next_line);
		temp = gnl_substr(temp + 1, 0, gnl_strlen(temp + 1));
		free(*next_line);
		next_line = gnl_substr(temp, 0, gnl_strlen(temp));
		free(temp);
	}
	else if (read_status < 1)
	{
		if (gnl_strlen(next_line))
			curr_line = gnl_substr(*next_line, 0, gnl_strlen(*next_line));
		free(*next_line);
		next_line = NULL;
	}
	return (curr_line);
}

char	*get_next_line(int fd)
{
	char		*curr_line;
	static char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	curr_line = temp_f(&next_line);
	if (curr_line)
		return (curr_line);
	else
		return (get_next_line(fd));
}