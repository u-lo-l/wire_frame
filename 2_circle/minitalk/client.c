/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:05:58 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/24 21:10:21 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char_by_signal(pid_t server_pid, char c)
{
	int	i;
	int	sigarr[2];

	sigarr[0] = SIGUSR1;
	sigarr[1] = SIGUSR2;
	i = 6;
	if (0 <= c || c <= 127)
	{
		while (i >= 0)
		{
			kill(server_pid, sigarr[(c >> i) & 0b1]);
			usleep(100);
			i--;
		}
	}
}

void	send_str_by_signal(pid_t server_pid, char *str)
{
	if (!str)
		return ;
	while (1)
	{
		send_char_by_signal(server_pid, *str);
		if (!(*str))
			break ;
		str++;
	}
}

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	err;

	err = FLASE;
	if (argc != 3)
		return (-1);
	server_pid = ft_atoi(argv[1], &err);
	if (err == TRUE || server_pid <= 1)
		return (-1);
	send_str_by_signal(server_pid, argv[2]);
}
