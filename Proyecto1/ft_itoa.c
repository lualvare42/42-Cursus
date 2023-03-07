/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:53:50 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/13 15:01:05 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_counterator(int n, int *i)
{
	if (n == -2147483648)
	{
		*i = *i + 1;
		n = -147483648;
	}
	if (n < 0)
	{
		*i = *i + 1;
		n = -n;
	}
	if (n > 9)
	{
		ft_counterator(n / 10, i);
		ft_counterator(n % 10, i);
	}
	else
		*i = *i + 1;
}

void	ft_fillerator(char *a, int n, int *i)
{
	if (n == -2147483648)
	{
		a[*i] = '-';
		a[*i + 1] = (2 + 48);
		*i = *i + 2;
		n = 147483648;
	}
	if (n < 0)
	{
		a[*i] = '-';
		*i = *i + 1;
		n = -n;
	}
	if (n > 9)
	{
		ft_fillerator(a, n / 10, i);
		ft_fillerator(a, n % 10, i);
	}
	else
	{
		a[*i] = (n + 48);
		*i = *i + 1;
	}
}

char	*ft_itoa(int n)
{
	char	*a;
	int		i;

	i = 0;
	ft_counterator(n, &i);
	a = (char *) malloc(sizeof(char) * (i + 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	ft_fillerator(a, n, &i);
	a[i] = '\0';
	return (a);
}
