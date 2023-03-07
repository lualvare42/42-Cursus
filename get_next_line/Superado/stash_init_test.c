/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stash_init_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:50:15 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/23 10:39:07 by lualvare         ###   ########.fr       */
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

char	*ft_strjoin(const char *s1, const char *s2) //I need to investigate how const char are initialized
{
	char	*a;
	size_t	n;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		s1 = "";
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	a = (char *) malloc(sizeof(char) * (i + j + 1));
	if (a == NULL)
		return (NULL);
	n = 0;
	while (n <= i + j)
	{
		if (n < i)
			a[n] = s1[n];
		else
			a[n] = s2[n - i];
		n++;
	}
	return (a);
}

int	main(void)
{
	static char		*s1;
	char			*s2;

	s2 = "El joven Bumby";
	s1 = ft_strjoin(s1, s2);
	printf("%s", s1);
	return (0);
}
