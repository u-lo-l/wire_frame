/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:49:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/01/22 16:49:26 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pft_init_number(t_format *f, va_list ap, char conv)
{
	long	temp;

	temp = 0;
	if (conv == 'd' || conv == 'i')
		temp = (long)va_arg(ap, int);
	else if (conv == 'u' || conv == 'x' || conv == 'X')
		temp = (long)va_arg(ap, unsigned int);
	else if (conv == 'p')
	{
		temp = (long)va_arg(ap, void *);
		f->precision = -1;
	}
	if (temp >= 0 || conv == 'p')
		f->nbr = (unsigned long)temp;
	else
	{
		f->nbr = (unsigned long)(-temp);
		f->is_minus = 1;
		ft_strlcpy(f->sign_prefix, "-", 2);
	}
}

void	pft_init_base(t_format *f, char conv)
{
	if (conv == 'p' || conv == 'x' || conv == 'X')
	{
		f->base = 16;
		if (conv == 'X')
		{
			ft_strlcpy(f->base_prefix, "0X", 3);
			f->is_digit_upper = 1;
		}
		else if (conv == 'x')
			ft_strlcpy(f->base_prefix, "0x", 3);
		else
		{
			ft_strlcpy(f->base_prefix, "0x", 3);
			f->print_base = 1;
		}
		if (f->nbr == 0 && conv != 'p')
			ft_strlcpy(f->base_prefix, "\0\0", 3);
	}
}

static int	pft_get_numsize(unsigned long nbr, int base)
{
	int	i;

	i = 1;
	while (nbr / base)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

char	*pft_numtostr(t_format *f)
{
	int				len;
	char			*numstr;

	if (f->blank == '0' && f->precision == -1 && f->width)
	{
		f->precision = f->width - ft_strlen(f->sign_prefix);
		f->width = 0;
	}
	if (f->nbr == 0 && f->precision == 0)
		len = 0;
	else
		len = ft_max(pft_get_numsize(f->nbr, f->base), f->precision);
	f->blank_size = ft_max(f->width - len, 0);
	numstr = ft_calloc(sizeof(char), len + 1);
	if (numstr == NULL)
		return (0);
	while (--len >= 0)
	{
		numstr[len] = "0123456789ABCDEF"[f->nbr % f->base];
		if (f->is_digit_upper == 0)
			numstr[len] = "0123456789abcdef"[f->nbr % f->base];
		f->nbr /= f->base;
	}
	return (numstr);
}

int	pft_print_num(t_format *f)
{
	int		ret_size;
	int		len;
	char	*numstr;

	if (f->blank == '0' && f->precision >= 0)
		f->blank = ' ';
	numstr = pft_numtostr(f);
	len = ft_strlen(numstr) + ft_strlen(f->sign_prefix);
	len += ft_strlen(f->base_prefix) * f->print_base;
	ret_size = len;
	f->blank_size = ft_max(f->width - len, 0);
	if (f->justify == RIGHT)
		ret_size += pft_fill_blank(f->blank, f->blank_size);
	ft_putstr(f->sign_prefix);
	if (f->print_base == 1)
		ft_putstr(f->base_prefix);
	ft_putstr(numstr);
	if (f->justify == LEFT)
		ret_size += pft_fill_blank(f->blank, f->blank_size);
	free(numstr);
	return (ret_size);
}
