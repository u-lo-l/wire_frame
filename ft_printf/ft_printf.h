/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 03:02:35 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/14 06:49:53 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
/*ft_printf.c*/
int		ft_printf_format(const char *str);
int		ft_printf(const char *str, ...);
/*ft_format_cspdi.c*/
int		ft_print_char(va_list ap);
int		ft_print_str(va_list ap);
int		ft_print_ptr(va_list ap);
int		ft_print_int(va_list ap);
/*ft_format_uxX%.c*/
int		ft_print_uint(va_list ap);
int		ft_print_hex_lower(va_list ap);
int		ft_print_hex_upper(va_list ap);
int		ft_print_percent(va_list ap);
/*ft_printf_utils.c*/
int 	ft_strlen(char *str);
int	 	ft_putstr(char *str);
int		get_numsize(unsigned int a);
char	*numtostr_base(long long nbr, unsigned int base);
#endif
