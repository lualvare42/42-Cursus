/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:28:39 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/20 10:32:43 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 5

char	*get_next_line(int fd);
char	*ft_stash_store(char *read_buff, char *stash);
char	*ft_freeup(char *stash, char *read_buff, int i);
char	*ft_stash_initializer(char *read_buff, char *stash);
char	*ft_reader(int fd);
char	*ft_line_seek(char *stash, int fd);
int		ft_null_seek(char *stash);
char	*ft_lead_saver(char *stash, int *n);

#endif