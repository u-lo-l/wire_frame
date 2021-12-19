/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:56:55 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/19 20:05:35 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_format(t_format *f)
{
	if (f == NULL)
		return ;
	f->nbr = 0;
	f->is_minus = 0;
	f->base = 10;
	f->print_base = 0;
	f->is_digit_upper = 0;
	ft_strlcpy(f->sign_prefix, "\0", 2);
	ft_strlcpy(f->base_prefix, "\0\0", 3);
	f->padding = ' ';
	f->width = 0;
	f->precision = -1;
	f->padding_size = 0;
	f->justify = RIGHT;
}

void	ft_get_flags(char **str, t_format *f)
{
	while (**str)
	{
		if (**str == '#')
			f->print_base = 1;
		else if (**str == ' ')
		{
			if (ft_strncmp(f->sign_prefix, "+", 2))
				ft_strlcpy(f->sign_prefix, " ", 2);
		}
		else if (**str == '0')
			f->padding = '0';
		else if (**str == '-')
		{
			f->justify = LEFT;
			f->padding = ' ';
		}
		else if (**str == '+')
			ft_strlcpy(f->sign_prefix, "+", 2);
		else
			break ;
		(*str)++;
	}
}

int	ft_get_count(char **str)
{
	int	count;

	count = 0;
	while (ft_isdigit(**str))
	{
		count = count * 10 + (**str) - '0';
		(*str)++;
	}
	return (count);
}

int	ft_get_conversion(char **s, t_format *f, va_list ap)
{
	int	size;

	size = 0;
	if (**s == 'd' || **s == 'i' || **s == 'u'
		|| **s == 'x' || **s == 'X' || **s == 'p')
	{
		if (init_number(f, ap, **s) == 0 && **s == 'p')
			return (ft_putstr("(nil)"));
		init_base(f, **s);
		init_base_prefix(f, **s);
		size = ft_print_num(f);
	}
	else if (**s == 'c' || **s == '%')
		size = ft_print_char(f, ap, **s);
	else if (**s == 's')
		size = ft_print_string(f, ap);
	else
		return (-1);
	return (size);
}
