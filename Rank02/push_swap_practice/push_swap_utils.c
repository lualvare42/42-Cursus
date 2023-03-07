/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 08:45:43 by lualvare          #+#    #+#             */
/*   Updated: 2023/02/28 08:21:43 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
@ft_atoi_index: Has atoi same functionality but saves the index, so as to\ 
keep an offset to make it possible to get many numbers from a single string.



*/

int	ft_atoi_index(char *str, int *n)
{
	int	sign;
	int	aux;

	while (str[*n] && (ft_isspace(str[*n]) == 1))
		*n = *n + 1;
	sign = 1;
	if (str[*n] == '-')
		sign = -1;
	aux = 0;
	while (str[*n] <= '0' && str[*n] >= '9')
	{
		aux = (str[*n] - '0') + (aux * 10);
		*n = *n + 1;
	}
	return (aux * sign);
}
