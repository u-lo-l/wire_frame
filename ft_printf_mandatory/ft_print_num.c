/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.conv                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:49:10 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/15 15:53:20 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_number(t_number *t_num, va_list ap, char conv)
{
	long	temp;

	if (conv == 'd' || conv == 'i')
		temp = (long)va_arg(ap, int);
	else if (conv == 'u' || conv == 'x'|| conv  == 'X')
		temp = (long)va_arg(ap, unsigned int);
	else if (conv == 'p')
		temp = (long)va_arg(ap, void *);
	else
		return ;
	if (temp >= 0)
	{
		t_num->nbr = (unsigned long)temp;
		t_num->is_minus = 0;
		ft_strlcpy(t_num->sign_prefix, "\0", 2);
	}
	else
	{
		t_num->nbr = (unsigned long)(-temp);
		t_num->is_minus = 1;
		ft_strlcpy(t_num->sign_prefix, "-", 2);
	}
}

void	init_base(t_number *t_num, char conv)
{
	if (conv == 'd' || conv == 'i' || conv == 'u')
	{
		t_num->base = 10;
		t_num->is_digit_upper = 0;
	}
	else if (conv == 'p' || conv == 'x'|| conv  == 'X')
	{
		t_num->base = 16;
		if (conv == 'X')
			t_num->is_digit_upper = 1;
		else
			t_num->print_base_pre = 0;
	}
}

void	init_base_prefix(t_number *t_num, char conv)
{
	t_num->print_base_pre = 0;
	if (conv == 'd' || conv == 'i' || conv == 'u')
		ft_strlcpy(t_num->base_prefix, "\0\0", 3);
	else if (conv == 'p' || conv == 'x')
	{
		ft_strlcpy(t_num->base_prefix, "0x", 3);
		if (conv == 'p')
			t_num->print_base_pre = 1;
	}
	else if (conv == 'X')
		ft_strlcpy(t_num->base_prefix, "0X", 3);
}

static int ft_count_digits(unsigned long number, int base)
{
	int	count;

	count = 1;
	while (number / base)
	{
		count++;
		number /= base;
	}
	return (count);
}

int	ft_print_num(t_number t_num)
{
	int		i;
	int		len;
	int		size;
	char	*numstr;

	len = ft_count_digits(t_num.nbr, t_num.base);
	size = len;
	numstr = ft_calloc(sizeof(char), len + 1);
	if (numstr == NULL)
		return (0);
	size += ft_putstr(t_num.sign_prefix);
	if (t_num.print_base_pre == 1)
		size += ft_putstr(t_num.base_prefix);
	i = 1;
	while (i <= len)
	{
		if (t_num.is_digit_upper == 0)
			numstr[len - i] = "0123456789abcdef"[t_num.nbr % t_num.base];
		else if (t_num.is_digit_upper == 1)
			numstr[len - i] = "0123456789ABCDEF"[t_num.nbr % t_num.base];
		t_num.nbr /= t_num.base;
		i++;
	}
	ft_putstr(numstr);
	free(numstr);
	return (size);
}