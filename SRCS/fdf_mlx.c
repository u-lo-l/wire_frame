/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:22:22 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/03 02:39:12 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

t_mlx	*creat_mlx(t_inputmap *in)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->image = malloc(sizeof(t_image));
	mlx->in = in;
	if (!isometric_view(mlx->trans))
		return (0);
	mlx->out = create_ouputmap(in->sizeof_y, in->sizeof_x);
	if (!convert_map(in, mlx->trans, mlx->out))
		return (0);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx->image->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->image->addr = mlx_get_data_addr(mlx->image->img, &(mlx->image->bpp), \
									&(mlx->image->line), &(mlx->image->endian));
	set_outputmap_size(mlx->out);
	mlx->onclick = 0;
	return (mlx);
}

void	delete_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	mlx_destroy_image(mlx->mlx, mlx->image->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
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

int	rotate_view(t_mlx *mlx, double rad, int dx, int dy)
{
	t_dvec3	axis;
	t_dvec3	temp;
	t_33mat	rot;
	t_33mat	mat;

	get_unitvector(dx, dy, 0, temp);
	transpose_33matrix(mlx->trans);
	transform(temp, mlx->trans, axis);
	transpose_33matrix(mlx->trans);
	rotation_matrix(axis, rad, rot);
	mat_mul(mlx->trans, rot, mat);
	mat_dup(mat, mlx->trans);
	if (!convert_map(mlx->in, mlx->trans, mlx->out))
		return (FALSE);
	mlx_renew_image(mlx);
	return (TRUE);
}

int	rotate_global(t_mlx *mlx, double rad, char axis_name)
{
	t_dvec3	axis;
	t_33mat	temp;
	t_33mat	rot;

	if (axis_name == 0)
		set_vector3(1, 0, 0, axis);
	else if (axis_name == 1)
		set_vector3(0, 1, 0, axis);
	else if (axis_name == 2)
		set_vector3(0, 0, 1, axis);
	else
		return (FALSE);
	rotation_matrix(axis, rad, rot);
	mat_mul(mlx->trans, rot, temp);
	mat_dup(temp, mlx->trans);
	if (!convert_map(mlx->in, mlx->trans, mlx->out))
		return (FALSE);
	mlx_renew_image(mlx);
	return (TRUE);
}
