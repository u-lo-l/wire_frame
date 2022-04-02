#include "../INC/fdf.h"

void	print_queue(t_queue *queue)
{
	t_qnode	*curr; 

	if (!queue)
		return ;
	curr = queue->pfront;
	while (curr != NULL)
	{
		printf("Z : %d C : %#X\n", curr->data[0], curr->data[1]);
		curr = curr->next;
	}
}

void	print_orgmap(t_inputmap *org)
{
	int	x;
	int	y;
	int	r;
	int	g;
	int	b;

	x = -1;
	while (++x < org->sizeof_x)
	{
		y = -1;
		while (++y < org->sizeof_y)
		{
			r = (org->arr[x][y][1] & 0XFF0000) >> 16;
			g = (org->arr[x][y][1] & 0X00FF00) >> 8;
			b = (org->arr[x][y][1] & 0X0000FF);
			printf("\033[38;2;%d;%d;%dm [% 3d]\033[0m", r, g, b, org->arr[x][y][0]);
		}
		printf("\n\n");
	}
}

void print_33mat(t_33mat mat)
{
	int	i = 0;
	while (i < 3)
	{
		int j = 0;
		while (j < 3)
		{
			printf(" %3.2f", mat[j][i]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void print_dvec3(t_dvec3 vec3)
{
	printf("%3.2f\n%3.2f\n%3.2f\n", vec3[X], vec3[Y], vec3[Z]);
}

void		print_output_map(t_outputmap *map)
{
	// int	x;
	// int	y;

	if (!map)
		return ;
	printf("ARR SIZE\n");
	printf("Y(width) : %d X(height) : %d\n", map->sizeof_y, map->sizeof_x);
	printf("VIEW POS MAX & MIN\n");
	printf("(y,x) | (%3.2f,% 3.2f)~(%3.2f,%3.2f)\n", map->minpoint[Y], map->minpoint[X], \
			map->maxpoint[Y], map->maxpoint[X]);
	printf("Y OFFSET : %d X_OFFSET %d\n", map->offset[Y], map->offset[X]);
	printf("SCALER : %3.2f\n", map->scaler);
	// x = -1;
	// while (++x < map->sizeof_x)
	// {
	// 	y = -1;
	// 	while (++y < map->sizeof_y)
	// 		printf("(%3.2f %3.2f | %#x)", map->map[x][y][0], map->map[x][y][1], (int)map->map[x][y][2]);
	// 	printf("\n");
	// }
	return ;
}