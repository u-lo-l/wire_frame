/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:01:17 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/19 01:08:48 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_print_format(char *s, va_list ap)
{
	t_number	t_num;
	int			size;

	size = 0;
	if (*s == 'd' || *s == 'i' || *s == 'u' || *s == 'x' || *s == 'X' || *s == 'p')
	{
		if (init_number(&t_num, ap, *s) == 0 && *s == 'p')
			return (ft_putstr("(nil)"));
		init_base(&t_num, *s);
		init_base_prefix(&t_num, *s);
		size = ft_print_num(t_num);
	}
	else if (*s == 'c' || *s == '%')
		size = ft_print_char(ap, *s);
	else if (*s == 's')
		size = ft_print_string(ap);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	char	*temp;
	va_list	ap;

	ret = 0;
	va_start(ap, str);
	temp = (char *)str;
	while (*temp)
	{
		if (*temp == '%')
		{
			temp++;
			ret += ft_print_format(temp, ap);
		}
		else
			ret += write(1, temp, 1);
		temp++;
	}
	va_end(ap);
	return (ret);
}

// int main()
// {   
// 	int a = 1234;
// 	char c = 'C';
// 	ft_printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", c, "abc def", &a, -a, a, a, a, a);
// 	printf("=====================\n");
// 	printf("%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", c, "abc def", &a, -a, a, a, a, a);
// 	// ft_printf("%p\n", &a);
// }