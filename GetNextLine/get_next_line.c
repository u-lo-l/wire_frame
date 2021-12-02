/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:56:54 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/02 20:43:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <limits.h>
#define READ_FAIL -1
#define LINEFEED '\n'

char	*get_next_line(int fd)
{
	int			read_status;
	char		buffer[BUFFER_SIZE];
	char		*curr_line;
	static char	*next_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	
}
