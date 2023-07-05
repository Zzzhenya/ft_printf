#include "libftprintf.h"

static int	count_digits(int n)
{
	int			count;
	long int	nb;

	count = 0;
	nb = n;
	if (nb <= 0)
	{
		count ++;
		nb = nb * -1;
	}
	while (nb)
	{
		nb = nb / 10;
		count ++;
	}
	return (count);
}

static char	*ft_itoa(int n)
{
	char		*ptr;
	int			digits;
	long int	nbr;

	digits = count_digits(n);
	nbr = n;
	ptr = malloc(sizeof(char) * digits + 1);
	if (!ptr)
		return (NULL);
	ptr[digits] = '\0';
	if (nbr < 0)
		nbr = nbr * -1;
	while (digits > 0)
	{
		digits --;
		ptr[digits] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		ptr[digits] = '-';
	return (ptr);
}

size_t count_print_d(va_list ap)
{
    int    ret;
    int     len;

    ret = va_arg(ap, int);
    len = count_digits(ret);
    write(1, ft_itoa(ret), sizeof(int) * len);
    return (len);
}