/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_head.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:28:39 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/24 16:49:14 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HEAD_H
# define TEST_HEAD_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strjoin(char const *stash, char const *read_buff);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
int		ft_line_check(char *stash);

#endif