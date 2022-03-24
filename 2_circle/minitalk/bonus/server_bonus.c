#include "minitalk_bonus.h"
#include <stdio.h>

int	receive_client_pid(int signo, int *connected)
{
	static int	i;
	static int	client_pid;

	// printf("client Pid func | i : %d\n", i);
	if (i > 31)
		client_pid = 0;
	if (i < 32)
	{
		client_pid <<= 1;
		if (signo == SIGUSR2)
			client_pid++;
		// printf("cpid: %d\n", client_pid);
		i++;
	}
	if (i > 31)
	{
		i = 0;
		if (kill(client_pid, SIGUSR1) == -1)
			exit(0);
		// printf("\n\n\nclient PID : %d\n", client_pid);
		*connected = TRUE;
		// usleep(TIME);
		return (client_pid);
	}
	return (0);
}

int	receive_string(int signo, int client_pid ,int *connected)
{
	static char	c;
	static char	i;
	
	if (client_pid == 0)
	{
		write(1, "client pid == 0\n", 16);
		exit(0);
	}
	// printf("\tstring func | i : %d\n", i);
	if (i < 0 || i > 6)
	{
		i = 0;
		c = 0;
	}
	if (0 <= i && i < 7)
	{
		c <<= 1;
		if (signo == SIGUSR2)
			c++;
		i++;
	}
	if (i == 7)
	{
		if (c)
			write(1, &c, 1);
		else
		{
			*connected = FALSE;
			write(1, "\n", 1);
		}
	}
	// write(1," SIG RECEIVED\n", 14);
	// write(1,"READY TO ACK", 12);
	// for (int i = 3; i > 0 ; i--)
	// {
	// 	write(1, " O", 2);
	// 	usleep(TIME);
	// }
	// write(1, "\n", 1);
	if (kill(client_pid, SIGUSR1) == -1)
		exit(0);
	if (connected == FALSE)
		return (TRUE);
	return (FALSE);
}

void	signal_handler(int signo)
{
	static int	connected;
	static int	client_pid;
	static int	string_received;

	// printf("\033[0;32mSIGNAL STATE ");
	// printf("connected : %d ", connected);
	// printf("client_pid : %d\n\033[0m", client_pid);

	if (connected  == FALSE)
		client_pid = receive_client_pid(signo, &connected);
	else
	{
		if (receive_string(signo, client_pid, &connected) == TRUE)
			client_pid = 0;
	}
}

int main(void)
{
	ft_putpid(getpid(), 10);
	ft_putstr("\n");
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}