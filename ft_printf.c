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

size_t  check_specifier(const char *str, size_t i, va_list ap)
{
    if (str[i + 1] == 's')
        return (print_str(ap));
    else if (str[i + 1] == '%')
    {
        write (1, "%", 1);
        return (1);
    }
    else if (str[i + 1] == 'c')
        return (print_chr(ap));
    else if (str[i + 1] == 'd' || str[i + 1] == 'i')
        return (print_int(ap));
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
    while (i < ft_strlen(str))
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