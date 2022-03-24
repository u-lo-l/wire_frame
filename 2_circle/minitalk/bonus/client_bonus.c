/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 04:35:58 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/25 05:10:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	receive_sig_from_server(int signo)
{
	if (signo == SIGUSR1)
		usleep(1);
}

void	send_client_pid_by_signal(pid_t server_pid, int client_pid)
{
	int	i;
	int	sigarr[2];

	if (client_pid <= 1)
		return ;
	sigarr[0] = SIGUSR1;
	sigarr[1] = SIGUSR2;
	i = 31;
	while (i >= 0)
	{
		if (kill(server_pid, sigarr[(client_pid >> i) & 0b1]) == -1)
			exit(0);
		usleep(TIME);
		i--;
	}
}

void	send_str_by_signal(pid_t server_pid, char *str)
{
	int	i;
	int	sigarr[2];

	sigarr[0] = SIGUSR1;
	sigarr[1] = SIGUSR2;
	if (!str)
		return ;
	while (1)
	{
		i = 6;
		while (i >= 0)
		{
			if (kill(server_pid, sigarr[(*str >> i) & 0b1]) == -1)
				exit(0);
			i--;
			pause();
		}
		if (!(*(str++)))
			break ;
	}
}

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	err;
	int	client_pid;

	if (argc != 3)
		return (-1);
	err = FALSE;
	server_pid = ft_atoi(argv[1], &err);
	client_pid = (int)getpid();
	usleep(TIME);
	signal(SIGUSR1, receive_sig_from_server);
	if (err == TRUE || server_pid <= 1)
		return (-1);
	send_client_pid_by_signal(server_pid, client_pid);
	pause();
	send_str_by_signal(server_pid, argv[2]);
}
