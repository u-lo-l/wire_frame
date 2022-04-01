/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 00:40:46 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/01 17:55:47 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DATA_H
# define FDF_DATA_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0
# define X 0
# define Y 1
# define Z 2
# define W 3

# define WIN_WIDTH 800
# define WIN_HEIGHT 450
/*FOR PROCESS INPUT MAP*/
typedef int	t_ivec2[2];

typedef struct s_qnode
{
	t_ivec2			data;
	struct s_qnode	*next;
}		t_qnode;

typedef struct s_queue_type
{
	int		queue_size;
	t_qnode	*pfront;
	t_qnode	*prear;
}			t_queue;

typedef struct s_inputmap
{
	int		sizeof_y;
	int		sizeof_x;
	t_ivec2	**arr;
}	t_inputmap;

/*FOR MATRIX AND OUTPUT MAP*/
typedef double	t_dvec2[2];
typedef double	t_dvec3[3];
typedef t_dvec3	t_33mat[3];

typedef struct s_ouputmap
{
	int		sizeof_y;
	int		sizeof_x;
	t_ivec2	maxpoint;
	t_ivec2	minpoint;
	t_ivec2	offset_default;
	t_ivec2	offset_curr;
	t_dvec3	**map;
}			t_outputmap;

#endif