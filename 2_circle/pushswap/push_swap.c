#include "push_swap.h"


/*
 * main함수에서 처리할 것.
 * 1) 들어온 인자가 유효한가?
 * 
 */
#include <stdio.h>
int main(int argc, char *argv[])
{
	char	*actions;
	int		error_check;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		argc = count_args(argv[1]);
		argv = split_args(argc, argv[1]);
	}
	else
	{
		argc--;
		argv++;
	}
	error_check = 0;
	int i = 0;
	int temp;
	while (i < argc)
	{
		temp = my_atoi(argv[i], &error_check);
		if (error_check == 1)
		{
			// write(2,"Error\n", 6);
			printf("Error\n");
			exit(1);
		}
		// temp = atoi(argv[i]);
		printf("%d\n", temp);
		i++;
	}
	// actions = push_swap(int argc, char **argv);
	return (0);
}
