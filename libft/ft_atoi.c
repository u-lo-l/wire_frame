/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:38:15 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/29 17:19:10 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned long	lnbr;

	sign = 1;
	lnbr = 0;
	while (ft_is_space(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		lnbr = lnbr * 10 + (*nptr - '0');
		nptr++;
	}
	if (sign == 1 && lnbr > (long)INT_MAX)
		return (-1);
	if (sign == -1 && lnbr > (long)INT_MAX + 1)
		return (0);
	return ((int)lnbr * sign);
}
