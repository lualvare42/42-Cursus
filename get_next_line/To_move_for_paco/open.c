/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:26:47 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/25 08:53:03 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 5

int	main(void)
{
	int		fd;
	//const char	*s;	
	char	str[BUFFER_SIZE + 1];
	//char	str1[BUFFER_SIZE + 1];
	int		ret;
	//int		ret2;
	//int		ret3;

	fd = open("test.txt", O_RDWR);
	ret = read(fd, str, BUFFER_SIZE);
	//s = "Hola mi bumby";
	//fd = open(s, O_RDONLY);
	//close (fd);
	//fd = open("test.txt", O_RDWR);
	//ret2 = read(fd, str1, BUFFER_SIZE);
	//close (fd);
	//fd = open("test.txt", O_RDWR);
	//ret3 = read(fd, str, BUFFER_SIZE);
	//str[ret] = '\0';
	//printf("%d\n", ret);
	//printf("%s\n", str);
	printf("%d\n", fd);
	//printf("%d\n", ret2);
	//printf("%d\n", ret3);
	return (0);
}
