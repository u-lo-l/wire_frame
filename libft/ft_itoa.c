/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:26:52 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/29 22:51:58 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
	char			*number;
	unsigned int	u_a;
	int				size;
	int				minus;

	minus = 0;
	if (a < 0)
		minus = 1;
	u_a = a * ((1 - minus) * (1) + ((minus) * (-1)));
	size = get_size(u_a);
	number = malloc(sizeof(char) * (minus + size + 1));
	if (!number)
		return (NULL);
	number[minus + size] = 0;
	while (--size >= 0)
	{
		number[minus + size] = u_a % 10 + '0';
		u_a /= 10;
	}
	if (minus)
		number[0] = '-';
	return (number);
}
