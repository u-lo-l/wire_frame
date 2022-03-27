#include "matrix.h"

t_matrix	*init_matrix(int rows, int cols)
{
	t_matrix	*z_mat;

	z_mat = malloc(sizeof(t_matrix));
	if (!z_mat)
		return (NULL);
	z_mat->dim[0] = rows;
	z_mat->dim[1] = cols;
	z_mat->mat = malloc(sizeof(double *) * cols);
	if (!(z_mat->mat))
	{
		free(z_mat);
		return (NULL);
	}
	while (cols > 0)
	{
		z_mat->mat[z_mat->dim[1] - cols] = malloc(sizeof(double) * rows);
		if (z_mat->mat[z_mat->dim[1] - cols] == NULL)
		{
			z_mat->dim[1] = z_mat->dim[1] - cols - 1;
			destroy_matrix(z_mat);
			return (NULL);
		}
		cols--;
	}
	return (z_mat);
}

t_matrix	*init_zero_matrix(int rows, int cols)
{
	t_matrix	*z_mat;
	int			r;
	int			c;

	z_mat = init_matrix(rows, cols);
	if (z_mat == NULL)
		return (NULL);
	c = -1;
	while (++c < cols)
	{
		r = -1;
		while (++r < rows)
			z_mat->mat[c][r] = 0;
	}
	return (z_mat);
}

t_matrix	*init_3d_vec(double x, double y, double z)
{
	t_matrix	*vec_3d;

	vec_3d = init_matrix(3, 1);
	if (!vec_3d)
		return (NULL);
	vec_3d->mat[0][0] = x;
	vec_3d->mat[0][1] = y;
	vec_3d->mat[0][2] = z;
	return (vec_3d);
}

void	destroy_matrix(t_matrix *matrix)
{
	int	c;

	c = 0;
	while (c < matrix->dim[1])
	{
		free(matrix->mat[c]);
		c++;
	}
	free(matrix);
}
