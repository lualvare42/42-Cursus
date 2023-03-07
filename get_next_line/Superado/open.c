/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:26:47 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/25 11:58:59 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 6

int	ft_file_read(int fd)
{
	char	str[BUFFER_SIZE + 1];

	return (read(fd, str, BUFFER_SIZE));
}

int	main(void)
{
	int		fd;
	//const char	*s;	
	char	str[BUFFER_SIZE + 1];
	//char	str1[BUFFER_SIZE + 1];
	int		ret;
	int		test;
	//int		ret2;
	//int		ret3;

	fd = open("test.txt", O_RDWR);
//	close(fd); cerrar el fd para producir el error de read
	ret = read(fd, str, BUFFER_SIZE);
	//test = write(fd, "", 0); //Probar el write con un fd cerrado
	//s = "Hola mi bumby";
	//fd = open(s, O_RDONLY);
	//close (fd);
	//fd = open("test.txt", O_RDWR);
	//ret2 = read(fd, str1, BUFFER_SIZE);
	//close (fd);
	//fd = open("test.txt", O_RDWR);
	//ret3 = read(fd, str, BUFFER_SIZE);
	//str[ret] = '\0';
	printf("%d\n", ret); //Prueba return del read
	//printf("%s\n", str);	//Prueba almacen en buffer del read
	//printf("%d\n", test); //Prueba return del write
	printf("%d\n", ft_file_read(fd)); //Prueba de si read recuerda el offset incluso en llamadas a otras funciones.
	//printf("%d\n", ret2);
	//printf("%d\n", ret3);
	return (0);
}
