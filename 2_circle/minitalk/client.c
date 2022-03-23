/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:05:58 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/23 14:35:24 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	put_char_bit(char c)
{
	int i = 0;
	char bit[7];

	while (i <= 6)
		bit[i++] = '0';
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
			bit[6 - i] = '1';
		else
			bit[6 - i] = '0';			
		i--;
	}
	write(1, bit, 7);
	write(1, "\n", 1);
}

void	send_char_by_signal(pid_t server_pid, char c)
{
	struct timeval	now;
	unsigned long	start, end;
	int	i;
	int	sigarr[2];
	sigarr[0] = SIGUSR1;
	sigarr[1] = SIGUSR2;
	i = 6;
	if (0 <= c || c <= 127)
	{
		while (i >= 0)
		{
			gettimeofday(&now, NULL);
			start = (uint64_t)now.tv_sec * 1000000 + (uint64_t)now.tv_usec;
			kill(server_pid, sigarr[(c >> i) & 0b1]);
			gettimeofday(&now, NULL);
			usleep(10);
			end = (uint64_t)now.tv_sec * 1000000 + (uint64_t)now.tv_usec;
			printf("kill() time : %ld\n", end - start);
			i--;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	err;

	err = 0;
	if (argc != 3)
		return (-1);
	server_pid = ft_atoi(argv[1], &err);
	if (err == TRUE || server_pid <= 1)
		return (-1);
	send_char_by_signal(server_pid, argv[2][0]);
}
