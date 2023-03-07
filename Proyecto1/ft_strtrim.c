/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:39:35 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/09 16:00:40 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_forward(char const *s1, char const *set)
{
	int	n;
	int	i;

	n = 0;
	while (s1[n])
	{
		i = 0;
		while ((s1[n] != set[i]) && (set[i]))
			i++;
		if (set[i] == '\0')
			return (n);
		n++;
	}
	return (n);
}

int	ft_backward(char const *s1, char const *set)
{
	int	n;
	int	i;

	n = (int)ft_strlen(s1) - 1;
	while (n >= 0)
	{
		i = 0;
		while ((s1[n] != set[i]) && (set[i]))
			i++;
		if (set[i] == '\0')
			return (n);
		n--;
	}
	return ((int)ft_strlen(s1));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	int		n;
	int		i;
	int		k;

	n = ft_forward(s1, set);
	i = ft_backward(s1, set);
	a = (char *) malloc(sizeof(char) * (i - n + 2));
	if (a == NULL)
		return (NULL);
	k = 0;
	while (n <= i)
	{
		a[k] = s1[n];
		n++;
		k++;
	}
	a[k] = '\0';
	return (a);
}
