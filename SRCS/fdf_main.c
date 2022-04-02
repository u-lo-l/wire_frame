/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:16:45 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/02 23:01:42 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

int	main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_inputmap	*in;

	if (argc != 2)
		return (0);
	in = get_origin_map(argv[argc - 1]);
	if (in == NULL)
		return (0);
	mlx = creat_mlx(in);
	if (!mlx)
	{
		delete_map_org(in);
		return (0);
	}
	my_mlx_print_map(mlx->image, mlx->out);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->img, 0, 0);
	mlx_hook(mlx->win, 2, 1L << 0, keydown, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, mousedown, mlx);
	mlx_hook(mlx->win, 5, 1L << 3, mouseup, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, mousemove, mlx);
	mlx_hook(mlx->win, 17, 0, destroy, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
