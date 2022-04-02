#include "../INC/fdf.h"

t_mlx	*creat_mlx(t_inputmap *in)
{
	t_mlx	*mlx;
	t_33mat	tranformation;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->image = malloc(sizeof(t_image));
	mlx->in = in;
	if (!isometric_view(tranformation))
		return (0);
	mlx->out = create_ouputmap(in->sizeof_y, in->sizeof_x);
	if (!convert_map(in, tranformation, mlx->out))
		return (0);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx->image->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img, &(mlx->image->bpp), \
									&(mlx->image->line), &(mlx->image->endian));
	set_outputmap_size(mlx->out);
	return (mlx);
}

void	delete_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	mlx_destroy_image(mlx->mlx, mlx->image->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	mlx_loop_end(mlx->mlx);
	delete_map_org(mlx->in);
	delete_outputmap(mlx->out);
	free(mlx->image);
	free(mlx->mlx);
	free(mlx);
}

int	mlx_renew_image(t_mlx	*mlx)
{
	if (!mlx)
		return (FALSE);
	mlx_destroy_image(mlx->mlx, mlx->image->img);
	mlx->image->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img, &(mlx->image->bpp), \
									&(mlx->image->line), &(mlx->image->endian));
	my_mlx_print_map(mlx->image, mlx->out);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->img, 0, 0);
	return (TRUE);
}