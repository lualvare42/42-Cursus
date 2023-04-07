/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:29:09 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/17 11:56:03 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Same as atoi_index but long long is used in order to check if any 
 number is larger than an int
 * 
 * @param str the string where to look for ints
 * @param n the index, that mark the beginning and end of each number
 * @return int
 */

long long	ft_latoi_index(char *str, int *n)
{
	int			sign;
	long long	aux;

	while (str[*n] && (ft_isspace(str[*n]) == 1))
		*n = *n + 1;
	sign = 1;
	if (str[*n] == '-')
	{
		*n = *n + 1;
		sign = -1;
	}
	if (str[*n] == '+')
		*n = *n + 1;
	aux = 0;
	while (str[*n] >= '0' && str[*n] <= '9')
	{
		aux = (str[*n] - '0') + (aux * 10);
		*n = *n + 1;
	}
	return (aux * sign);
}
