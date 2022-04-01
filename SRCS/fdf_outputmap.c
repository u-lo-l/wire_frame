#include "../INC/fdf.h"

t_outputmap *create_ouputmap(int sizeof_y, int sizeof_x)
{
	t_outputmap	*out;

	out = malloc(sizeof(t_outputmap));
	if (!out)
		return (NULL);
	out->map = malloc(sizeof(t_dvec3 *) * sizeof_x);
	if (!out->map)
	{
		free(out);
		return (NULL);
	}
	out->sizeof_y = sizeof_y;
	out->sizeof_x = -1;
	while (++(out->sizeof_x) < sizeof_x)
	{
		out->map[out->sizeof_x] = malloc(sizeof(t_dvec3) * sizeof_y);
		if (!out->map[out->sizeof_x])
		{
			delete_outputmap(out);
			return (NULL);
		}
	}
	set_ivector2(-2147483648, -2147483648, out->maxpoint);
	set_ivector2(2147483647, 2147483647, out->minpoint);
	return (out);
}

void	delete_outputmap(t_outputmap *out)
{
	int	i;

	if (!out)
		return ;
	i = -1;
	while (++i < out->sizeof_x)
		free(out->map[i]);
	free(out->map);
	free(out);
}

int	convert_map(t_inputmap *in, t_33mat mat, t_outputmap *out)
{
	int			x;
	int			y;
	t_dvec3		v_in;
	t_dvec3		v_out;

	if (!in || !out)
		return (FALSE);
	x = -1;
	while (++x < in->sizeof_x)
	{
		y = -1;
		while (++y < in->sizeof_y)
		{
			if (!set_vector3(x, y, (double)(in->arr[x][y][0]), v_out))
				return (FALSE);
			if (!transform(v_out, mat, v_in))
				return (FALSE);
			if (!set_vector3(v_in[0], v_in[1], in->arr[x][y][1], out->map[x][y]))
				return (FALSE);
		}
	}
	return (TRUE);
}
			// (out->map[y][x])[0] = v_in[0];
			// (out->map[y][x])[1] = v_in[1];
			// (out->map[y][x])[2] = in->arr[y][x][1];

int	set_outputmap_size(t_outputmap *out)
{
	int	x;
	int	y;
	int	offset_x;
	int	offset_y;

	if (!out)
		return (FALSE);
	x = -1;
	while (++x < out->sizeof_x)
	{
		y = -1;
		while (++y < out->sizeof_y)
		{
			out->maxpoint[X] = ceil(fmax(out->map[x][y][X], out->maxpoint[X]));
			out->maxpoint[Y] = ceil(fmax(out->map[x][y][Y], out->maxpoint[Y]));
			out->minpoint[X] = floor(fmin(out->map[x][y][X], out->minpoint[X]));
			out->minpoint[Y] = floor(fmin(out->map[x][y][Y], out->minpoint[Y]));
		}
	}
	offset_x = (WIN_HEIGHT - (out->maxpoint[X], out->minpoint[X])) / 2;
	offset_y = (WIN_WIDTH - (out->maxpoint[Y], out->minpoint[Y])) / 2;
	if(!set_ivector2(offset_x, offset_y, out->offset_default))
		return (FALSE);
	return (TRUE);
}