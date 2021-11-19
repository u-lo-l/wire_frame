#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bsd/string.h>

// void    *ft_memset(void *s, int c, size_t n);
// void    *ft_memcpy(void *dest, const void *src, size_t n);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);

char str1[10] = "aaaaaaaaa";
char str2[7] = "ABCEDF";
char dest[] = "";
char fest[] = "";
char *src = NULL;

int main()
{
    strlcpy(str1, str2, 3);
    printf("%s\n", str1);
}