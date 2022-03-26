#include <mlx.h>

int main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if(!(mlx_win = mlx_new_window(mlx, 800, 450, "HI!")))
		return 0;
	mlx_loop(mlx);
}