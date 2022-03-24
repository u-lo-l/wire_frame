#include "minitalk_bonus.h"
#include <stdio.h>

int	g_sig_from_server;

void	receive_sig_from_server(int signo)
{
	if (signo == SIGUSR1)
	{
		// usleep(TIME);
		// write(1, "ACK ED\n", 7);
		g_sig_from_server = TRUE;
	}
}

void	wait_for_sig_from_server(void)
{
	int	i;

	i = 0;
	if (g_sig_from_server == TRUE)
		return ;
	// write(1, "WAITING ", 8);
	while (++i <= 10)
	{
		if (g_sig_from_server == TRUE)
			break ;
		// printf("count : %d\n", i);
		usleep(TIME);
	}
}

void	send_cpid_by_signal(pid_t server_pid, int client_pid)
{
	int	i;
	int	sigarr[2];
	int	pid_bit[31];

	if (client_pid <= 1)
		return ;
	sigarr[0] = SIGUSR1;
	sigarr[1] = SIGUSR2;
	i = 31;
	while (i >= 0)
	{
		if(kill(server_pid, sigarr[(client_pid >> i) & 0b1]) == -1)
			exit(0);
		usleep(100);
		i--;
	}
}

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
			wait_for_sig_from_server();
			if (g_sig_from_server == FALSE)
			{
				write(1, "fail\n", 5);
				exit(0);
			}
			// write(1,"READY TO SEND CHAR", 18);
			// for (int i = 3; i > 0 ; i--)
			// {
			// 	write(1, " O", 2);
			// 	usleep(TIME);
			// }
			// write(1, "\n", 1);
			if (kill(server_pid, sigarr[(c >> i) & 0b1]) == -1)
				exit(0);
			// write(1, "killed\n", 7);
			i--;
			g_sig_from_server = FALSE;
		}
	}
}

void	send_str_by_signal(pid_t server_pid, char *str)
{
	printf("sending str\n");
	if (!str)
		return ;
	while (1)
	{
		send_char_by_signal(server_pid, *str);
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

	signal(SIGUSR1, receive_sig_from_server);

	err = FALSE;
	g_sig_from_server = FALSE;
	server_pid = ft_atoi(argv[1], &err);
	client_pid = (int)getpid();
	printf("\nclient pid : %d\n", client_pid);
	if (err == TRUE || server_pid <= 1)
		return (-1);

	send_cpid_by_signal(server_pid, client_pid);
	printf("pid sent done\n");
	// if (g_sig_from_server)
	send_str_by_signal(server_pid, argv[2]);
	wait_for_sig_from_server();
	if (g_sig_from_server == FALSE)
	{
		write(1, "fail\n", 5);
		exit(0);
	}
	// else
		// printf("FAIL TO CONNECT\n");
		// write(1, "FAIL TO CONNECT\n", 16);
}
