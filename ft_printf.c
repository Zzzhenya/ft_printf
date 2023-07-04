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

#include <stdio.h>
#include <string.h>
#include "libftprintf.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i ++;
	}
}

size_t count_print_s(va_list ap)
{
    char    *ret_str;

    ret_str = va_arg(ap, char *);
    ft_putstr_fd(ret_str, 1);
    return (strlen(ret_str));
}

size_t check_specifier(const char *str, size_t i, va_list ap)
{
    if (str[i + 1] == 's')
    {
        return (count_print_s(ap));
    }
    else if (str[i + 1] == '%')
    {
        write (1, "%", 1);
        return (1);
    }
    else
        return (0);
}

int ft_printf(const char *str, ...)
{
    va_list     ap;
    size_t     i;
    size_t     ret;

    i = 0;
    ret = 0;
    va_start(ap, str);
    while (i < strlen(str))
    {
        if (str[i] == '%' )
        {
            ret = ret + check_specifier(str, i++, ap);
            i++;
        }
        else
        {
            ret = ret + write(1, &str[i], 1);
            i++;
        }
    }
    va_end(ap);    
    return (ret);
}