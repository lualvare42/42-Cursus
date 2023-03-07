/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:41:14 by lualvare          #+#    #+#             */
/*   Updated: 2023/02/28 11:04:41 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_num_len_check(char *s) //If there's anything aside from a number or a space, returns 0
{
	int	n;

	n = 0;
	while ((s[n] >= '0' && s[n] <= '9') || s[n] == ' ')
		n++;
	if (n == (int)ft_strlen(s))
		return (1);
	return (0);
}

int	ft_blank_check(char *s)
{
	int	n;

	n = 0;
	while (s[n] == ' ')
		n++;
	if (n == (int)ft_strlen(s))
		return (1);
	return (0);
}

int	ft_input_check(int argc, char **s)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (ft_num_len_check(s[i]) == 0)
			return (0);
		else if (ft_blank_check(s[i]) == 1)
			return (0);
		else if (ft_strlen(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/*Starting here I am coding input read
1- first step is to determine the size of the integer array (malloc) [Working]
	functions used for 1: ft_num_qty & ft_qty
2- read and store each number in an integer array
*/

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || (c == ' '));
}

int	ft_atoi_index(char *str, int *n)
{
	int	sign;
	int	aux;
	int	test;

	test = *n;
	while (str[*n] && (ft_isspace(str[*n]) == 1))
		*n = *n + 1;
	sign = 1;
	test = *n;
	if (str[*n] == '-')
		sign = -1;
	aux = 0;
	while (str[*n] >= '0' && str[*n] <= '9')
	{
		aux = (str[*n] - '0') + (aux * 10);
		*n = *n + 1;
		test = *n;
	}
	//*n = *n + 1;
	//test = *n;
	return (aux * sign);
}

int	ft_qty(char *s)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[n])
	{
		if ((s[n] >= '0' && s[n] <= '9') && (n == 0 || s[n - 1] == ' '))
			i++;
		n++;
	}
	return (i);
}

int	ft_num_qty(int argc, char **s)
{
	int	i;
	int	n;
	int	aux;

	i = 1;
	aux = 0;
	while (i <= argc - 1)
	{
		n = ft_qty(s[i]);
		aux = aux + n;
		i++;
	}
	return (aux);
}

//A esta función quiero hacerla un void para que simplemente escriba los números dentro del array
 
void	ft_int_array(char **s, int *input) //acá estaba pensando en la lógica para leer varios números dentro de un string " "
{
	static int	n; //Para mantener el número de índice del input
	int			i;
	int			j;
	int			k;

	n = 0;
	i = 1;
	while (s[i])
	{
		j = 0;
		k = 0;
		while (s[i][k])
		{
			input[n] = ft_atoi_index(s[i], &k); //Ahora mismo el input se esta machacando i = 0;
			j++;
			n++;
		}
		i++;
	}
}

// In the loop we'll just call a void function that fills the input
int	*ft_input_read(int argc, char **s)
{
	int	n;
	int	*input;
	int	i;

	n = ft_num_qty(argc, s);
	input = (int *) malloc(sizeof(int) * n);
	if (input == 0)
		return (0);
	i = 1;
	ft_int_array(s, input);
	return (input);
}

int	main(int argc, char **argv)
{
	int	*input;
	int	n;
	int	i;

	if (ft_input_check(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	n = ft_num_qty(argc, argv);
	printf("la cantidad de numeros es %d\n", n);
	input = ft_input_read(argc, argv);
	i = 0;
	while (i < n)
	{
		printf("El numero %d es %d\n", i, input[i]);
		i++;
	}
	return (0);
}
