/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:20:27 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/24 22:57:39 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const void *haystack, const void *needle, size_t len)
{
	size_t	h_idx;
	size_t	n_idx;

	h_idx = 0;
	while ((h_idx < len) && !((const char *)haystack)[h_idx])
	{
		n_idx = 0;
		while (((const char *)haystack)[h_idx] == ((const char *)needle)[n_idx])
		{
			n_idx++;
			if (!((const char *)needle)[n_idx])
				return ((char *)(haystack + h_idx));
		}
		h_idx++;
	}
	return (NULL);
}
