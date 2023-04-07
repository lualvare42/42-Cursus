/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:31:58 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/05 14:19:02 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief 
	This set of functions help generate an array of int that will work to check
	if the input has any duplicates, and later on it will be used to copy each 
	int into a circular linked list.
 * 
 * @ft_input_read:
	Allocates total_elements of memory for an array of int.
		@return
			- Created array of int.
 * @ft_int_array:
	Copies ints from input into an array.
 * @ft_num_qty:
	Determines the amount of ints in input.
 * @ft_qty:
	Determines the amount of ints within each ARG of input.
 */

int	ft_qty(char *s)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[n])
	{
		if ((ft_int(s[n]) == 1) && (n == 0 || ft_isspace(s[n - 1]) == 1))
			i++;
		n++;
	}
	return (i);
}

int	ft_num_qty(int argc, char **s)
{
	int	i;
	int	n;
	int	aux;

	i = 1;
	aux = 0;
	while (i <= argc - 1)
	{
		n = ft_qty(s[i]);
		aux = aux + n;
		i++;
	}
	return (aux);
}

void	ft_int_array(char **s, int *input)
{
	int	n;
	int	i;
	int	k;

	n = 0;
	i = 1;
	while (s[i])
	{
		k = 0;
		while (s[i][k] && (ft_blank_check(&s[i][k]) == 0))
		{
			input[n] = ft_atoi_index(s[i], &k);
			n++;
		}
		i++;
	}
}

int	*ft_input_read(char **s, int total_elements)
{
	int	*input;

	input = (int *) malloc(sizeof(int) * total_elements);
	if (input == 0)
		return (0);
	ft_int_array(s, input);
	return (input);
}
