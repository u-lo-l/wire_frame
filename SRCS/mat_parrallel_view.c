/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_parrallel_view.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkim2 <dkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:39:39 by dkim2             #+#    #+#             */
/*   Updated: 2022/04/05 14:39:41 by dkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/fdf.h"

void	xy_plane_view(t_dvec3 u, t_dvec3 v, t_dvec3 w)
{
	set_vector3(0, 1, 0, u);
	set_vector3(1, 0, 0, v);
	set_vector3(0, 0, -1, w);
}

void	yz_plane_view(t_dvec3 u, t_dvec3 v, t_dvec3 w)
{
	set_vector3(0, 1, 0, u);
	set_vector3(0, 0, -1, v);
	set_vector3(-1, 0, 0, w);
}

void	zx_plane_view(t_dvec3 u, t_dvec3 v, t_dvec3 w)
{
	set_vector3(-1, 0, 0, u);
	set_vector3(0, 0, -1, v);
	set_vector3(0, -1, 0, w);
}
