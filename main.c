#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int ft_printf(const char *str, ...);

int main(void)
{
	printf("Ft: %d\n", ft_printf("Hello!%s", "World!"));
	printf("Or: %d\n", printf("Hello!%s", "World!"));
	return (0);
}