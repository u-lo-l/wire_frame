/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:02:25 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/23 16:08:37 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# define TRUE 1
# define FLASE 0
# include <stdio.h>
# include <sys/time.h>

/*UTILS*/
int		ft_strlen(char *str);
int		ft_numsize(long num, int radix);
void	ft_putpid(pid_t pid, int radix);
void	ft_putstr(char *str);
int		ft_atoi(char *str, int *err);

// void	put_char_bit(char c);
/*SERVER*/
void	receive_str_by_signal(int signo);
/*CLIENT*/
void	send_char_by_signal(pid_t server_pid, char c);
void	send_str_by_signal(pid_t server_pid, char *str);

#endif