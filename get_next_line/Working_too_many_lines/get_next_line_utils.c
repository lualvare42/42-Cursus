/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:35:57 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/31 08:14:37 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

char	*ft_strdup(const char *str)
{
	char	*a;
	size_t	n;

	if (str == NULL)
		return (NULL);
	a = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (a == NULL)
		return (NULL);
	n = 0;
	while (*(char *)(str + n))
	{
		a[n] = *(char *)(str + n);
		n++;
	}
	a[n] = '\0';
	return (a);
}

/*char	*ft_strdupper(const char *a, char **stash)
{
	char	*aux;
	size_t	n;

	//free(stash);
	aux = (char *) malloc(sizeof(char) * (ft_strlen(a) + 1));
	if (*stash == NULL)
		return (NULL);
	n = 0;
	while (*(char *)(a + n))
	{
		aux[n] = *(char *)(a + n);
		n++;
	}
	aux[n] = '\0';
	n = 0;
	while (aux[n])
	{
		*(*(stash + 0) + n) = aux[n];
		n++;
	}
	free(aux);
	*(*(stash + 0) + n) = '\0';
	return (NULL);
}*/

int	ft_line_check(char *stash) //voy a hacer que -1 sea el negativo.
{
	int	n;

	n = 0;
	if (stash == NULL)
		return (-1);
	while (stash[n])
	{
		if (stash[n] == '\n')
			return (n);
		n++;
	}
	return (-1);
}

char	*ft_strjoin(char const *stash, char const *read_buff)
{
	char	*a;
	size_t	n;
	size_t	i;
	size_t	j;

	if ((read_buff[0] == '\0') && (stash == NULL)) //|| !read_buff)
		return (NULL);
	else if (stash == NULL)
		stash = "";
	i = ft_strlen(stash);
	j = ft_strlen(read_buff);
	a = (char *) malloc(sizeof(char) * (i + j + 1));
	if (a == NULL)
		return (NULL);
	n = 0;
	while (n <= i + j)
	{
		if (n < i)
			a[n] = stash[n];
		else
			a[n] = read_buff[n - i];
		n++;
	}
	//free((char *)stash);
	return (a);
}

/*char	*ft_strjoin(char *stash, char *read_buff)
{
	char	*a;
	size_t	n;
	size_t	i;
	size_t	j;

	if ((read_buff[0] == '\0') && (stash == NULL))
		return (NULL);
	else if (stash == NULL)
		stash = "";
	i = ft_strlen(stash);
	j = ft_strlen(read_buff);
	a = (char *) malloc(sizeof(char) * (i + j + 1));
	if (a == NULL)
		return (NULL);
	n = 0;
	while (n <= i + j)
	{
		if (n < i)
			a[n] = stash[n];
		else
			a[n] = read_buff[n - i];
		n++;
	}
	free(stash);
	return (a);
}*/

/*char	*ft_strjoin(char **stash, char *read_buff)
{
	char	*a;
	size_t	n;
	size_t	i;
	size_t	j;

	if ((read_buff[0] == '\0') && (*stash == NULL))
		return (NULL);
	else if (*stash == NULL)
		*stash = "";
	i = ft_strlen(*stash);
	j = ft_strlen(read_buff);
	a = (char *) malloc(sizeof(char) * (i + j + 1));
	if (a == NULL)
		return (NULL);
	n = 0;
	while (n <= i + j)
	{
		if (n < i)
			a[n] = *(*(stash + 0) + n);
		else
			a[n] = read_buff[n - i];
		n++;
	}
	ft_strdupper(a, stash);
	free(a);
	return (*stash);
}*/

/*char	*ft_string_check(char *stash, char const *read_buff)
{
	if ((read_buff[0] == '\0') && (stash == NULL))
		return (NULL);
	else if (stash == NULL)
		stash = "";
	return (ft_strjoin(stash, read_buff));
}*/

/* In case of error just copy ft_string_check at the start of ft_strjoin */