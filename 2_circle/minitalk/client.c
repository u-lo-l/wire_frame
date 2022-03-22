/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:05:58 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/23 02:05:59 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	server_pid;

	if (argc != 3)
		return (0);
	server_pid = ft_atoi(argv[1]);
	printf("arg pid : %d\n", server_pid);
	kill(server_pid, SIGKILL);
}
