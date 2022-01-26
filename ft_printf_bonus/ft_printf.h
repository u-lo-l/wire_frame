/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:02:35 by dkim2             #+#    #+#             */
/*   Updated: 2022/01/26 14:37:13 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"
# define RIGHT 0
# define LEFT 1

typedef struct s_format
{
	unsigned long	nbr;
	int				is_minus;
	int				base;
	int				print_base;
	int				is_digit_upper;
	char			sign_prefix[2];
	char			base_prefix[3];
	char			blank;
	int				width;
	int				precision;
	int				blank_size;
	int				justify;

}	t_format;
/*ft_format.c*/
void	pf_init_format(t_format *format_info);

void	pf_get_flags(char **str, t_format *format_info);

int		pf_get_count(char **str);

int		pf_get_conversion(char **str, t_format *format_info, va_list ap);
/*ft_printf.c*/
int		pf_printf_format(const char *str);

int		ft_printf(const char *str, ...);
/*ft_printf_num.c*/
void	pf_init_number(t_format *t_num, va_list ap, char conv);

void	pf_init_base(t_format *t_num, char conv);

int		pf_print_num(t_format *t_num);
/*ft_print_word.c*/
int		pf_fill_blank(char c, int n);

int		pf_print_char(t_format *format_info, va_list ap, char conv);

int		pf_print_string(char *str, t_format *format_info);

#endif
