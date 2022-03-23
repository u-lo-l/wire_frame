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

void	receive_str_by_signal(int signo)
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
	{
		if (c)
			write(1, &c, 1);
		else
			write(1, "\n", 1);
	}
}

int	main(void)
{
	ft_putpid(getpid(), 10);
	ft_putstr("\n");
	signal(SIGUSR1, receive_str_by_signal);
	signal(SIGUSR2, receive_str_by_signal);
	while (1)
		pause();
}
