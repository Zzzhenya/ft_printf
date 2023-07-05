#include "libftprintf.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i ++;
	}
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len ++;
	return (len);
}

size_t count_print_s(va_list ap)
{
    char    *ret_str;

    ret_str = va_arg(ap, char *);
    ft_putstr_fd(ret_str, 1);
    return (ft_strlen(ret_str));
}