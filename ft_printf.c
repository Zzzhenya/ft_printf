/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:46:29 by sde-silv          #+#    #+#             */
/*   Updated: 2023/06/28 14:46:34 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len ++;
	return (len);
}

static int	check_specifier(const char *str, int i, va_list ap)
{
	if (str[i + 1] == 's')
		return (print_str((char *)va_arg(ap, char *)));
	else if (str[i + 1] == '%')
		return (write (1, "%", 1));
	else if (str[i + 1] == 'c')
		return (print_chr(va_arg(ap, int)));
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
	    return (print_int(va_arg(ap, int)));
	else if (str[i + 1] == 'p')
		return (print_ptr(va_arg(ap, unsigned long int), str[i + 1]));
	else if (str[i + 1 ] == 'x' || str[i + 1 ] == 'X')
		return (print_hex((unsigned int)va_arg(ap, unsigned long int), str[i + 1]));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, str);
	while (i < (int)ft_strlen(str))
	{
		if (str[i] == '%')
			ret = ret + check_specifier(str, i++, ap);
		else
			ret = ret + write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}
