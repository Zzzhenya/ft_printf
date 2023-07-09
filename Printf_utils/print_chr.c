#include "../ft_printf.h"

int print_chr(va_list ap)
{
    int    ret;
    unsigned char    c;

    ret = va_arg(ap, int);
    c = (unsigned char)ret;
    return(write(1, &c, sizeof(char)));
}