/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:37:14 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/07 10:25:09 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest,	int c, size_t len)
{
	size_t	n;

	n = 0;
	while (n < len)
	{
		*(char *)(dest + n) = (unsigned char)c;
		n++;
	}
	return (dest);
}
