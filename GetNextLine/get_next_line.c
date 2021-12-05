/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:56:54 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/05 13:13:23 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

/*gnl_read(int fd , char *save_line)						*/
/*															*/
/*if there is '\n' in saved_line, returns saved_line.		*/
/*if there isn't, read file and append string to saved_line.*/
/*check if there is '\n' in saved_line again.				*/
/*															*/
/*[return NULL case] :										*/
/*1. fail to alloc buffer									*/
/*2. save_line == "" when read() ended						*/
/*3. fail to append buffer to save_line						*/
/*
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
		if (read_status < 1)
			break ;
		save_line = gnl_strappend(save_line, buffer);
		if (save_line == NULL)
			break ;
	}
	free(buffer);
	if (gnl_strlen(save_line) == 0)
	{
		free(save_line);
		return (NULL);
	}
	return (save_line);
}

char	*get_next_line(int fd)
{
	char		*curr_line;
	char		*linefeed;
	static char	*next_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	curr_line = NULL;
	next_line = gnl_read(fd, next_line);
	if (next_line == NULL)
		return (NULL);
	linefeed = gnl_strchr(next_line, '\n');
	if (linefeed != NULL)
	{
		curr_line = gnl_substr(next_line, 0, linefeed - next_line + 1);
		next_line = gnl_substr(next_line, linefeed - next_line + 1, gnl_strlen(linefeed + 1));
	}
	else
	{	
		curr_line = gnl_substr(next_line, 0, gnl_strlen(next_line));
		free(next_line);
		next_line = NULL;
	}
	return (curr_line);
}
*/
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
	free(buffer);
	buffer = gnl_strchr(next_line, '\n');
	if (buffer != NULL)
	{
		curr_line = gnl_substr(next_line, 0, buffer + 1 - next_line);
		buffer = gnl_substr(buffer + 1, 0, gnl_strlen(buffer + 1));
		free(next_line);
		next_line = buffer;
		free(buffer);
		return (curr_line);
	}
	if (read_status < 1)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
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
}
*/
