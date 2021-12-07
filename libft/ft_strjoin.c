/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:44:38 by dkim2             #+#    #+#             */
/*   Updated: 2021/12/07 20:23:56 by dkim2            ###   ########.fr       */
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

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	prefix_len = ft_strlen(s1);
	suffix_len = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (prefix_len + suffix_len + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < prefix_len)
		new_str[i] = s1[i];
	i = -1;
	while (++i < suffix_len)
		new_str[prefix_len + i] = s2[i];
	new_str[prefix_len + i] = 0;
	return (new_str);
}
