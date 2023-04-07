/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:45:03 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/14 10:46:21 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief This function is a boolean for determining the existence of
 negative or positive ints within a string
 */

int	ft_int(char c)
{
	return ((c >= '0' && c <= '9') || (c == '-' || c == '+'));
}
