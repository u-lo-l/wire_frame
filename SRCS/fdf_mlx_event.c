/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:21:34 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/05 11:35:29 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

int	keydown(int keycode, t_mlx *mlx)
{
	if (!mlx)
		return (0);
	if (keycode == 53)
	{
		delete_mlx(mlx);
		exit(0);
	}
	else if (keycode == 0 || keycode == 1 || keycode == 2)
		rotate_global(mlx, M_PI / 24, keycode);
	else if (keycode == 12 || keycode == 13 || keycode == 14)
		rotate_global(mlx, -M_PI / 24, keycode - 12);
	else if (keycode == 8)
	{
		mlx->color_mode ^= 0b1;
		mlx_renew_image(mlx);
	}
	else if (18 <= keycode && keycode <= 26)
	{
		isometric_view(mlx->trans, keycode);
		convert_map(mlx->in, mlx->trans, mlx->out);
		mlx_renew_image(mlx);
	}
	else
		return (0);
	return (1);
}

int	mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (!mlx)
		return (0);
	set_ivector2(x, y, mlx->last);
	mlx->onclick = button;
	if (button == 4)
		mlx->out->offset[2] *= 1.05;
	else if (button == 5)
		mlx->out->offset[2] /= 1.05;
	else
		return (0);
	mlx_renew_image(mlx);
	return (1);
}

int	mouseup(int button, int x, int y, t_mlx *mlx)
{
	if (x > 0 && y > 0 && button > 0)
		mlx->onclick = 0;
	return (0);
}

int	mousemove(int x, int y, t_mlx *mlx)
{
	double	dx;
	double	dy;
	double	rad;

	if (mlx->onclick == 1)
	{
		set_ivector2(x, y, mlx->curr);
		mlx->out->offset[X] += mlx->curr[X] - mlx->last[X];
		mlx->out->offset[Y] += mlx->curr[Y] - mlx->last[Y];
		set_ivector2(x, y, mlx->last);
		mlx_renew_image(mlx);
	}
	else if (mlx-> onclick == 2)
	{
		rad = M_PI / 30;
		set_ivector2(x, y, mlx->curr);
		dx = mlx->last[X] - mlx->curr[X];
		dy = mlx->last[Y] - mlx->curr[Y];
		if (dx == 0 && dy == 0)
			return (0);
		rotate_view(mlx, rad, -dy, dx);
		set_ivector2(x, y, mlx->last);
	}
	return (1);
}

int	destroy(t_mlx *mlx)
{
	if (!mlx)
		return (0);
	delete_mlx(mlx);
	exit(0);
}
