/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:04:46 by sde-silv          #+#    #+#             */
/*   Updated: 2023/07/12 17:07:54 by sde-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_ptr(unsigned long int nbr, int format)
{
	int	digits;

	if (nbr == 0)
		return (print_str("(nil)"));
	else
	{
		digits = write (1, "0x", 2);
		return (digits + print_hex(nbr, format));
	}
}
