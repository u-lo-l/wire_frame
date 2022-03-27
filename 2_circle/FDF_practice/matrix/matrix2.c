#include "matrix.h"

t_matrix	*mat_mini(t_matrix *a, int row, int col)
{
	t_matrix	*mini;
	int			r_c;
	int			r_a;
	int			c_c;
	int			c_a;

	if (!a || (a->dim[0] < 1) || (a->dim[1] < 1))
		return (NULL);
	mini = init_matrix(a->dim[0] - 1, a->dim[1] - 1);
	if (!mini)
		return (NULL);
	c_c = 0;
	c_a = -1;
	while (++c_a < a->dim[1] && c_c < mini->dim[1])
	{
		r_c = 0;
		r_a = -1;
		if (c_a == col)
			continue ;
		while (++r_a < a->dim[0] && r_c < mini->dim[0])
			if (r_a != row)
				mini->mat[c_c][r_c++] = a->mat[c_a][r_a];
		c_c++;
	}
	return (mini);
}

double	cofactor(t_matrix *a, int row, int col)
{
	double	det_mini;
	int		epsilon;

	if (!a)
		return (NAN);
	epsilon = pow(-1, row + col + 2);
	det_mini = mat_determinant(mat_mini(a, row, col));
	return (epsilon * det_mini);
}

double	mat_determinant(t_matrix *a)
{
	double	det;
	int		c;

	if (!a || a->dim[0] != a->dim[1])
		return (NAN);
	if (a->dim[0] == 1)
		det = a->mat[0][0];
	else
	{
		det = 0;
		c = -1;
		while (++c < a->dim[1])
			det += a->mat[c][0] * cofactor(a, 0, c);
	}
	return (det);
}

t_matrix	*mat_transpose(t_matrix *a)
{
	t_matrix	*trans_mat;
	int			r;
	int			c;

	trans_mat = init_matrix(a->dim[1], a->dim[0]);
	if (trans_mat == NULL)
		return (NULL);
	c = -1;
	while (++c < trans_mat->dim[1])
	{
		r = -1;
		while (++r < trans_mat->dim[0])
			trans_mat->mat[c][r] = a->mat[r][c];
	}
	return (trans_mat);
}

t_matrix	*mat_inverse(t_matrix *a)
{
	t_matrix	*inv;
	int			r;
	int			c;
	double		det;

	if (!a)
		return (NULL);
	det = mat_determinant(a);
	if (det == NAN || 1 / det == INFINITY)
		return (NULL);
	inv = init_matrix(a->dim[0], a->dim[1]);
	c = -1;
	while (inv != NULL && ++c < a->dim[1])
	{
		r = -1;
		while (++r < a->dim[0])
			inv->mat[c][r] = cofactor(a, c, r) / det;
	}
	return (inv);
}
