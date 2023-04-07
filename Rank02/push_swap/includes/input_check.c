/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:38:15 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/05 11:39:22 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief
	This set of functions guarantee the correct formatting of the input the 
	push_swap program gets.
 * @ft_num_len_check: 
 	Ensures input has just int, spaces, and/or signs (±)
		@return
			- 1, TRUE.
			- 0, FALSE.
 * @ft_blank_check: 
 	Ensures input is not just a blank string.
		@return
			- 1, TRUE (at least one ARG is a blank string).
			- 0, FALSE.
 * @ft_strlen: 
 	Ensures input is not an empty string.
		@return
			- > 0, OK 
			- 0, KO (at least one ARG is an empty).
 * @ft_int_check: 
 	Ensures that input has only int sized numbers.
		@return
			- 1, OK 
			- 0, KO (at least one number has incorrect size).
 * @param argc 
 * @param s 
 * @return int 
 */

int	ft_num_len_check(char *s)
{
	int	n;

	n = 0;
	while ((ft_int(s[n]) == 1 || ft_isspace(s[n]) == 1) && ft_sign(s) == 1)
		n++;
	if (n == (int)ft_strlen(s))
		return (1);
	return (0);
}

int	ft_blank_check(char *s)
{
	int	n;

	n = 0;
	while (ft_isspace(s[n]) == 1)
		n++;
	if (n == (int)ft_strlen(s))
		return (1);
	return (0);
}

int	ft_input_check(int argc, char **s)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (ft_num_len_check(s[i]) == 0)
			return (0);
		else if (ft_blank_check(s[i]) == 1)
			return (0);
		else if (ft_strlen(s[i]) == 0)
			return (0);
		i++;
	}
	if (ft_int_check(s) == 0)
		return (0);
	return (1);
}
