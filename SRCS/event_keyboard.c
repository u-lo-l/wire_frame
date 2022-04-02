#include "../INC/fdf.h"

int	keydown(int keycode, t_mlx *mlx)
{
	if (!mlx)
		return (0);
	if (keycode == 'Q' || keycode == 'q')
	{
		delete_mlx(mlx);
		exit(0);
	}
	if (keycode == 65363)
		mlx->out->offset[X]++;
	if (keycode == 65361)
		mlx->out->offset[X]--;
	if (keycode == 65362)
		mlx->out->offset[Y]--;
	if (keycode == 65364)
		mlx->out->offset[Y]++;
	mlx_renew_image(mlx);
	return (1);
}

int	mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (x == y || x == button)
		button = x;
	mlx->onclick = 1;
	printf("%d\n", button);
	if (button == 4)
		mlx->out->scaler *= 1.05;
	if (button == 5)
		mlx->out->scaler /= 1.05;
	mlx_renew_image(mlx);
	return (1);
}

int	mouseup(int button, int x, int y, t_mlx *mlx)
{
	if (x == y || x == button)
		button = x;
	mlx->onclick = 0;
	return (0);
}

int	mousemove(int x, int y, t_mlx *mlx)
{
	if (mlx->onclick == 1)
		printf("mouse_onclick : (%03d, %03d)\n", x, y);
	return (0);
}

int	destroy(t_mlx *mlx)
{
	if (!mlx)
	{
		printf("BAD\n");
		return (0);
	}
	printf("destroy\n");
	delete_mlx(mlx);
	exit(0);
}