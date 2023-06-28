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

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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

int ft_printf(const char *str, ...)
{
    va_list arg_ptr;
    int     i;
    int     ret;
    char    *ret_str;

    i = 0;
    ret = 0;
    va_start(arg_ptr, str);
    while (i < strlen(str))
    {
        if (str[i] == '%' )
        {
            i = i + 2; 
            ret_str = va_arg(arg_ptr, char *);
            ft_putstr_fd(ret_str, 1);
            ret = ret + strlen(ret_str);
        }
        else
            ret = ret + write(1, &str[i], 1);
        i++;
    }
    va_end(arg_ptr);    
    return (ret);
}