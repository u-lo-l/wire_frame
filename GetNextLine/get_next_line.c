/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:56:54 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/05 20:20:34 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	int			read_status;
	char		*buffer;
	char		*curr_line;
	static char	*next_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = gnl_strcalloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read_status = read(fd, buffer, BUFFER_SIZE);
	next_line = gnl_strappend(next_line, buffer);
	if (next_line== NULL)
		return (NULL);
	free(buffer);
	buffer = gnl_strchr(next_line, '\n');
	if (buffer != NULL)
	{
		curr_line = gnl_substr(next_line, 0, buffer + 1 - next_line);
		buffer = gnl_substr(buffer + 1, 0, gnl_strlen(buffer + 1));
		free(next_line);
		next_line = gnl_substr(buffer, 0, gnl_strlen(buffer));
		free(buffer);
		return (curr_line);
	}
	if (read_status < 1)
	{
		if (next_line)
			free(next_line);
		return (NULL);
	}
	return (get_next_line(fd));
}
/*
#include <fcntl.h>
int main()
{
	int fd = open("text", O_RDONLY);
	char	*s;
	int i = 0;
	while (i++ < 10)
	{
		s = get_next_line(fd);
		if (!s)
		{
			printf("(null)\n");
			break ;
		}
		printf(">\n%d | %s>\n", i, s);
		free(s);
	}
	close(fd);
}*/
