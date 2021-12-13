/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 04:26:44 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/14 06:48:42 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int ft_putstr(char *str)
{
	if (str == NULL)
		return (0);
	return (write(1, str, ft_strlen(str)));
}

int	get_numsize(unsigned int a)
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

char	*numtostr_base(long long nbr, unsigned int base)
{
	int				len;
	int				negative;
	char			*numstr;

	if (base < 2 || base > 16)
		return (NULL);
	negative = 0;
	if (nbr < 0)
		negative = 1;
	nbr = nbr * (negative * (-1) + (1 - negative));
	len = get_numsize(nbr);
	numstr = malloc(sizeof(char) * (negative + len + 1));
	numstr[negative + len] = 0;
	while (--len >= 0)
	{
		numstr[negative + len] = "0123456789ABCDE"[nbr % base];
		nbr /= base;
	}
	if (negative)
		numstr[0] = '-';
	return (numstr);
}
