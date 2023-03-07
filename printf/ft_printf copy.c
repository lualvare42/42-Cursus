/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:54:23 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/13 18:59:16 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_check(char c, va_list ap, int *i)
{
	if (c == 'c')
	{
		ft_print_char(ap);
		*i = *i + 1;
	}	
	else if (c == 's')
		ft_print_str(ap, i);
	else if (c == 'p')
		ft_print_memory(ap, i);
	else if ((c == 'd') || (c == 'i'))
		ft_print_decimal_int(ap, i);
	else if (c == 'u')
		ft_print_unsigned(ap, i);
	else if (c == 'x')
		ft_print_hex_lower(ap, i);
	else if (c == 'X')
		ft_print_hex_upper(ap, i);
	else if (c == '%')
	{
		write (1, "%", 1);
		*i = *i + 1;
	}
}

int	ft_printf(const char *s, ...)
{
	int		n;
	int		i;
	int		j;
	va_list	ap;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(ap, s);
	n = 0;
	i = 0;
	j = 0;
	while (s[n])
	{
		if (s[n] == '%')
		{
			ft_arg_check(s[n + 1], ap, &i);
			n = n + 2;
		}
		else
		{
			write(1, &s[n], 1);
			n++;
			j++;
		}
	}
	va_end(ap);
	return (i + j);
}
