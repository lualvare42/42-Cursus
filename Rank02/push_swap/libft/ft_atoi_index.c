/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:29:09 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/14 21:37:14 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief as the atoi its purpose is taking a string and turn it into an int,
 but it is able to retrieve all the numbers within a single string even if 
 they are separate numbers.

 This function is to be used within a loop ir order to retrieve all the 
 numbers from a string.
 * 
 * @param str the string where to look for ints
 * @param n the index, that mark the beginning and end of each number
 * @return int
 */

int	ft_atoi_index(char *str, int *n)
{
	int	sign;
	int	aux;

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
