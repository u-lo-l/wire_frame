/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:33:33 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/19 22:59:17 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
typedef unsigned char uchar_t;

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    
    i = 0;
    while (i < n)
    {
        if (dest > src)
            ((uchar_t *)dest)[n - i + 1] = ((uchar_t *)src)[n - i + 1];
        else
            ((uchar_t *)dest)[i] = ((uchar_t *)src)[i];
        i++;
    }
    return (dest);
}