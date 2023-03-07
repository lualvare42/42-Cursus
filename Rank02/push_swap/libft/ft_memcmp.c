/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:37:14 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/05 12:56:05 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			n;
	unsigned char	*ba;
	unsigned char	*bb;

	ba = (unsigned char *)b1;
	bb = (unsigned char *)b2;
	n = 0;
	while (n < len)
	{
		if (ba[n] != bb[n])
			return ((int)ba[n] - (int)bb[n]);
		n++;
	}
	return (0);
}
