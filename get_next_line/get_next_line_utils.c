/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:35:57 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/31 12:13:25 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

int	ft_line_check(char *stash)
{
	int	n;

	n = 0;
	if (stash == NULL)
		return (-1);
	while (stash[n])
	{
		if (stash[n] == '\n')
			return (n);
		n++;
	}
	return (-1);
}

char	*ft_strjoin_mod(char const *stash, char const *read_buff)
{
	char	*a;
	size_t	n;
	size_t	i;
	size_t	j;

	if ((read_buff[0] == '\0') && (stash == NULL))
		return (NULL);
	else if (stash == NULL)
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
	return (a);
}
