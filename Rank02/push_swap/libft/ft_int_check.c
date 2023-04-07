/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:20:53 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/15 09:55:28 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_check(char **s)
{
	int	i;
	int	k;

	i = 1;
	while (s[i])
	{
		k = 0;
		while (s[i][k])
		{
			if (ft_isint(ft_latoi_index(s[i], &k)) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
