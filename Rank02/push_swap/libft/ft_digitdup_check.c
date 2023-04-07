/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitdup_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:49:59 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/14 21:11:10 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digitdup_check(char *s1, char *s2)
{
	int	i;
	int	n;

	i = 0;
	while (s1[i])
	{
		n = 0;
		while (s2[n])
		{
			if (s2[n] == s1[i] && ft_isdigit(s2[n]) == 1)
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}
