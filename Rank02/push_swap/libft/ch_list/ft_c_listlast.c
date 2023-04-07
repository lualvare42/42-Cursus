/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_listlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:34:08 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/17 15:36:40 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_list.h"

t_clist	*ft_c_listlast(t_clist *list)
{
	t_clist	*node;
	t_clist	*list_end;

	node = list;
	list_end = list->next;
	while ((list_end != NULL) && (list_end->is_head == NULL))
	{
		if (node != list_end)
			node = node->next;
		list_end = list_end->next;
	}
	return (node);
}
