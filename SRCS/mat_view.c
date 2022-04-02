#include "../INC/fdf.h"


int	isometric_view(t_33mat mat)
{
	t_dvec3	u;
	t_dvec3	v;
	t_dvec3	w;

	if(!get_unitvector(-1, 1, 0, u))
		return (FALSE);
	if(!get_unitvector(1, 1, -2, v))
		return (FALSE);
	if(!get_unitvector(-1, -1 , -1 , w))
		return (FALSE);
	if(!tranformation_33mat(mat, u, v, w))
		return (FALSE);
	return(TRUE);
}