#include "../INC/fdf.h"

int	zero_33mat(t_33mat mat)
{
	int	i;
	int	j;

	if (!mat)
		return (FALSE);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			mat[i][j] = 0;
		i++;
	}
	return (TRUE);
}

int	transpose_33matrix(t_33mat mat)
{
	double	temp;

	if (!mat)
		return (FALSE);
	temp = mat[0][1];
	mat[0][1] = mat[1][0];
	mat[1][0] = temp;
	temp = mat[0][2];
	mat[0][2] = mat[2][0];
	mat[2][0] = temp;
	temp = mat[1][2];
	mat[1][2] = mat[2][1];
	mat[2][1] = temp;
	return (TRUE);	
}

int	mat_mul(t_33mat mat1, t_33mat mat2, t_33mat result)
{
	int	i;
	int	j;

	if (!mat1 || !mat2 || !result)
		return (FALSE);
	if (!transpose_33matrix(mat1))
		return (FALSE);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (!inner_product(mat1[i], mat2[j], &result[i][j]))
				return (FALSE);
	}
	return (TRUE);
}

int	mat_dup(t_33mat mat, t_33mat dup)
{
	int	i;
	int	j;
	
	if (!mat || !dup)
		return (FALSE);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			dup[i][j] = mat[i][j];
	}
	return (TRUE);
}