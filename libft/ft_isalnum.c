/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:24:15 by dkim2             #+#    #+#             */
/*   Updated: 2021/11/10 23:26:53 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

static int  ft_is_upper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

static int  ft_islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

static int ft_isalpha(int c)
{
    return (ft_is_upper(c) || ft_islower(c));
}

int ft_isalnum(int  c)
{
    return (ft_isdigit(c) || ft_isalpha(c));
}