/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <sde-silv@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:13:54 by sde-silv          #+#    #+#             */
/*   Updated: 2023/06/08 14:43:57 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./Libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	print_str(char *next);
int	print_chr(int next);
int	print_int(int next);
int	print_uint(unsigned int next);
int	print_ptr(unsigned long int next, int format);
int	print_hex(unsigned long int next, int format);

#endif