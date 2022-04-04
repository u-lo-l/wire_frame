/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:19:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/05 00:55:44 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (0 > x || WIN_WIDTH <= x || 0 > y || WIN_HEIGHT <= y)
		return ;
	dst = image->addr + y * image->line + x * (image->bpp / 8);
	*(unsigned int *)dst = color;
}

void	my_mlx_draw_line(t_mlx *mlx, t_outputmap *out, t_ivec2 p1, t_ivec2 p2)
{
	double	denominator;
	double	delta[5];
	double	temp_a[5];
	double	temp_b[5];

	temp_a[X] = out->map[p1[X]][p1[Y]][X] * out->offset[2] + out->offset[X];
	temp_a[Y] = out->map[p1[X]][p1[Y]][Y] * out->offset[2] + out->offset[Y];
	temp_b[X] = out->map[p2[X]][p2[Y]][X] * out->offset[2] + out->offset[X];
	temp_b[Y] = out->map[p2[X]][p2[Y]][Y] * out->offset[2] + out->offset[Y];
	get_color_vector(mlx, p1, temp_a + 2);
	get_color_vector(mlx, p2, temp_b + 2);
	diff_dvec(delta, temp_a, temp_b, 5);
	denominator = fmax(fabs(delta[X]), fabs(delta[Y]));
	scale_dvec(delta, 5, 1 / denominator);
	while ((int)(temp_a[X] - temp_b[X]) || (int)(temp_a[Y] - temp_b[Y]))
	{
		my_mlx_pixel_put(mlx->image, (int)temp_a[X], (int)temp_a[Y], \
							dvec3_to_color(temp_a + 2));
		sum_dvec(temp_a, delta, 5);
	}
	my_mlx_pixel_put(mlx->image, (int)temp_b[X], (int)temp_b[Y], \
						dvec3_to_color(temp_a + 2));
}

void	my_mlx_print_map(t_mlx *mlx)
{
	t_ivec2	pos;
	t_ivec2	temp;

	if (!mlx)
		return ;
	pos[X] = -1;
	while (++(pos[X]) < mlx->out->sizeof_x)
	{
		pos[Y] = -1;
		while ((++(pos[Y]) < mlx->out->sizeof_y - 1) && \
				(set_ivector2(pos[X], pos[Y] + 1, temp)))
			my_mlx_draw_line(mlx, mlx->out, pos, temp);
	}
	pos[X] = -1;
	while (++(pos[X]) < mlx->out->sizeof_x - 1)
	{
		pos[Y] = -1;
		while ((++(pos[Y]) < mlx->out->sizeof_y) \
				&& (set_ivector2(pos[X] + 1, pos[Y], temp)))
			my_mlx_draw_line(mlx, mlx->out, pos, temp);
	}
}
