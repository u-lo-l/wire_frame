/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:02:35 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/19 01:10:18 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_nbr
{
	unsigned long	nbr;
	int				is_minus;
	int				base;
	int				print_base_pre;
	int				is_digit_upper;
	char			sign_prefix[2];
	char			base_prefix[3];
}	t_number;
/*ft_printf.c*/
int		ft_printf_format(const char *str);
int		ft_printf(const char *str, ...);
/*ft_print_num.c*/
int		init_number(t_number *t_num, va_list ap, char conv);
void	init_base(t_number *t_num, char conv);
void	init_base_prefix(t_number *t_num, char conv);
int		ft_print_num(t_number t_num);
/*ft_print_word.c*/
int 	ft_print_char(va_list ap, char conv);
int 	ft_print_string(va_list ap);
/*ft_printf_utils.c*/
#endif
