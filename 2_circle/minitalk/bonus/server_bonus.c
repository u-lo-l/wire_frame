#include "minitalk_bonus.h"
#include <stdio.h>

void putnum_binary(unsigned int nbr)
{
	char arr[32] = {};
	int i = 32;

	while (--i >= 0)
	{
		arr[i] = (nbr & 1) + '0';
		nbr >>= 1;
	}
	write(1, "bi : ", 5);
	while (i < 32)
	{
		write(1, (arr + i), 1);
		if (i % 4 == 3)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int main()
{
	sigset_t	set;

	sigemptyset(&set);
	printf("%u\n", set);
	putnum_binary(set);
	
	sigaddset(&set, SIGUSR1);
	printf("%u\n", set);
	putnum_binary(set);

	sigaddset(&set, SIGUSR2);
	printf("%u\n", set);
	putnum_binary(set);
}
