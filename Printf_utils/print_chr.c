#include "../ft_printf.h"

int	print_chr(int ret)
{
	unsigned char	c;

	c = (unsigned char)ret;
	return (write (1, &c, sizeof(char)));
}
