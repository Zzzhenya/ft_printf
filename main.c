#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int ft_printf(const char *, ...);

int main(void)
{
	printf("Ft: %d\n", ft_printf("Hello!"));
	printf("Or: %d\n", printf("Hello!"));
	return (0);
}

int ft_printf(const char *str, ...)
{
    va_list arg_ptr;
    int     i;

    i = 0;
    va_start(arg_ptr, str);
    while (i < strlen(str))
    {
        write(1, &str[i], 1);
        i ++;
    }
    va_end(arg_ptr);    
    return (i);
}