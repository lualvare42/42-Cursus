/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:45:17 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/24 12:24:53 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr_base_m(unsigned long int nbr, char *base, int *i)
{
	if (nbr >= 16)
	{
		ft_print_nbr_base_m(nbr / 16, base, i);
		ft_print_nbr_base_m(nbr % 16, base, i);
	}
	else if (nbr < 16)
	{
		write(1, &base[nbr], 1);
		*i = *i + 1;
	}
}

void	ft_print_memory(va_list ap, int *i)
{
	unsigned long int	nbr;

	nbr = (long int)va_arg(ap, long int);
	write(1, "0x", 2);
	*i = *i + 2;
	ft_print_nbr_base_m(nbr, "0123456789abcdef", i);
}
