/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:44:38 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/24 22:46:11 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	prefix_len;
	size_t	suffix_len;
	char	*new_str;

	prefix_len = ft_strlen(s1);
	suffix_len = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (prefix_len + suffix_len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < prefix_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < prefix_len + suffix_len)
	{
		new_str[prefix_len + i] = s2[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
