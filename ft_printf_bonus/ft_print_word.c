/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:49:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/01/22 13:40:31 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_char(va_list ap, char conv)
{
	unsigned char c;

	if (conv == '%')
		return (write(1, "%", 1));
	if (conv == 'c')
	{
		c = (unsigned int)va_arg(ap, int);
		return (write(1, &c, 1));
	}
	return (0);
}

int ft_print_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == 0)
		str = "(null)";
	return (ft_putstr(str));
}
