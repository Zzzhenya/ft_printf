#include <stdio.h>
#include "libftprintf.h"
//int ft_printf(const char *str, ...);

int main(void)
{
	printf("Ft: %d\n", ft_printf("Hello!%sA%%BB", "World!"));
	printf("Or: %d\n", printf("Hello!%sA%%BB", "World!"));
	int width = 5;
	int num = 10;
	printf("%*d\n", width, num);
	printf("%2$*1$d\n", width, num);
	return (0);
}