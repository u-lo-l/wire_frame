/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:13:22 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/03 02:47:13 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC_B/fdf_bonus.h"

static void	isometric_view1(t_dvec3 u, t_dvec3 v, t_dvec3 w)
{
	get_unitvector(-1, 1, 0, u);
	get_unitvector(1, 1, -2, v);
	get_unitvector(-1, -1, -1, w);
}

static void	isometric_view2(t_dvec3 u, t_dvec3 v, t_dvec3 w)
{
	get_unitvector(-1, -1, 0, u);
	get_unitvector(-1, 1, -2, v);
	get_unitvector(1, -1, -1, w);
}

static void	isometric_view3(t_dvec3 u, t_dvec3 v, t_dvec3 w)
{
	get_unitvector(1, -1, 0, u);
	get_unitvector(-1, -1, -2, v);
	get_unitvector(1, 1, -1, w);
}

static void	isometric_view4(t_dvec3 u, t_dvec3 v, t_dvec3 w)
{
	get_unitvector(1, 1, 0, u);
	get_unitvector(1, -1, -2, v);
	get_unitvector(-1, 1, -1, w);
}

int	isometric_view(t_33mat mat, int view_num)
{
	t_dvec3	u;
	t_dvec3	v;
	t_dvec3	w;

	if (!mat)
		return (FALSE);
	if (view_num == 18)
		isometric_view1(u, v, w);
	else if (view_num == 19)
		isometric_view2(u, v, w);
	else if (view_num == 20)
		isometric_view3(u, v, w);
	else if (view_num == 21)
		isometric_view4(u, v, w);
	else if (view_num == 23)
		xy_plane_view(u, v, w);
	else if (view_num == 22)
		yz_plane_view(u, v, w);
	else if (view_num == 26)
		zx_plane_view(u, v, w);
	else
		return (FALSE);
	tranformation_33mat(mat, u, v, w);
	return (TRUE);
}
