/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:01:17 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/14 07:08:48 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int ft_print_format(char **str, va_list ap)
{
	int		size;
    char    cnv;
	// printf("%p\n", (*str));
	size = 0;
    cnv = **str;
    if (cnv == 'c')
        size = ft_print_char(ap);
    else if (cnv == 's')
        size = ft_print_str(ap);
    else if (cnv == 'p')
        size = ft_print_ptr(ap);
    else if (cnv == 'd' || cnv == 'i')
        size = ft_print_int(ap);
	else if (cnv == 'u')
        size = ft_print_uint(ap);
    else if (cnv == 'x')
        size = ft_print_hex_lower(ap);
    else if (cnv == 'X')
        size = ft_print_hex_upper(ap);
    else if (cnv == '%')
        size = ft_print_percent(ap);
	(*str) += 1;
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	int		size;
	char	*temp;
	char	**strptr;
	va_list ap;

	temp = (char *)str;
	va_start(ap, str);
	while (*temp)
	{
		// printf("LOOPS\n");
		// printf("I : %ld\n", temp - str);
		if (*temp == '%')
		{
			temp++;
			ret += ft_print_format(&temp, ap);
		}
		else
			ret += write(1, temp++, 1);
		// printf("==========================\n");
		// printf("I : %ld\n", temp - str);
		// printf("LOOPE\n");
	}
	va_end(ap);
	return (ret);
}

int main()
{
	ft_printf("%d\n%d\n%d\n%d\n%d\n%d\n", -1, -2, -3, -4, -5, -6);
}