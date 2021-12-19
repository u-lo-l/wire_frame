/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:49:07 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/19 22:30:20 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_padding(char c, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		write(1, &c, 1);
	return (n);
}

int	ft_print_char(t_format *f, va_list ap, char conv)
{
	unsigned char	c;
	int				size;

	size = 0;
	f->padding_size = ft_max(f->padding_size - 1, 0);
	if (f->justify == RIGHT)
		size += ft_put_padding(f->padding, f->padding_size);
	if (conv == '%')
		c = '%';
	if (conv == 'c')
		c = (unsigned char)va_arg(ap, int);
	size += write(1, &c, 1);
	if (f->justify == LEFT)
		size += ft_put_padding(f->padding, f->padding_size);
	return (size);
}

int	ft_print_string(t_format *f, va_list ap)
{
	char	*str;
	int		size;
	int		len;

	size = 0;
	str = va_arg(ap, char *);
	if (str == 0)
		str = "(null)";
	len = ft_strlen(str);
	f->padding_size = ft_max(f->padding_size - len, 0);
	if (f->justify == RIGHT && f->precision < 0)
		size += ft_put_padding(f->padding, f->padding_size);
	if (f->precision >= 0)
	{
		int i = 0;
		while (i < ft_min(f->precision, len))
			size += write(1, &str[i++], 1);
	}
	else
	{
		size += ft_putstr(str);
		if (f->justify == LEFT)
			size += ft_put_padding(f->padding, f->padding_size);
	}
	return (size);
}
