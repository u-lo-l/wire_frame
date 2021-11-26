/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 03:43:12 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/26 15:23:57 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*temp1;
	const char	*temp2;

	temp1 = s1;
	temp2 = s2;
	i = 0;
	while (i < n)
	{
		if ((temp1[i] - temp2[i]) || temp1[i] == 0)
			break ;
		i++;
	}
	return (temp1[i] - temp2[i]);
}
