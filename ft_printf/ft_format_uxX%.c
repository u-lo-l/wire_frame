/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_uxX%.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 04:22:02 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/14 07:14:23 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(va_list ap)
{
	int				size;
	unsigned int	num;
	char			*numstr;
	
	num = va_arg(ap, unsigned int);
	numstr = numtostr_base(num, 10)
	size = ft_putstr(numstr);
	free(numstr);
	return (size);
}

int ft_print_hex_lower(va_list ap)
{
	int				size;
	unsigned int	num;
	char			*numstr;
	
	num = va_arg(ap, unsigned int);
	numstr = numtostr_base(num, 10)
	size = write(1, "0x", 2);
	size += ft_putstr(numstr); // tolower 있어야함.
	free(numstr);
	return (size);
}

int ft_print_hex_upper(va_list ap)
{
	int				size;
	unsigned int	num;
	char			*numstr;
	
	num = va_arg(ap, unsigned int);
	numstr = numtostr_base(num, 10)
	size = write(1, "0x", 2);
	size += ft_putstr(numstr);
	free(numstr);
	return (size);
}

int ft_print_percent(va_list ap)
{
	int	size;
	size = write(1, "%", 1);
	return (size);
}