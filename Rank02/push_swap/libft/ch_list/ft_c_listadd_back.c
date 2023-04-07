/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_listadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:37:53 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/04 16:50:22 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_list.h"

/**
 * @brief 
	This function adds a node to the end of a circular linked list.
	The newly added node shall have head as its next.
	Head shall have the newly added node as its previous.
 	18/03/2023:
 		Currently new node is not being connected to head and last within this
 		function scope.
 		This feature is to be added.
 	20/03/2023:
 		New node connected to head and last nodes. 
 		Working good.
 * @param list 
 * @param new 
 */
void	ft_c_listadd_back(t_clist **list, t_clist *new)
{
	t_clist	*node;
	t_clist	*head;

	node = ft_c_listlast(*list);
	head = *list;
	node->next = new;
	head->prev = new;
	new->next = head;
	new->prev = node;
}
