/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:37:14 by lualvare          #+#    #+#             */
/*   Updated: 2023/02/28 13:12:28 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int	n;
	int	i;
	int	s;
	int	d;

	n = 0;
	i = (int)ft_strlen(dst);
	s = (int)ft_strlen(src);
	if ((int)dstsize < 0)
		d = i + s + 1;
	else
		d = (int)dstsize;
	if (d < i)
		return (d + s);
	while (src[n] && (n < (d - i - 1)))
	{
		dst[i + n] = src[n];
		n++;
	}
	dst[i + n] = '\0';
	return (i + s);
}
