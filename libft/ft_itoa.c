/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:26:52 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/25 01:02:28 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

int	get_size(unsigned int a)
{
	int	size;

	size = 1;
	a /= 10;
	while (a)
	{
		size++;
		a /= 10;
	}
	return (size);
}

char	*ft_itoa(int a)
{
	int		i;
	int		minus;
	int		size;
	char	*number;

	minus = 0;
	if (a == INT_MIN)
		return ("-2147483648");
	if (a < 0)
	{
		minus = 1;
		a = -a;
	}
	size = get_size(a);
	number = malloc(sizeof(char) * (minus + size + 1));
	i = 0;
	number[minus + size] = '\0';
	while (++i <= minus + size)
	{
		number[minus + size - i] = a % 10 + '0';
		a /= 10;
	}
	if (minus)
		number[0] = '-';
	return (number);
}
