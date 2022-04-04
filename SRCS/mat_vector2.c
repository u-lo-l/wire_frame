/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_vector2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:15:32 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/04 16:15:34 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

int	scale_dvec(double *v1, int size, double scaler)
{
	int	i;

	if (!v1)
		return (FALSE);
	i = -1;
	while (++i < size)
		v1[i] *= scaler;
	return (TRUE);
}

int	sum_dvec(double *v1, double *v2, int size)
{
	int	i;

	if (!v1 || !v2)
		return (FALSE);
	i = -1;
	while (++i < size)
		v1[i] += v2[i];
	return (TRUE);
}

int	diff_dvec(double *result, double *v1, double *v2, int size)
{
	int	i;

	if (!v1 || !v2)
		return (FALSE);
	i = -1;
	while (++i < size)
		result[i] = v2[i] - v1[i];
	return (TRUE);
}
