/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:49:10 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/19 22:55:32 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	init_number(t_format *f, va_list ap, char conv)
{
	long	temp;

	if (conv == 'd' || conv == 'i')
		temp = (long)va_arg(ap, int);
	else if (conv == 'u' || conv == 'x' || conv == 'X')
		temp = (long)va_arg(ap, unsigned int);
	else if (conv == 'p')
		temp = (long)va_arg(ap, void *);
	if (temp >= 0 || conv == 'p')
		f->nbr = (unsigned long)temp;
	else
	{
		f->nbr = (unsigned long)(-temp);
		f->is_minus = 1;
		ft_strlcpy(f->sign_prefix, "-", 2);
	}
	return (f->nbr != 0);
}

void	init_base(t_format *f, char conv)
{
	if (conv == 'd' || conv == 'i' || conv == 'u')
	{
		f->base = 10;
		f->is_digit_upper = 0;
	}
	else if (conv == 'p' || conv == 'x' || conv == 'X')
	{
		f->base = 16;
		if (conv == 'X')
			f->is_digit_upper = 1;
		else
			f->is_digit_upper = 0;
	}
}

void	init_base_prefix(t_format *f, char conv)
{
	if (conv == 'p' || conv == 'x')
	{
		ft_strlcpy(f->base_prefix, "0x", 3);
		if (conv == 'p')
			f->print_base = 1;
	}
	else if (conv == 'X')
		ft_strlcpy(f->base_prefix, "0X", 3);
	if (f->nbr == 0 && (conv == 'x' || conv == 'X'))
		ft_strlcpy(f->base_prefix, "\0\0", 3);
}

char	*ft_numtostr(t_format f)
{
	int				len;
	char			*numstr;
	unsigned long	temp;

	temp = f.nbr;
	len = 1;
	while (temp / f.base)
	{
		len++;
		temp /= f.base;
	}
	len = ft_max(len, f.precision);
	numstr = ft_calloc(sizeof(char), len + 1);
	if (numstr == NULL)
		return (0);
	while (--len >= 0)
	{
		if (f.is_digit_upper == 0)
			numstr[len] = "0123456789abcdef"[f.nbr % f.base];
		else if (f.is_digit_upper == 1)
			numstr[len] = "0123456789ABCDEF"[f.nbr % f.base];
		f.nbr /= f.base;
	}
	return (numstr);
}

int	ft_print_num(t_format *f)
{
	int		ret_size;
	int		whole_len;
	char	*numstr;

	numstr = ft_numtostr(*f);
	ret_size = ft_strlen(numstr);
	whole_len = ret_size + ft_strlen(f->sign_prefix);
	whole_len += ft_strlen(f->base_prefix) * f->print_base;
	f->padding_size = ft_max(f->padding_size - whole_len, 0);
	ret_size += ft_putstr(f->sign_prefix);
	if (f->justify == RIGHT)
		ret_size += ft_put_padding(f->padding, f->padding_size);
	if (f->print_base == 1)
		ret_size += ft_putstr(f->base_prefix);
	ft_putstr(numstr);
	if (f->justify == LEFT)
		ret_size += ft_put_padding(f->padding, f->padding_size);
	free(numstr);
	return (ret_size);
}
