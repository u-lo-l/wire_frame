/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:50:27 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/23 21:51:14 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# define TRUE 1
# define FLASE 0

/*UTILS*/
int		ft_strlen(char *str);
int		ft_numsize(long num, int radix);
void	ft_putpid(pid_t pid, int radix);
void	ft_putstr(char *str);
int		ft_atoi(char *str, int *err);

// void	put_char_bit(char c);
/*SERVER*/
/*CLIENT*/

#endif