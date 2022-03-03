#include "push_swap.h"
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
#include <stdio.h>

int	my_atoi(char *str, int *error_check)
{
	long 	num;
	int		is_minus;
	is_minus = 0;
	num	= 0; 
	if (*str == '-')
	{
		is_minus = 1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + (*str - '0');
		else
		{
			*error_check = 1;
			break;
		}
		if (num > is_minus + 2147483647)
		{
			*error_check = 1;
			break;
		}
		str++;
	}
	if (is_minus)
		num *= -1;
	return ((int)num);
}
