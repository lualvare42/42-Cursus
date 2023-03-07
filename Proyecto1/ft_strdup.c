/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:07:47 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/07 13:48:36 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*a;
	size_t	n;

	a = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (a == NULL)
		return (NULL);
	n = 0;
	while (*(char *)(str + n))
	{
		a[n] = *(char *)(str + n);
		n++;
	}
	a[n] = '\0';
	return (a);
}
