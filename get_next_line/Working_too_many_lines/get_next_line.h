/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:28:39 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/30 16:17:29 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *stash, char const *read_buff);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
int		ft_line_check(char *stash);
char	*ft_string_check(char *stash, char const *read_buff);
//char	*ft_strjoin(char /*const*/ **stash, char /*const*/ *read_buff);
//char	*ft_strjoin(char *stash, char *read_buff);

#endif
