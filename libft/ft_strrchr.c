/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:36:46 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/07 16:26:19 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;
	int			size;
	int			i;

	size = ft_strlen(s);
	temp = NULL;
	i = 0;
	while (i <= size)
	{
		if (s[i] == (char)c)
			temp = &s[i];
		i++;
	}
	return ((char *)temp);
}
