/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_listsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:23:04 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/24 15:32:01 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_list.h"
/**
 * @brief 
 * 24/03/2023
 Cleaned function, it does not print values anymore.
 Previous version can be found in push_swap_practice
 * @param list 
 * @return int 
 */
int	ft_c_listsize(t_clist *list)
{
	t_clist	*current;
	int		n;

	current = list->next;
	n = 0;
	while (current->is_head == NULL && current)
	{
		current = current->next;
		n++;
	}
	return (n);
}
