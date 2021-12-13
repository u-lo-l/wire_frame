/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_cspdi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 04:00:40 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/14 07:15:38 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list ap)
{
	int		size;
	char	c;

	c = (char)va_arg(ap, int);
	size = write(1, &c, 1);
	return (size);
}

int ft_print_str(va_list ap)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int ft_print_ptr(va_list ap)
{
	int			size;
	long long	ptr;

	ptr = (long long)va_arg(ap, void *);
	size = write(1, "0x", 2);
	size += ft_putstr(numtostr_base(ptr, 16));
	return (size);
}

int ft_print_int(va_list ap)
{
	int		size;
	int 	num;
	char	*numstr;
	
	num = va_arg(ap, unsigned int);
	numstr = numtostr_base(num, 10)
	size = ft_putstr(numstr);
	free(numstr);
	return (size);
}