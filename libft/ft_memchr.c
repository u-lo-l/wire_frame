/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 02:21:24 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/11 03:42:57 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    *memchr(const void *s, int c, unsigned int n)
{
    unsigned int    i;
    char            *temp;

    temp = s;
    i = 0;
    while (i < n && temp[i] != 0)
    {
        if (c == temp[i])
            return (temp + i);
        i++;
    }
    return (NULL);
}