/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:03:19 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/27 01:55:41 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;
	int		size;

	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen(s);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
