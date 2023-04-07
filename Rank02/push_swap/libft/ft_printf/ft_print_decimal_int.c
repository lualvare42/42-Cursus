/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:45:17 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/13 16:11:33 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int n, int *i)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
		*i = *i + 2;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		*i = *i + 1;
	}
	if (n > 9)
	{
		ft_print_nbr((n / 10), i);
		ft_print_nbr((n % 10), i);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
		*i = *i + 1;
	}
}

void	ft_print_decimal_int(va_list ap, int *i)
{
	int		n;

	n = va_arg(ap, int);
	ft_print_nbr(n, i);
}
