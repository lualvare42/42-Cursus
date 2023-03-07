/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:27:04 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/31 12:27:48 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"

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