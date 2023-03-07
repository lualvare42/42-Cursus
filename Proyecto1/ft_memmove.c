/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:37:14 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/07 10:10:20 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst,	const void *src, size_t	len)
{
	size_t			n;

	if (dst == NULL && src == NULL)
		return (0);
	if ((dst > src) && (len != 0))
	{
		n = len - 1;
		while ((int)n >= 0)
		{
			*(char *)(dst + n) = *(char *)(src + n);
			n--;
		}
	}	
	else
	{
		n = 0;
		while (n < len)
		{
			*(char *)(dst + n) = *(char *)(src + n);
			n++;
		}
	}
	return (dst);
}
