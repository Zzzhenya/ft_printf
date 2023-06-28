#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int ft_printf(const char *, ...);

int main(void)
{
	printf("Ft: %d\n", ft_printf("Hello!%s","World!"));
	printf("Or: %d\n", printf("Hello!%s","World!"));
	return (0);
}

int ft_printf(const char *str, ...)
{
    va_list arg_ptr;
    int     i;
    int     ret;
    char    *ret_str;

    i = 0;
    ret = 0;
    va_start(arg_ptr, str);
    while (i < strlen(str))
    {
        if (str[i] == '%' )
        {
            i = i + 2; 
            ret_str = va_arg(arg_ptr, char *);
            ft_putstr_fd(ret_str, 1);
            ret = ret + strlen(ret_str);
        }
        else
            ret = ret + write(1, &str[i], 1);
        i++;
    }
    va_end(arg_ptr);    
    return (ret);
}