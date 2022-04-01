#include "../INC/fdf.h"

int	tranformation_33mat(t_33mat mat, t_dvec3 u, t_dvec3 v, t_dvec3 w)
{
	int i;

	if (!mat || (!u && !v && !w))
		return (FALSE);
	if (!zero_33mat(mat))
		return (FALSE);
	i = -1;
	while (++i < 3)
	{
		if (u !=NULL)
			mat[0][i] = u[i];
		if (v != NULL)
			mat[1][i] = v[i];
		if (w != NULL)
			mat[2][i] = w[i];
	}
	if (!transpose_33matrix(mat))
		return (FALSE);
	return (TRUE);
}

int	rotation_matrix(t_dvec3 axis, double rad, t_33mat result)
{
	double c;
	double s;
	double v;

	if (!axis || rad == NAN || rad == INFINITY)
		return (FALSE);
	c = cos(rad);
	s = sin(rad);
	v = 1 - c;
	result[X][X] = axis[X] * axis[X] * v + c;
	result[X][Y] = axis[X] * axis[Y] * v + axis[Z] * s;
	result[X][Z] = axis[X] * axis[Z] * v - axis[Y] * s;

	result[Y][X] = axis[Y] * axis[X] * v - axis[Z] * s;
	result[Y][Y] = axis[Y] * axis[Y] * v + c;
	result[Y][Z] = axis[Y] * axis[Z] * v + axis[X] * s;
	
	result[Z][X] = axis[Z] * axis[X] * v + axis[Y] * s;
	result[Z][Y] = axis[Z] * axis[Y] * v - axis[X] * s;
	result[Z][Z] = axis[Z] * axis[Z] * v + c;
	return (TRUE);
}

int	rotate(t_dvec3 vec, t_dvec3 axis, double rad, t_dvec3 result)
{
	t_33mat	rotate_mat;

	if (!vec || !axis || rad != NAN || rad != INFINITY)
		return (FALSE);
	if (!rotation_matrix(axis, rad, rotate_mat))
		return (FALSE);
	if (!transform(vec, rotate_mat, result))
		return (FALSE);
	return (TRUE);
}

int	transform(t_dvec3 vec, t_33mat mat, t_dvec3 result)
{
	int		i;
	t_33mat	trans;

	if (!vec || !mat || !result)
		return (FALSE);
	if (!mat_dup(mat, trans) || !transpose_33matrix(trans))
		return (FALSE);
	i = -1;
	while (++i < 3)
		if (!inner_product(trans[i], vec, result + i))
			return (FALSE);
	return (TRUE);
}