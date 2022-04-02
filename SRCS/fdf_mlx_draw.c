#include "../INC/fdf.h"

int	scale_color(int color, double scaler)
{
	int		red;
	int		green;
	int		blue;

	red = ((color & 0XFF0000) >> 16) * scaler;
	green = ((color & 0X00FF00) >> 8) * scaler;
	blue = (color & 0X0000FF) * scaler;
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	if (red < -255)
		red = -255;
	if (green < -255)
		green = -255;
	if (blue < -255)
		blue = -255;
	color = (red << 16) + (green << 8) + blue;
	return (color);
}

int	add_color(int color, int stride)
{
	int	red;
	int	green;
	int	blue;

	red = ((color & 0XFF0000) >> 16) + ((stride & 0XFF0000) >> 16);
	green = ((color & 0X00FF00) >> 8) + ((color & 0X00FF00) >> 8);
	blue = (color & 0X0000FF) + (stride & 0X0000FF);
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	if (red < 0)
		red = 0;
	if (green < 0)
		green = 0;
	if (blue < 0)
		blue = 0;
	color = (red << 16) + (green << 8) + blue;
	return (color);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;
	if (0 > x || WIN_WIDTH <= x || 0 > y || WIN_HEIGHT <= y)
		return ;
	dst = image->addr + y * image->line + x * (image->bpp/8);
	*(unsigned int*)dst = color;
}

void	my_mlx_draw_line(t_image *image, t_dvec3 A, t_dvec3 B, \
						t_ivec2 offset, double scaler)
{
	double	denominator;
	t_dvec3	delta;
	t_dvec3	temp_a;
	t_dvec3	temp_b;

	temp_a[X] = A[X] * scaler + offset[X];
	temp_a[Y] = A[Y] * scaler + offset[Y];
	temp_b[X] = B[X] * scaler + offset[X];
	temp_b[Y] = B[Y] * scaler + offset[Y];
	delta[X] = (temp_b[X] - temp_a[X]);
	delta[Y] = (temp_b[Y] - temp_a[Y]);
	delta[2] = (B[2] - A[2]);
	denominator = fmax(fabs(delta[X]), fabs(delta[Y]));
	delta[X] /= denominator;
	delta[Y] /= denominator;
	delta[2] = scale_color(delta[2], 1 / denominator);
	while ((int)(temp_a[X] - temp_b[X]) || (int)(temp_a[Y] - temp_b[Y]))
	{
		my_mlx_pixel_put(image, (int)temp_a[X], (int)temp_a[Y], (int)A[2]);
		temp_a[X] += delta[X];
		temp_a[Y] += delta[Y];
		A[2] = add_color(A[2], delta[2]);
	}
	my_mlx_pixel_put(image, (int)temp_b[X], (int)temp_b[Y], (int)B[2]);
}

void	my_mlx_print_map(t_image *image, t_outputmap *map)
{
	int	x;
	int	y;

	if (!image || !map)
		return ;
	x = -1;
	print_output_map(map);
	while (++x < map->sizeof_x)
	{
		y = -1;
		while (++y < map->sizeof_y - 1)
			my_mlx_draw_line(image, map->map[x][y], map->map[x][y + 1], \
								map->offset, map->scaler);
	}
	x = -1;
	while (++x < map->sizeof_x - 1)
	{
		y = -1;
		while(++y < map->sizeof_y)
			my_mlx_draw_line(image, map->map[x][y], map->map[x + 1][y], \
								map->offset, map->scaler);
	}
}