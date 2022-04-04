/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:19:10 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/03 02:40:54 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

static int	dvec3_to_color(t_dvec3 color_vec)
{
	int	res;

	if (!color_vec)
		return (FALSE);
	res = ((int)color_vec[0] & 0xff) << 16;
	res += ((int)color_vec[1] & 0xff) << 8;
	res += (int)color_vec[2] & 0xff;
	return (res);
}

static void	color_to_dvec3(int color, t_dvec3 color_vec)
{
	if (!color_vec)
		return ;
	color_vec[0] = (color & 0xff0000) >> 16;
	color_vec[1] = (color & 0xff00) >> 8;
	color_vec[2] = (color & 0xff);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (0 > x || WIN_WIDTH <= x || 0 > y || WIN_HEIGHT <= y)
		return ;
	dst = image->addr + y * image->line + x * (image->bpp / 8);
	*(unsigned int *)dst = color;
}

void	my_mlx_draw_line(t_image *image, t_dvec3 A, t_dvec3 B, \
						t_dvec3 offset)
{
	double	denominator;
	double	delta[5];
	double	temp_a[5];
	double	temp_b[5];

	temp_a[X] = A[X] * offset[2] + offset[X];
	temp_a[Y] = A[Y] * offset[2] + offset[Y];
	temp_b[X] = B[X] * offset[2] + offset[X];
	temp_b[Y] = B[Y] * offset[2] + offset[Y];
	color_to_dvec3(A[2], temp_a + 2);
	color_to_dvec3(B[2], temp_b + 2);
	diff_dvec(delta, temp_a, temp_b, 2);
	delta[X] = (temp_b[X] - temp_a[X]);
	delta[Y] = (temp_b[Y] - temp_a[Y]);
	denominator = fmax(fabs(delta[X]), fabs(delta[Y]));
	scale_dvec(delta, 2, 1 / denominator);
	while ((int)(temp_a[X] - temp_b[X]) || (int)(temp_a[Y] - temp_b[Y]))
	{
		my_mlx_pixel_put(image, (int)temp_a[X], (int)temp_a[Y], \
							dvec3_to_color(temp_a + 2));
		sum_dvec(temp_a, delta, 2);
	}
	my_mlx_pixel_put(image, (int)temp_b[X], (int)temp_b[Y], (int)B[2]);
}

void	my_mlx_print_map(t_mlx *mlx)
{
	int	x;
	int	y;

	if (!mlx)
		return ;
	x = -1;
	while (++x < mlx->out->sizeof_x)
	{
		y = -1;
		while (++y < mlx->out->sizeof_y - 1)
			my_mlx_draw_line(mlx->image, mlx->out->map[x][y], \
				mlx->out->map[x][y + 1], mlx->out->offset);
	}
	x = -1;
	while (++x < mlx->out->sizeof_x - 1)
	{
		y = -1;
		while (++y < mlx->out->sizeof_y)
			my_mlx_draw_line(mlx->image, mlx->out->map[x][y], \
				mlx->out->map[x + 1][y], mlx->out->offset);
	}
}
