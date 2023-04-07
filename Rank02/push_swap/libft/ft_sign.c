/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:54:04 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/04 16:21:57 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 	this function works as a boolean to check if each sign precedes 
 	a number, and only a number.
   @version
	04-03-2023:
		Modified to prevent the acceptance of signs preceded by numbers
		(e.g: -9+11) this kind of input now returns Error.
 * 
 * @param s string where to look for the signs
 * @return int 
	TRUE  (1) -> Signs in the string do precede a number
	FALSE (0) -> There are signs in the string that do not precede a number
 */

int	ft_sign(char *s)
{
	int		n;
	char	c;

	n = 0;
	while (s[n])
	{
		c = s[n];
		if ((c == '-' || c == '+') && (n != 0 && ft_isspace(s[n - 1]) == 0))
			return (0);
		if ((c == '-' || c == '+') && ft_isdigit(s[n + 1]) == 0)
			return (0);
		n++;
	}
	return (1);
}
