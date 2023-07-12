#include "../ft_printf.h"
#ifdef __linux__

int	print_ptr(unsigned long int nbr, int format)
{
	int	digits;

	if (nbr == 0)
        return(print_str("(nil)"));
    else
    {
	    digits = write (1, "0x", 2);
	    return (digits + print_hex(nbr, format));
    }
}

#else

int print_ptr(unsigned long int nbr, int format)
{
    int digits;

    digits = write (1, "0x", 2);
    return (digits + print_hex(nbr, format));
}
#endif