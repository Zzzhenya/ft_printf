#include "../ft_printf.h"

static int	hex_len(unsigned long int num)
{
	long int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	if (len == 0)
	    return (1);
	return (len);
}

static void	ft_put_hex(unsigned long int num, int format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num < 10)
			print_chr(num + '0');
		else
		{
			if (format == 'x' || format == 'p')
				print_chr(num - 10 + 'a');
			else if (format == 'X')
				print_chr(num - 10 + 'A');
		}
	}
}

int print_hex(unsigned long int nbr, int format)
{
    ft_put_hex(nbr, format);
	return (hex_len(nbr));
}