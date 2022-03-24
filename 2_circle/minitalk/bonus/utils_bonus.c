/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 02:02:58 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/24 21:33:22 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	ft_numsize(long num, int radix)
{
	int	size;

	size = 1;
	while (num / radix)
	{
		size++;
		num = num / radix;
	}
	return (size);
}

void	ft_putpid(pid_t pid, int radix)
{
	int		minus;
	int		size;
	char	*str;

	minus = 0;
	if (pid < 0)
	{
		minus = 1;
		pid = -pid;
	}
	size = ft_numsize(pid, radix);
	str = malloc(size + minus + 1);
	str[size + minus] = 0;
	while (--size >= 0)
	{
		str[size + minus] = pid % radix + '0';
		pid /= radix;
	}
	if (minus)
		str[0] = '-';
	ft_putstr(str);
	free(str);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}

int	ft_atoi(char *str, int *err)
{
	int		sign;
	long	nbr;

	sign = 1;
	nbr = 0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	if (*str != 0)
		*err = 1;
	if (sign == 1 && nbr >= 2147483647L)
		*err = 1;
	if (sign == -1 && nbr >= 2147483648L)
		*err = 1;
	return ((int)nbr * sign);
}
/*
void	put_char_bit(char c)
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
}*/