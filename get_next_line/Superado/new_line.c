/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:13:50 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/23 08:06:08 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_lead_saver(char *stash, int *n)
{
	char	*a;
	int		i;

	i = 0;
	while (stash[*n + i + 1])
		i++;
	a = (char *) malloc(sizeof(char *) * (i + 1));
	if (a == NULL)
		return (NULL);
	while (i >= 0)
	{
		a[i] = stash[*n + i + 1];
		i--;
	}
	while (a[i])
		i++;
	free(stash);
	return (a);
}

int	ft_null_seek(char *stash)
{
	int	n;

	n = 0;
	while (stash[n])
	{
		if (stash[n] == '\0')
			return (1);
		n++;
	}
	return (0);
}

char	*ft_line_seek(char *stash)
{
	int		n;
	int		i;
	char	*aux;

	n = 0;
	while (stash[n])
	{
		if (stash[n] == '\n')
		{
			aux = (char *) malloc(sizeof(char) * (n + 1));
			if (aux == NULL)
				return (NULL);
			i = 0;
			while (i <= n)
			{
				aux[i] = stash[i];
				i++;
			}
			aux[i] = '\0';
			stash = ft_lead_saver(stash, &n);
			return (aux);
		}
		n++;
	}
	return (NULL);
}

char	*ft_line(char *stash, int fd)
{	
	char	*aux;

	aux = ft_line_seek(stash);
	if (aux != NULL)
		return (aux);
	else
	{
		if (ft_null_seek(stash) == 1)
			return (stash);
		else
			ft_line(ft_stash_store(ft_reader(fd), stash), fd);
	}
	stash = ft_stash_store(ft_reader(fd), stash);
	if (ft_null_seek(stash) == 1)
		return (stash);
	ft_line_seek(read_buff, stash);
	return (NULL);
}
