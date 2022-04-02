/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_outputmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:22:53 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/02 20:48:57 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

t_outputmap	*create_ouputmap(int sizeof_y, int sizeof_x)
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
	set_vector2(-2147483648, -2147483648, out->maxpoint);
	set_vector2(2147483647, 2147483647, out->minpoint);
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
			if (!set_vector3(v_in[0], v_in[1], in->arr[x][y][1], \
				out->map[x][y]))
				return (FALSE);
		}
	}
	return (TRUE);
}

int	set_outputmap_size(t_outputmap *out)
{
	int	x;
	int	y;

	if (!out)
		return (FALSE);
	x = -1;
	while (++x < out->sizeof_x)
	{
		y = -1;
		while (++y < out->sizeof_y)
		{
			out->maxpoint[X] = fmax(out->map[x][y][X], out->maxpoint[X]);
			out->maxpoint[Y] = fmax(out->map[x][y][Y], out->maxpoint[Y]);
			out->minpoint[X] = fmin(out->map[x][y][X], out->minpoint[X]);
			out->minpoint[Y] = fmin(out->map[x][y][Y], out->minpoint[Y]);
		}
	}
	return (set_offset_scaler_output(out));
}

int	set_offset_scaler_output(t_outputmap *out)
{
	double	x;
	double	y;

	if (!out)
		return (FALSE);
	printf("x : %3.2f  ~ %3.2f  | y : %3.2f ~ %3.2f\n", out->maxpoint[X], \
			out->minpoint[X], out->maxpoint[Y], out->minpoint[Y]);
	x = out->maxpoint[X] - out->minpoint[X];
	y = out->maxpoint[Y] - out->minpoint[Y];
	out->scaler = fmin((WIN_WIDTH / x), (WIN_HEIGHT / y));
	printf("x %3.3f y %3.3f\n",x * out->scaler, y * out->scaler);
	out->offset[X] = (WIN_WIDTH - x * out->scaler) / 2;
	out->offset[Y] = (WIN_HEIGHT - y * out->scaler)/ 2;
	out->offset[X] -= out->minpoint[X] * out->scaler;
	out->offset[Y] -= out->minpoint[Y] * out->scaler;
	return (TRUE);
}