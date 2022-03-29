/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:40:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/03/30 01:55:34 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0
# define X 0;
# define Y 1;
# define Z 2;
# define W 3;

typedef int	t_z_n_color[2];

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef struct s_qnode
{
	t_z_n_color		data;
	struct s_qnode	*next;
}		t_qnode;

typedef struct s_queue_type
{
	int		queue_size;
	t_qnode	*pfront;
	t_qnode	*prear;
}			t_queue;

typedef struct s_map_org
{
	int			width;
	int			height;
	t_z_n_color	**arr;
}	t_map_org;

#endif