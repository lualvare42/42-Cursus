/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:26:47 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/20 08:13:54 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 10

char	*first_attempt(int fd)
{
	static int			n;
	int					ret;
	int					i;
	char				*si;
	char				*s;

	si = (char *) malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	ret = read(fd, si, BUFFER_SIZE);
	si[ret + 1] = '\0';
	i = n;
	while ((si[n] != '\n') && (si[n] != '\0'))
		n++;
	s = (char *) malloc(sizeof(char) * (n - i + 1));
	while (i <= n)
	{
		s[i] = si[i];
		i++;
	}
	s[i] = '\0';
	n = n + 1;
	free(si);
	return (s);
}

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDWR);
	printf("%s", first_attempt(fd));
	printf("%s", first_attempt(fd));
	printf("%s", first_attempt(fd));
	return (0);
}
