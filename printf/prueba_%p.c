/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_%p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:02:44 by lualvare          #+#    #+#             */
/*   Updated: 2023/01/09 12:32:51 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	base_check(char *base)
{
	int	n;

	n = 0;
	while (base[n])
		n++;
	return (n);
}

int	condition_check(char *base, int size)
{
	int	n;
	int	i;

	n = 0;
	while (base[n])
	{	
		if ((base [n] == '+') || (base[n] == '-'))
			return (0);
		i = n + 1;
		while (base[i])
		{
			if (base[n] == base[i])
				return (0);
			i++;
		}
		n++;
	}
	if (size <= 1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	s;
	int	aux;

	n = 0;
	s = 1;
	aux = 0;
	while (str[n] && ((str[n] >= 9 && str[n] <= 13) || str[n] == ' '))
		n++;
	if (str[n] == '-')
	{
		s = -1;
		n++;
	}
	else if (str[n] == '+')
		n++;
	while (str[n] && (str[n] >= 48 && str[n] <= 57))
	{
		aux = (str[n] - 48) + (aux * 10);
		n++;
	}
	return (aux * s);
}

void	ft_recursiva(unsigned int nbr, char *base, int size)
{
	if (nbr >= size)
	{
		ft_recursiva(nbr / size, base, size);
		ft_recursiva(nbr % size, base, size);
	}
	else if (nbr < size)
		write(1, &base[nbr], 1);
}

void	ft_putnbr_base(char *nbr, char *base)
{
	int				size;
	int				x;
	unsigned int	n;

	size = base_check(base);
	x = condition_check(base, size);
	if (x == 0)
		write(1, "", 1);
	else
	{
		n = (unsigned int)ft_atoi(nbr);
		printf("%d\n", n);
		ft_recursiva(n, base, size);
	}
}

int	main(void)
{
	int		i;
	int		j;
	void	*s;
	void	*z;

	s = &i;
	z = &j;
	ft_putnbr_base((char *)s, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base((char *)z, "0123456789abcdef");
	write(1, "\n", 1);
	printf("%p\n", &i);
	printf("%p", &j);
	return (0);
}
