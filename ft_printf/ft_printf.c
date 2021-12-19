/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:01:17 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/19 21:50:57 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void show_info(t_format f)
{
	printf("\n*********************\n");
	printf("nbr : %lu\nbase : %d\nprint base : %d\nupper : %d\n", f.nbr, f.base, f.print_base, f.is_digit_upper);
	printf("sign_p : [%s]\nbase_p : [%s]\npadding : [%c]\n", f.sign_prefix, f.base_prefix, f.padding);
	printf("width : %d\nprecision : %d\npadsize : %d\njustify : %d\n", f.width, f.precision, f.padding_size, f.justify);
	printf("*********************\n");
}

int	ft_print_format(char **str, va_list ap)
{
	t_format	format_info;
	int			size;

	size = 0;
	ft_init_format(&format_info);
	ft_get_flags(str, &format_info);
	format_info.width = ft_get_count(str);
	if (**str == '.')
	{
		(*str)++;
		format_info.precision = ft_get_count(str);
	}
	format_info.padding_size = ft_max(format_info.width, format_info.precision);
	size = ft_get_conversion(str, &format_info, ap);
	(*str)++;
	// show_info(format_info);
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
			ret += ft_print_format(&temp, ap);
		}
		else
			ret += write(1, temp++, 1);
	}
	va_end(ap);
	return (ret);
}
