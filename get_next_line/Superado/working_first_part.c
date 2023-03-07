/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_protA.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:26:47 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/20 10:19:43 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 5

char	*ft_reader(int fd)
{
	int					ret;
	char				*read_buff;

	read_buff = (char *) malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (read_buff == NULL)
		return (NULL);
	ret = read(fd, read_buff, BUFFER_SIZE);
	read_buff[ret + 1] = '\0';
	printf("%d\n", ret);
	return (read_buff);
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

char	*ft_freeup(char *stash, int i)
{
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
	ft_freeup(stash, (i + n));
	return (a);
}

char	*get_next_line(int fd)
{	
	char			*read_buff;
	static char		*stash;

	read_buff = ft_reader(fd);
	if (stash == NULL)
		stash = ft_stash_initializer(read_buff, stash);
	else
		stash = ft_stash_store(read_buff, stash);
	return (stash);
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
