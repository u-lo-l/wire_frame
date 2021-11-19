/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:40:10 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/19 23:46:40 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascci(int c);

int		ft_isprintf(int c);

size_t	ft_strlen(const char *s);

void	*memset(void *s, int c, size_t n);

void	bzeor(void *s, size_t n);

void	*memcpy(void *dst, const void *src, size_t n);

void	*memmove(void *dst, const void *src, size_t n);

size_t	strlcpy(char *dst, const char *src, size_t n);

size_t	strlcat(char *dst, const char *src, size_t n);

#endif
