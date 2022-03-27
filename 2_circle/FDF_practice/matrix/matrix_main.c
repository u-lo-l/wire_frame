#include "matrix.h"

void	print_matrix(t_matrix *matrix)
{
	if (!matrix)
		return ;
	printf("MAT : %d x %d\n", matrix->dim[0], matrix->dim[1]);
	for (int r = 0; r < matrix->dim[0] ; r++, printf("\n"))
		for(int c = 0; c < matrix->dim[1] ; c++)
			printf(" %+5.2f", matrix->mat[c][r]);
}


int main()
{
	t_matrix	*Rot_O2V;
	t_matrix	*Rot_V2O;

	Rot_O2V = init_matrix(3, 3);

	Rot_O2V->mat[0][0] = -1 / sqrt(2);
	Rot_O2V->mat[0][1] = 1 / sqrt(2);
	Rot_O2V->mat[0][2] = 0;

	Rot_O2V->mat[1][0] = 1 / sqrt(6);
	Rot_O2V->mat[1][1] = 1 / sqrt(6);
	Rot_O2V->mat[1][2] = -2 / sqrt(6);

	Rot_O2V->mat[2][0] = -1 / sqrt(3);
	Rot_O2V->mat[2][1] = -1 / sqrt(3);
	Rot_O2V->mat[2][2] = -1 / sqrt(3);

	t_matrix	*v_vec = init_3d_vec(1, 0, 0);
	t_matrix	*o_vec = mat_mul(Rot_O2V, v_vec);
	print_matrix(o_vec);
	destroy_matrix(v_vec);
	destroy_matrix(o_vec);

	// Rot_V2O = mat_inverse(Rot_O2V);
	Rot_V2O = mat_transpose(Rot_O2V);
	print_matrix(Rot_V2O);
	o_vec = init_3d_vec(-1/sqrt(2), 1/sqrt(2), 0);
	print_matrix(o_vec);
	v_vec = mat_mul(Rot_V2O, o_vec);
	print_matrix(v_vec);

}