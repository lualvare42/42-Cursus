/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listhead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:40:42 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/04 16:38:39 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_list.h"

/**
 * @brief This function creates a special header node for a circular linked
 list.
 * 
 * @param n call ft_listhead with n = 0 to initialize it.
 * @return t_clist* 
 */
t_clist	*ft_listhead(int n)
{
	t_lhead	*head_info;
	t_clist	*head;

	head_info = (t_lhead *) malloc(sizeof(t_lhead));
	if (head_info == NULL)
		return (NULL);
	head_info->max = n;
	head_info->min = n;
	head_info->max_position = n;
	head_info->min_position = n;
	head_info->n_elements = n;
	head_info->is_a = n;
	head = (t_clist *) malloc(sizeof(t_clist));
	if (head == NULL)
		return (NULL);
	head->data = n;
	head->is_head = head_info;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
