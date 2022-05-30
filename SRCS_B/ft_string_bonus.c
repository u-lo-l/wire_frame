/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:27:43 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/01 18:27:44 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC_B/fdf_bonus.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str != NULL && str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		len1;
	int		len2;
	int		i;
	char	*new;

	if (!str2)
		return (str1);
	if (str1 == NULL)
		len1 = 0;
	else
		len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	new = malloc(sizeof(char *) * (len1 + len2 + 1));
	i = -1;
	while (++i < len1)
		new[i] = str1[i];
	i = -1;
	while (++i < len2)
		new[len1 + i] = str2[i];
	new[len1 + i] = 0;
	free(str1);
	return (new);
}

char	*ft_substr(char *str, int start, int size)
{
	char	*substr;
	int		i;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (start >= len)
		size = 0;
	else if (start + size > len)
		size = len - start;
	substr = malloc(sizeof(char) * (size + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < size && start + i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

char	*ft_strndup(char *str, int size)
{
	int		i;
	int		len;
	char	*ret;

	len = ft_strlen(str);
	if (len == -1)
		return (NULL);
	if (len < size)
		size = len;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < size)
		ret[i] = str[i];
	ret[i] = 0;
	return (ret);
}
