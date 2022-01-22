/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:49:07 by dkim2             #+#    #+#             */
/*   Updated: 2022/01/23 00:11:17 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_fill_blank(char c, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		write(1, &c, 1);
	return (n);
}

int	pf_print_char(t_format *f, va_list ap, char conv)
{
	unsigned char	c;
	int				size;

	size = 0;
	f->blank_size = ft_max(f->width - 1, 0);
	if (f->justify == RIGHT)
		size += pf_fill_blank(f->blank, f->blank_size);
	if (conv == '%')
		c = '%';
	if (conv == 'c')
		c = (unsigned char)va_arg(ap, int);
	size += write(1, &c, 1);
	if (f->justify == LEFT)
		size += pf_fill_blank(f->blank, f->blank_size);
	return (size);
}

int	pf_print_string(char *str, t_format *f)
{
	int		size;
	int		len;

	size = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (f->precision >= 0)
		len = ft_min(len, f->precision);
	f->blank_size = ft_max(f->width - len, 0);
	if (f->justify == RIGHT)
		size += pf_fill_blank(f->blank, f->blank_size);
	size += write(1, str, len);
	if (f->justify == LEFT)
		size += pf_fill_blank(f->blank, f->blank_size);
	return (size);
}
