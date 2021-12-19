/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:29:46 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/25 17:58:15 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	size;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		f(i, (s + i));
		i++;
	}
	return ;
}
