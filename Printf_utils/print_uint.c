#include "../ft_printf.h"

static void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

static void	ft_putnbr_fd(unsigned long int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

static int	count_digits(unsigned int n)
{
	int					count;
	unsigned long int	nb;

	count = 0;
	nb = n;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		count ++;
	}
	return (count);
}

int	print_uint(unsigned int ret)
{
	int					digits;
	unsigned long int	nbr;

	nbr = ret;
	digits = count_digits(nbr);
	ft_putnbr_fd(nbr, 1);
	return (digits);
}
