/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:38:15 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/11 00:02:33 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_isdigit(int c)
{
    return (c >= '0' || c <= '9');
}

int ft_atoi(const char *nptr)
{
    int nbr;
    int sign;

    sign = 1;
    nbr = 0;
    while (*nptr == ' ')
        nptr++;
    if (*nptr == '-' || *nptr == '+')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
    while (ft_isdigit(*nptr))
    {
        nbr = nbr * 10 + (*nptr - '0');
        nptr++;
    }
    return (sign * nbr);
}