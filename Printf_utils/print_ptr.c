#include "../ft_printf.h"
//#include <stdio.h>

/*
 o, u, x, X
              The unsigned int argument is converted to unsigned octal
              (o), unsigned decimal (u), or unsigned hexadecimal (x and
              X) notation.  The letters abcdef are used for x
              conversions; the letters ABCDEF are used for X
              conversions.  The precision, if any, gives the minimum
              number of digits that must appear; if the converted value
              requires fewer digits, it is padded on the left with
              zeros.  The default precision is 1.  When 0 is printed
              with an explicit precision 0, the output is empty.

*/

int print_ptr(unsigned long int nbr, int format)
{
	int			digits;

    digits = write (1, "0x", 2);
	digits = digits + print_hex(nbr, format);
	return (digits);
}
