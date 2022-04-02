/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:21:34 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/03 02:38:45 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

int	keydown(int keycode, t_mlx *mlx)
{
	if (!mlx)
		return (0);
	if (keycode == 65307)
	{
		delete_mlx(mlx);
		exit(0);
	}
	else if (keycode == 'x' || keycode == 'y' || keycode == 'z')
		rotate_global(mlx, M_PI / 24, keycode);
	else if (keycode == 'u' || keycode == 'v' || keycode == 'w')
		rotate_global(mlx, -M_PI / 24, keycode + ('x' - 'u'));
	else if (keycode == 'h')
	{
		isometric_view(mlx->trans);
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
		mlx->out->scaler *= 1.05;
	else if (button == 5)
		mlx->out->scaler /= 1.05;
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
	else if (mlx-> onclick == 3)
	{
		rad = M_PI / 45;
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
