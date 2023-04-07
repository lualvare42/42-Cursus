/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listhead_act.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:44:10 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/27 19:16:22 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ch_list.h"

/**
 * @brief this functions works as a bridge to 5 other that update the values
 on the header node.
 21/03/2023
 Adding 4 other functions min, max_position, min_position, n_elements
 * 
 * @param list 
 */
void	ft_listhead_max(t_clist *list)
{
	t_clist	*current;
	t_lhead	*head;
	int		i;

	head = list->is_head;
	current = list->next;
	head->max = current->data;
	i = 1;
	head->max_position = i;
	while (current->is_head == NULL)
	{
		if (current->data > head->max)
		{
			head->max = current->data;
			head->max_position = i;
		}
		current = current->next;
		i++;
	}
}

void	ft_listhead_min(t_clist *list)
{
	t_clist	*current;
	t_lhead	*head;
	int		i;

	head = list->is_head;
	current = list->next;
	head->min = current->data;
	i = 1;
	head->min_position = i;
	while (current->is_head == NULL)
	{
		if (current->data < head->min)
		{
			head->min = current->data;
			head->min_position = i;
		}
		current = current->next;
		i++;
	}
}

void	ft_listhead_act(t_clist *list)
{
	ft_listhead_max(list);
	ft_listhead_min(list);
	list->is_head->n_elements = ft_c_listsize(list);
	list->is_head->half = (list->is_head->n_elements / 2) + 1;
}
