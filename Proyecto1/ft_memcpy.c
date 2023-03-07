/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:37:14 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/05 13:27:02 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src,	size_t len)
{
	size_t			n;

	if (dst == NULL && src == NULL)
		return (0);
	else if (len != 0)
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
