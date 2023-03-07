/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:35:57 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/24 11:39:02 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_head.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

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

int	ft_line_check(char *stash)
{
	int	n;

	n = 0;
	while (stash[n])
	{
		if (stash[n] == '\n')
			return (n);
		n++;
	}
	return (0);
}

char	*ft_strjoin(char const *stash, char const *read_buff)
{
	char	*a;
	size_t	n;
	size_t	i;
	size_t	j;

	if (stash == NULL)
		stash = "";
	i = ft_strlen(stash);
	j = ft_strlen(read_buff);
	a = (char *) malloc(sizeof(char) * (i + j + 1));
	if (a == NULL)
		return (NULL);
	n = 0;
	while (n <= i + j)
	{
		if (n < i)
			a[n] = stash[n];
		else
			a[n] = read_buff[n - i];
		n++;
	}
	//free((void *)read_buff);
	return (a);
}
