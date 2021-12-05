/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:56:54 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/05 22:37:54 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

char	*gnl_strappend(char *front, char *end)
{
	int		f_size;
	int		e_size;
	int		i;

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

char	*get_next_line(int fd)
{
	int			read_status;
	char		*buffer;
	char		*curr_line;
	static char	*next_line;

	curr_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
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
		next_line = gnl_substr(buffer, 0, gnl_strlen(buffer));
		free(buffer);
		return (curr_line);
	}
	else if (read_status < 1)
	{
		if (gnl_strlen(next_line))
			curr_line = gnl_substr(next_line, 0, gnl_strlen(next_line));
		free(next_line);
		next_line = NULL;	
		return (curr_line);
	}
	return (get_next_line(fd));
}
/*====================================*/
/*
void	ppp(char *str)
{
	if (str)
		printf("%s",str);
	else
		printf("null\n");
}

#include <fcntl.h>
int main()
{
	int fd = open("text", O_RDONLY);
	char	*s;
	// while ((s = get_next_line(fd)))
	// {
	// 	printf("%s", s);
	// 	free(s);
	// }
	int i = 0;
	while (++i < 10)
	{
		s = get_next_line(fd);
		if (s)
			printf("==========\n%s==========\n",s);
		else
			printf("null\n");
		printf("POINTER : %p\n\n", s);
		if (s)
			free(s);
	}
	close(fd);
}*/
