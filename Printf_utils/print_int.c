#include "../ft_printf.h"

static void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

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

int print_int(int ret)
{
	int			digits;
	long int	nbr;

	nbr = ret;
	digits = count_digits(nbr);
	ft_putnbr_fd(nbr, 1);
	return (digits);
}
