/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:26:47 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/23 10:10:19 by lualvare         ###   ########.fr       */
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
		if (stash[n] == '\n')
		{
			aux = (char *) malloc(sizeof(char) * (ft_strlen(stash) - n + 1));
			if (aux == NULL)
				return (NULL);
			i = 0;
			while (n <= ft_strlen(stash))
			{
				aux[i] = stash[n + 1];
				i++;
				n++;
			}
			free(stash);
			return (aux);
		}
		n++;
	}
	return (NULL);
}

char	*ft_line_seek(char *stash)
{
	size_t		n;
	size_t		i;
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
			return (aux);
		}
		n++;
	}
	return (NULL);
}

char	*ft_reader(char *read_buff, int fd)
{
	char	*aux;
	int		ret;

	ret = 1;
	while (ret != 0)
	{
		read_buff = (char *) malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		if (read_buff == NULL)
			return (NULL);
		ret = read(fd, read_buff, BUFFER_SIZE);
		read_buff[ret + 1] = '\0';
		stash = ft_strjoin(stash, read_buff);
		if (ft_line_seek(stash) != NULL)
		{
			aux = ft_line_seek(stash);
			stash = ft_lead_saver(stash);
			return (aux);
		}
		free(read_buff);
	}
	return (stash);
}

char	*ft_stash_initializer(char *read_buff, char *stash)
{
	int	n;

	n = 0;
	while (read_buff[n])
		n++;
	stash = (char *) malloc(sizeof(char) * (n + 1));
	if (stash == NULL)
		return (NULL);
	while (n >= 0)
	{
		stash[n] = read_buff[n];
		n--;
	}
	free(read_buff);
	return (stash);
}

char	*ft_freeup(char *stash, char *read_buff, int i)
{
	free(read_buff);
	free(stash);
	stash = (char *) malloc(sizeof(char *) * (i + 1));
	if (stash == NULL)
		return (NULL);
	return (stash);
}

char	*ft_stash_store(char *read_buff, char *stash)
{
	char	*a;
	int		n;
	int		i;
	int		j;

	n = 0;
	while (read_buff[n])
		n++;
	i = 0;
	while (stash[i])
		i++;
	a = (char *) malloc(sizeof(char *) * (n + i + 1));
	if (a == NULL)
		return (NULL);
	j = 0;
	while (j <= i + n)
	{
		if (j < i)
			a[j] = stash[j];
		else
			a[j] = read_buff[j - i];
		j++;
	}
	ft_freeup(stash, read_buff, (i + n));
	return (a);
}

char	*get_next_line(int fd)
{	
	char			*read_buff;
	static char		*stash;
	char			*new_line;

	if (stash == NULL)
		read_buff = ft_reader(fd);
	else
		stash = ft_stash_store(read_buff, stash);
	new_line = ft_line(stash, fd);
	return (new_line);
}

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
	return (0);
}
