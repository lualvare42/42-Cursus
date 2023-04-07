/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:45:17 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/13 16:11:33 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr_u(unsigned int n, int *i)
{
	if (n > 9)
	{
		ft_print_nbr_u((n / 10), i);
		ft_print_nbr_u((n % 10), i);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
		*i = *i + 1;
	}
}

void	ft_print_unsigned(va_list ap, int *i)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	ft_print_nbr_u(n, i);
}
