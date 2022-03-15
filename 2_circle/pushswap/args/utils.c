/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:58:31 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/16 03:56:02 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	my_strlen(char *str)
{
	int	size;

	size = 0;
	if (!str)
		return (-1);
	while (str[size])
		size++;
	return (size);
}

char	*my_strndup(char *str, int size)
{
	int		i;
	int		len;
	char	*ret;

	len = my_strlen(str);
	if (len == -1)
		return (NULL);
	if (len < size)
		size = len;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < size)
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}

int	my_atoi(char *str, int *error_check)
{
	long	num;
	int		is_minus;

	is_minus = 0;
	num = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			is_minus = 1;
	if (*str == 0)
		*error_check = 1;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*(str++) - '0');
	if (*str != 0 || num > is_minus + 2147483647L)
		*error_check = 1;
	if (is_minus)
		num *= -1;
	return ((int)num);
}