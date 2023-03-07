/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:37:14 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/02 11:21:08 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;

	if (dstsize != 0)
	{
		n = 0;
		while (src[n] && (n < dstsize - 1))
		{
			dst[n] = src[n];
			n++;
		}
		dst[n] = '\0';
	}	
	return (ft_strlen(src));
}
