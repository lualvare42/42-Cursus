/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_list_gen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:40:02 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/04 16:53:38 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_list.h"

/**
 * @brief 
 	This function generates new nodes for circular linked lists.
	
 	18/03/2023:
 		I've noticed that this node generator will only work for addback
 		operation since
 		node->next = head;
 		node->prev = last;
 		These two lines shall be removed and added to addback & addfront 
		functions updated to include them accordingly.
 	20/03/2023:
 		Deleted next, and prev pointer assignment. 
 		These pointers are to be assigned on addfront/back functions.
 * @param value
 * @param list 
 * @return t_clist* 
 */
t_clist	*ft_c_list_gen(int value, t_clist *list)
{
	t_clist	*node;
	t_clist	*head;
	t_clist	*last;

	head = list;
	last = ft_c_listlast(list);
	node = (t_clist *) malloc(sizeof(t_clist));
	if (node == NULL)
		return (NULL);
	node->data = value;
	node->is_head = NULL;
	return (node);
}
