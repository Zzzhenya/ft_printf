#include "../ft_printf.h"

size_t print_chr(va_list ap)
{
    int    ret;
    char    c;

    ret = va_arg(ap, int);
    if (ret)
    {
        c = (char)ret;
        return(write(1, &c, sizeof(char)));
    }
    return (1);
}