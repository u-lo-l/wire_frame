#include "../INC/fdf.h"

int	dvec3_to_color(t_dvec3 color_vec)
{
	int	res;

	if (!color_vec)
		return (FALSE);
	res = ((int)color_vec[0] & 0xff) << 16;
	res += ((int)color_vec[1] & 0xff) << 8;
	res += (int)color_vec[2] & 0xff;
	return (res);
}

void	color_to_dvec3(int color, t_dvec3 color_vec)
{
	if (!color_vec)
		return ;
	color_vec[0] = (color & 0xff0000) >> 16;
	color_vec[1] = (color & 0xff00) >> 8;
	color_vec[2] = (color & 0xff);
}

void	convert_to_altitude_color(t_mlx *mlx, t_ivec2 pos, t_dvec3 color_vec)
{
	long	gap;
	int		z_value;

	printf("max : %d\n min %d\n", mlx->in->altitude[0], mlx->in->altitude[1]);
	gap = mlx->in->altitude[0] - mlx->in->altitude[1];
	z_value = mlx->in->arr[pos[X]][pos[Y]][0];
	color_vec[1] = (mlx->in->altitude[0] - z_value) / gap;
	color_vec[2] = (z_value - mlx->in->altitude[1]) / gap;
	color_vec[1] *= 0xff;
	color_vec[2] *= 0xff;
	color_vec[0] = 0;
}

void	get_color_vector(t_mlx *mlx, t_ivec2 pos, t_dvec3 color_vec)
{
	int	color;

	color = mlx->out->map[pos[X]][pos[Y]][2];
	if (mlx->color_mode == 0)
		color_to_dvec3(color, color_vec);
	else if (mlx->color_mode == 1)
		convert_to_altitude_color(mlx, pos, color_vec);
}