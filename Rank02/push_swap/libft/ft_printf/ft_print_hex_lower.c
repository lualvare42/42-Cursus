/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:45:17 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/24 12:24:15 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr_base_l(unsigned int nbr, char *base, int *i)
{
	if (nbr >= 16)
	{
		ft_print_nbr_base_l(nbr / 16, base, i);
		ft_print_nbr_base_l(nbr % 16, base, i);
	}
	else if (nbr < 16)
	{
		write(1, &base[nbr], 1);
		*i = *i + 1;
	}
}

void	ft_print_hex_lower(va_list ap, int *i)
{
	unsigned int	nbr;

	nbr = (unsigned int)va_arg(ap, int);
	ft_print_nbr_base_l(nbr, "0123456789abcdef", i);
}
