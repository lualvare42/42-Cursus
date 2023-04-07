/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_greater.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:59:23 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/27 20:14:00 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs_greater(int a, int b)
{
	if (ft_abs(a) > ft_abs(b))
		return (ft_abs(a));
	return (ft_abs(b));
}
