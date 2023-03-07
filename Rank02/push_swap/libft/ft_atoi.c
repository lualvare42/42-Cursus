/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:06:37 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/01 17:50:08 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
