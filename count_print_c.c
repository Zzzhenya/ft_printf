#include "libftprintf.h"

size_t count_print_c(va_list ap)
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