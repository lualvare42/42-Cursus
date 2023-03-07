/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 07:45:17 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/13 18:19:21 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(va_list ap, int *i)
{
	int		n;
	char	*str;

	n = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*i = *i + 6;
	}
	while ((str != NULL) && str[n])
	{
		write(1, &str[n], 1);
		n++;
	}
	*i = *i + n;
}
