/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:48:08 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/15 07:53:40 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s, char c)
{
	int	n;

	n = 0;
	while ((s[n] == c) && s[n])
		n++;
	return (n);
}

int	ft_count_c(char const *s, char c)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (i < (int)ft_strlen(s))
	{
		if ((s[i] != c) && ((i == 0) || (s[i - 1] == c)))
			n = n + 1;
		i++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		n;
	int		i;
	int		k;

	a = (char **) malloc(sizeof(char *) * (ft_count_c(s, c) + 1));
	if (a == NULL)
		return (NULL);
	n = ft_start(s, c);
	i = 0;
	k = n;
	while ((n <= (int)ft_strlen(s)) && (ft_strlen(s) != 0))
	{
		if (((s[n] == c) && (s[n - 1] != c)) || ((!s[n]) && (s[n - 1] != c)))
		{
			a[i] = ft_substr(s, (size_t)k, (size_t)(n - k));
			k = n + ft_start((s + n), c);
			i++;
		}
		n++;
	}
	a[i] = NULL;
	return (a);
}
