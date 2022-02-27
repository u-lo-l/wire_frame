#include "ft_printf_bonus.h"
#include <stdio.h>

int main()
{
    printf("[printf]\n");
    printf("%020d\n",-8000);
    printf("%20d\n",-8000);
    printf("%#020x\n",8000);
    printf("%#20x\n",8000);
 
    ft_printf("[ft_printf]\n");
    ft_printf("%020d\n",-8000);
    ft_printf("%20d\n",-8000);
    ft_printf("%#020x\n",8000);
    ft_printf("%#20x\n",8000);
}