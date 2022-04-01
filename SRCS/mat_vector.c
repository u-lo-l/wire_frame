/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:24:48 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/01 19:23:57 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

int	set_ivector2(int i, int j, t_ivec2 result)
{
	if (!result)
		return (FALSE);
	result[X] = i;
	result[Y] = j;
	return (TRUE);
}

int	set_vector3(double i, double j, double k, t_dvec3 result)
{
	if (!result || i == NAN || j == NAN || k == NAN)
		return (FALSE);
	if (i == INFINITY || j == INFINITY || k == INFINITY)
		return (FALSE);
	result[X] = i;
	result[Y] = j;
	result[Z] = k;
	return (TRUE);
}

int	get_unitvector(double i, double j, double k, t_dvec3 result)
{
	double	l2norm;

	if (!result || i == NAN || j == NAN || k == NAN)
		return (FALSE);
	if (i == INFINITY || j == INFINITY || k == INFINITY)
		return (FALSE);
	l2norm = i * i + j * j + k * k;
	l2norm = sqrt(l2norm);
	result[X] = i / l2norm;
	result[Y] = j / l2norm;
	result[Z] = k / l2norm;
	return (TRUE);
}

int	inner_product(t_dvec3 a, t_dvec3 b, double *result)
{
	int	i;

	if (!a || !b)
		return (FALSE);
	*result = 0;
	i = -1;
	while (++i < 3)
		*result += a[i] * b[i];
	return (TRUE);
}

int	cross_product(t_dvec3 a, t_dvec3 b, t_dvec3 result)
{
	if (!a || !b)
		return (FALSE);
	result[X] = a[Y] * b[Z] - a[Z] * b[Y];
	result[Y] = a[X] * b[Z] - a[Z] * b[X];
	result[Z] = a[X] * b[Y] - a[Y] * b[X];
	return (TRUE);
}
