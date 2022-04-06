/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:40:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/02 21:58:17 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H

# define TRUE 1
# define FALSE 0
# define X 0
# define Y 1
# define Z 2
# define W 3

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
/*FOR PROCESS INPUT MAP*/
typedef int		t_ivec2[2];
typedef int		t_ivec3[3];

typedef struct s_qnode
{
	t_ivec2			data;
	struct s_qnode	*next;
}				t_qnode;

typedef struct s_queue_type
{
	int		queue_size;
	t_qnode	*pfront;
	t_qnode	*prear;
}				t_queue;

typedef struct s_inputmap
{
	int		sizeof_y;
	int		sizeof_x;
	t_ivec2	altitude;
	t_ivec2	**arr;
}				t_inputmap;
/*FOR MATRIX AND OUTPUT MAP*/
typedef double	t_dvec2[2];
typedef double	t_dvec3[3];
typedef t_dvec3	t_33mat[3];

typedef struct s_ouputmap
{
	int		sizeof_y;
	int		sizeof_x;
	t_dvec3	maxpoint;
	t_dvec3	minpoint;
	t_dvec3	offset;
	t_dvec3	**map;
}				t_outputmap;

/*FOR MiniLibX*/
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}				t_image;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_image		*image;
	t_inputmap	*in;
	t_outputmap	*out;
	t_33mat		trans;
	t_ivec2		last;
	t_ivec2		curr;
	int			onclick;
	int			color_mode;
}				t_mlx;

#endif