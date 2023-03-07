/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:26:47 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/31 12:27:58 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_lead_saver(char *stash)
{
	size_t		n;
	size_t		i;
	char		*aux;

	n = 0;
	while (stash[n])
	{
		if ((stash[n] == '\n') && (stash[n + 1] != '\0'))
		{
			aux = (char *) malloc(sizeof(char) * (ft_strlen(stash) - n + 1));
			if (aux == NULL)
				return (NULL);
			i = 0;
			while ((n + 1) <= ft_strlen(stash))
			{
				aux[i++] = stash[n++ + 1];
			}
			free(stash);
			return (aux);
		}
		n++;
	}
	free(stash);
	return (NULL);
}

char	*ft_line_seek(char *stash)
{
	int		n;
	int		i;
	char	*aux;

	if (ft_line_check(stash) >= 0)
		n = ft_line_check(stash) + 1;
	else
		n = ft_strlen(stash);
	aux = (char *) malloc(sizeof(char) * (n + 1));
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		aux[i] = stash[i];
		i++;
	}
	aux[n] = '\0';
	return (aux);
}

char	*ft_free(char *stash, char *read_buff)
{
	char	*aux;

	aux = ft_strjoin_mod(stash, read_buff);
	free(stash);
	return (aux);
}

char	*ft_stasher(int fd, char *stash, int *ret)
{
	char		*read_buff;

	read_buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buff == NULL)
		return (NULL);
	while (*ret != 0)
	{
		*ret = read(fd, read_buff, BUFFER_SIZE);
		if (*ret == -1)
		{
			free(read_buff);
			free(stash);
			return (NULL);
		}
		read_buff[*ret] = '\0';
		stash = ft_free(stash, read_buff);
		if (ft_line_check(stash) >= 0)
		{
			free(read_buff);
			return (stash);
		}
	}
	free(read_buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*aux;
	int			ret;

	ret = 1;
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	stash = ft_stasher(fd, stash, &ret);
	if (stash == NULL)
		return (NULL);
	aux = ft_line_seek(stash);
	stash = ft_lead_saver(stash);
	return (aux);
}
