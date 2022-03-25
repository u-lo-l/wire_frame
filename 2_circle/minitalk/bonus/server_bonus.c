/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 04:36:00 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/25 05:13:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	receive_client_pid(int signo, int *connected)
{
	static int	i;
	static int	client_pid;

	if (i > 31)
		client_pid = 0;
	if (i < 32)
	{
		client_pid <<= 1;
		if (signo == SIGUSR2)
			client_pid++;
		i++;
	}
	if (i > 31)
	{
		i = 0;
		usleep(TIME);
		if (kill(client_pid, SIGUSR1) == -1)
			exit(0);
		*connected = TRUE;
		return (client_pid);
	}
	return (0);
}

int	receive_string(int signo, int client_pid)
{
	static char	c;
	static int	i;

	if (i < 0 || i > 7)
	{
		i = 0;
		c = 0;
	}
	if (i < 8)
	{
		c <<= 1;
		if (signo == SIGUSR2)
			c++;
		i++;
	}
	usleep(TIME);
	if (kill(client_pid, SIGUSR1) == -1)
		exit(0);
	if (i == 8 && c)
		write(1, &c, 1);
	if (i == 8 && !c)
		return (TRUE);
	return (FALSE);
}

static void	signal_handler(int signo)
{
	static int	connected;
	static int	client_pid;

	if (connected == FALSE)
		client_pid = receive_client_pid(signo, &connected);
	else
	{
		if (receive_string(signo, client_pid) == TRUE)
		{
			connected = FALSE;
			client_pid = 0;
			write(1, "\n", 1);
		}
	}
}

int	main(void)
{
	ft_putpid(getpid(), 10);
	ft_putstr("\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
