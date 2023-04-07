/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circular_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:45:43 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/21 07:31:10 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_list.h"

void	ft_circular_check(t_clist *list)
{
	t_clist	*head;
	t_clist	*last;

	head = list;
	last = ft_c_listlast(list);
	if ((last->next == head) && (head->prev == last))
		printf("\nCircular Linked List Working\n");
	else
		printf("\nCircular Linked List NOT Working\n");
}
