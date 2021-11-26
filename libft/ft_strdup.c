/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:31:13 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/27 01:30:42 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*copy;

	size = ft_strlen(s1);
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}
