/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_listadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:37:53 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/23 18:02:25 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_list.h"

/**
 * @brief 
 * 18/03/2023
 Created today, needs testing
 23/03/2023
 Modified, head->next NULL condition check added.
 * @param list 
 * @param new 
 */
void	ft_c_listadd_front(t_clist **list, t_clist *new)
{
	t_clist	*node;
	t_clist	*head;

	head = *list;
	node = head->next;
	head->next = new;
	new->prev = head;
	if (node != NULL)
	{
		node->prev = new;
		new->next = node;
	}
	else
	{
		head->prev = new;
		new->next = head;
	}
}
