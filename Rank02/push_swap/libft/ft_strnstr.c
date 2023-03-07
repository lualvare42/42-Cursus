/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:37:14 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/05 09:42:14 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	n;
	size_t	i;

	n = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[n] && (n < len))
	{
		i = 0;
		while ((big[n + i] == little[i]) && (big[n + i]) && (n + i < len))
		{
			i++;
			if (little[i] == '\0')
				return ((char *) &big[n]);
		}
		n++;
	}
	return (0);
}
