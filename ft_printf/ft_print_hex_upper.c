/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:45:17 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/13 17:43:26 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr_base_u(unsigned int nbr, char *base, int *i)
{
	if (nbr >= 16)
	{
		ft_print_nbr_base_u(nbr / 16, base, i);
		ft_print_nbr_base_u(nbr % 16, base, i);
	}
	else
	{
		write(1, &base[nbr], 1);
		*i = *i + 1;
	}
}

void	ft_print_hex_upper(va_list ap, int *i)
{
	unsigned int	nbr;

	nbr = (unsigned int)va_arg(ap, void *);
	ft_print_nbr_base_u(nbr, "0123456789ABCDEF", i);
}
