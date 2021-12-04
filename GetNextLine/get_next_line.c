/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:56:54 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/04 20:49:09 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

char	*gnl_read(int fd, char *save_line)
{
	char	*buffer;
	int		read_status;

	buffer = gnl_strcalloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (gnl_strchr(save_line, '\n') == NULL)
	{
		read_status = read(fd, buffer, BUFFER_SIZE);
		if (read_status == -1)
			break ;
		save_line = gnl_strappend(save_line, buffer);
		if (save_line == NULL)
			break ;
	}
	free(buffer);
	return (save_line);
}

char	*get_next_line(int fd)
{
	int			read_status;
	char		*buffer;
	char		*curr_line;
	char		*temp;
	static char	*next_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = gnl_strcalloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read_status = read(fd, buffer, BUFFER_SIZE);
	next_line = gnl_strappend(next_line, buffer);
	free(buffer);
	temp = gnl_strchr(next_line, '\n');
	if (temp != NULL)
	{
		curr_line = gnl_substr(next_line, 0, temp + 1 - next_line);
		temp = gnl_substr(temp + 1, 0, gnl_strlen(temp + 1));
		free(next_line);
		next_line = temp;
		return (curr_line);
	}
	if (read_status == -1)
		return (next_line);
	return (get_next_line(fd));
}

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
		printf(">\n%s>\n", s);
		free(s);
	}
	close(fd);
}
