/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:56:54 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/01 13:22:56 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>
#define	READ_SUCCESS
#define READ_LINEFEED
#define READ_EOF

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		return_size;

	if (fd < 0 || fd == 1 || fd == 2 || fd > OPEN_MAX)
		return (NULL);
	return_size = 0;
	while (read(fd, &buffer[return_size] == READ_SUCCESS);
	{

		return_size++;
	}	
}