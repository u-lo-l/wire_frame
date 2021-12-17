#include "ft_printf.h"
#include <stdio.h>
int main()
{
	int a = 123456789;

	ft_printf("%d\n",10);
	printf("%d\n", 10);
	printf("===========================\n");
	ft_printf("%d\n",-10000);
	printf("%d\n",-10000);
	printf("===========================\n");
	ft_printf("%x\n",100);
	printf("%x\n", 100);
	// printf("===========================\n");
	// ft_printf("%X\n", 500);
	// printf("%X\n", 500);
	printf("===========================\n");
	ft_printf("%p\n",&a);
	printf("%p\n",&a);
	printf("===========================\n");
	ft_printf("%s\n","SIMPLE STRING\nSAMPLE STRING");
	printf("%s\n","SIMPLE STRING\nSAMPLE STRING");
	// printf("===========================\n");
	// ft_printf("%c\n",'c');
	// printf("%c\n",'c');
	// printf("===========================\n");
	// ft_printf("%u\n",a);
	// printf("%u\n",a);
	// printf("===========================\n");
	// ft_printf("%i\n",-a);
	// printf("%i\n",-a);
	// printf("===========================\n");
	// ft_printf("%d\n",a);
	// printf("%d\n",a);
	// printf("===========================\n");
	// ft_printf("%s\n","T");
	// printf("%s\n","T");
	// printf("===========================\n");
	// ft_printf("%x\n",a);
	// printf("%x\n",a);
}