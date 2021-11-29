/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:20:27 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/29 16:53:43 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const void *hs, const void *nd, size_t len)
{
	size_t	h_i;
	size_t	n_i;

	if (ft_strlen(nd) == 0)
		return ((char *)hs);
	h_i = 0;
	while ((h_i < len) && ((const char *)hs)[h_i])
	{
		n_i = 0;
		while (((const char *)hs)[h_i + n_i] == ((const char *)nd)[n_i])
		{
			if (h_i + n_i >= len)
				break ;
			n_i++;
			if (!((const char *)nd)[n_i])
				return ((char *)hs + h_i);
		}
		h_i++;
	}
	return (NULL);
}

/*[BAD CODE]
char	*ft_strnstr(const void *hs, const void *nd, size_t len)
{
	size_t	h_i;
	size_t	n_i;

	if (ft_strlen(nd) == 0)
		return ((char *)hs);
	h_i = 0;
	while ((h_i < len) && ((const char *)hs)[h_i])
	{
		n_i = 0;
		while (((const char *)hs)[h_i + n_i] == ((const char *)nd)[n_i])
		{
			n_i++;
			if (h_i + n_i >= len)
				break ;
			if (!((const char *)nd)[n_i])
				return ((char *)hs + h_i);
		}
		h_i++;
	}
	return (NULL);
}*/