#include "matrix.h"

t_matrix	*mat_sum(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			r;
	int			c;

	if (!a || !b)
		return (NULL);
	if ((a->dim[0] != b->dim[0]) || (a->dim[1] != b->dim[1]))
		return (NULL);
	result = init_matrix(a->dim[0], a->dim[1]);
	if (result == NULL)
		return (NULL);
	r = -1;
	while (++r < a->dim[0])
	{
		c = -1;
		while (++c < a->dim[1])
			result->mat[r][c] = a->mat[r][c] + b->mat[r][c];
	}
	return (result);
}

t_matrix	*mat_sub(t_matrix *a, t_matrix *b)
{
	t_matrix	*result;
	int			r;
	int			c;

	if (!a || !b)
		return (NULL);
	if ((a->dim[0] != b->dim[0]) || (a->dim[1] != b->dim[1]))
		return (NULL);
	result = init_matrix(a->dim[0], a->dim[1]);
	if (result == NULL)
		return (NULL);
	r = -1;
	while (++r < a->dim[0])
	{
		c = -1;
		while (++c < a->dim[1])
			result->mat[r][c] = a->mat[r][c] - b->mat[r][c];
	}
	return (result);
}

t_matrix	*mat_mul(t_matrix *a, t_matrix *b)
{
	t_matrix	*trans;
	t_matrix	*result;
	int			c;
	int			r;

	if (a->dim[1] != b->dim[0])
		return (NULL);
	trans = mat_transpose(a);
	if (!trans)
		return (NULL);
	result = init_matrix(a->dim[0], b->dim[1]);
	c = -1;
	while (result != NULL && ++c < result->dim[1])
	{
		r = -1;
		while (++r < result->dim[0])
			result->mat[c][r] = vec3_dot(trans->mat[r], b->mat[c]);
	}
	destroy_matrix(trans);
	return (result);
}

t_matrix	*mat_scale(t_matrix *a, double scaler)
{
	t_matrix	*result;
	int			r;
	int			c;

	if (!a || scaler == INFINITY)
		return (NULL);
	result = init_matrix(a->dim[0], a->dim[1]);
	if (!result)
		return (NULL);
	r = -1;
	while (++r < result->dim[0])
	{
		c = -1;
		while (++c <result->dim[1])
			result->mat[r][c] = a->mat[r][c] * scaler;
	}
	return (result);
}