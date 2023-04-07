/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_inarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:24:14 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/05 14:58:23 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks for duplicates in an int array
 * 
 * @param input 
 * @return int 
 */

int	ft_dup_inarray(int *input, int size)
{
	int	n;
	int	i;

	n = 0;
	while (n < size - 1)
	{
		i = n + 1;
		while (i < size)
		{
			if (input[i] == input[n])
				return (1);
			i++;
		}
		n++;
	}
	return (0);
}
