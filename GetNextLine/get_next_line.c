/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:56:54 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/03 06:01:16 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>
#define READ_FAIL -1

char	*get_next_line(int fd)
{
	int			read_status;
	char		buffer;
	char		*curr_line;
	char		*temp;
	static char	*next_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	curr_line = NULL;
	buffer = gnl_strcalloc(BUFFER_SIZE);
	if (read(fd, buffer, BUFFER_SIZE) == READ_FAIL)
		return (NULL);
	temp = gnl_strcat(next_line, buffer)
}
