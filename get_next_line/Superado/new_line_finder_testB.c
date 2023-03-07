/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line_finder_testB.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:34:34 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/23 09:44:31 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stash_init_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:50:15 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/23 08:31:19 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n])
		n++;
	return (n);
}

char	*ft_strjoin(const char *stash, const char *read_buff)
{
	char	*a;
	size_t	n;
	size_t	i;
	size_t	j;

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
	//free(read_buff);
	return (a);
}

char	*ft_lead_saver(char *stash)
{
	char	*a;
	int		i;

	i = 0;
	while (stash[*n + i + 1])
		i++;
	a = (char *) malloc(sizeof(char *) * (i + 1));
	if (a == NULL)
		return (NULL);
	while (i >= 0)
	{
		a[i] = stash[*n + i + 1];
		i--;
	}
	free(stash);
	return (a);
}

char	*ft_line_seek(char *stash)
{
	int		n;
	int		i;
	char	*aux;

	n = 0;
	while (stash[n])
	{
		if (stash[n] == '\n')
		{
			aux = (char *) malloc(sizeof(char) * (ft_strlen(stash) - n + 1));
			if (aux == NULL)
				return (NULL);
			i = 0;
			while (n <= ft_strlen(stash))
			{
				aux[i] = stash[n + 1];
				i++;
				n++;
			}
			free(stash);
			return (aux);
		}
		n++;
	}
	return (NULL);
}

char	*get_it(char *buff)
{
	static char	*stash;
	char		*a;

	if (stash == NULL)
		stash = "";
	stash = ft_strjoin(stash, buff);
	a = ft_line_seek(stash);
	if (a != NULL)
		stash = ft_lead_saver(stash);
	printf("*%s*\n", stash);
	return (a);
}

int main()
{
	char		*buff;

    buff = "Ya lo lei\nsoy larry";
    printf("%s", get_it(buff));
    return 0;
}
