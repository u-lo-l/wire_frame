#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

/*utils*/
int	my_strlen(char *str);
char	*my_strndup(char *str, int size);
int	my_atoi(char *str, int *errer_check);

/*args*/
int	count_args(char *str);
char	**split_args(int argc, char *str);


/*main function*/
char	*push_swap(int argc, char **argv);


#endif
