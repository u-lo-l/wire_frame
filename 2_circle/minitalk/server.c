/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:02:11 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/23 16:08:33 by dkim2            ###   ########.fr       */
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
void	receive_char_by_signal(int signo)
{
	static char	c;
	static int	i;
		
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
		write(1, &c, 1);
}

int	main(void)
{
	struct timeval	now;
	unsigned long	start = 0, end;
	ft_putpid(getpid(), 10);
	ft_putstr("\n");
	signal(SIGUSR1, receive_char_by_signal);
	signal(SIGUSR2, receive_char_by_signal);
	while (1)
	{
		gettimeofday(&now, NULL);
		end = (uint64_t)now.tv_sec * 1000000 + (uint64_t)now.tv_usec;
		printf("receive() time : %ld\n", end - start);
		pause();
		printf("receiving\n");
		gettimeofday(&now, NULL);
		start = (uint64_t)now.tv_sec * 1000000 + (uint64_t)now.tv_usec;
	}
}
