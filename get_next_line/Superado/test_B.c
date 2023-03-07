/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_B.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:26:47 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/18 14:34:15 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 10

char	*ft_reader(int fd)
{
	int					ret;
	char				*si;

	si = (char *) malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	while (read(fd, si, BUFFER_SIZE) != 0)
	{
		si = (char *) malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		ret = read(fd, si, BUFFER_SIZE);
		si[ret + 1] = '\0';
	}
	return (si);
}

char	*ft_stasher(char *si)
{
	static int			n;
	int					i;
	char				*s;
	int					j;

	i = n;
	j = 0;
	while (si[n])
		n++;
	s = (char *) malloc(sizeof(char) * (n));
	while (i <= n)
	{
		s[j] = si[i];
		i++;
		j++;
	}
	s[i] = '\0';
	n = n + 1;
	free(si);
	return (s);
}

char	*ft_caller(int fd)
{	
	int	ret;
	
	return (first_attempt(ft_reader(fd), &ret));
}

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDWR);
	printf("%s", ft_caller(fd));
	printf("%s", ft_caller(fd));
	printf("%s", ft_caller(fd));
	return (0);
}
