/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:33:33 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/29 16:04:58 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef unsigned char	t_uchar;

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (dest > src)
			((t_uchar *)dest)[n - i - 1] = ((const t_uchar *)src)[n - i - 1];
		else
			((t_uchar *)dest)[i] = ((const t_uchar *)src)[i];
		i++;
	}
	return (dest);
}
