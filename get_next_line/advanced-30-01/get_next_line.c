/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:26:47 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/31 09:08:03 by lualvare         ###   ########.fr       */
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
			while ((n + 1) <= ft_strlen(stash))
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
	int		n;
	int		i;
	char	*aux;

	n = ft_line_check(stash);
	aux = (char *) malloc(sizeof(char) * (n + 2));
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (i <= n)
	{
		aux[i] = stash[i];
		i++;
	}
	aux[n + 1] = '\0';
	stash = ft_strdup(aux);
	free(aux);
	return (stash);
}

char	*ft_free(char *stash, char *read_buff)
{
	char	*aux;

	aux = ft_strjoin(stash, read_buff);
	free(stash);
	return (aux);
}

char	*ft_stasher(int fd)
{
	char		*read_buff;
	static char	*stash;
	char		*aux;
	int			ret;

	ret = 1;
	while (ret != 0)
	{
		read_buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (read_buff == NULL)
			return (NULL);
		ret = read(fd, read_buff, BUFFER_SIZE);
		read_buff[ret] = '\0';
		stash = ft_free(stash, read_buff);
		free(read_buff);
		if (ft_line_check(stash) >= 0)
		{
			aux = ft_line_seek(stash);
			stash = ft_lead_saver(stash);
			return (aux);
		}
	}
	aux = ft_strdup(stash);
	free(stash);
	stash = NULL;
	return (aux);
}

char	*get_next_line(int fd)
{
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	else if (read(fd, 0, 0) < 0)
		return (NULL);
	return (ft_stasher(fd));
}

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDWR);
	//fd = open("empty.txt", O_RDWR);
	//fd = 0;
	//printf("%d\n", fd);
	printf("1%s", get_next_line(fd));
	printf("2%s", get_next_line(fd));
	printf("3%s", get_next_line(fd));
	printf("4%s", get_next_line(fd));
	printf("5%s", get_next_line(fd));
	printf("6%s", get_next_line(fd));
	return (0);
}
