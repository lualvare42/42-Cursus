/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:45:26 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/04 17:16:07 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief This brief is for all the functions in stack_utils.c
	- @ft_stack_is_ordered: 
		Checks whether the stack is ordered or not
		@return: IS ORDERED(1), IS NOT ORDERED(0).
	- @ft_indexer: 
		Adds an index to each number in the stack according to its size
		relative to the rest.
	- @ft_positioner:
		Assigns a position to each node in the stack relative to their
		position to the head node.
	- @ft_stack_update:
		Each time a node is moved or deleted, the stack has to be updated.
		ft_indexer is just called once, to preserve the order the numbers should
		be sorted.
		ft_positioner && ft_listhead_act are called each time a stack changes.
	- @ft_free_stack:
		This function helps free all allocated memory after the stack is sorted.
		04-04-2023:
			In while clause, changed the relationship from >= to > because an
			additional loop was being taken.
 * 
 * @param stack 
 * @return int 
 */

int	ft_stack_is_ordered(t_clist *stack)
{
	t_clist	*current;
	t_clist	*iter;

	current = stack->next;
	while (current->is_head == NULL)
	{
		iter = current->next;
		while (iter->is_head == NULL)
		{
			if ((current->data) > (iter->data))
				return (0);
			iter = iter->next;
		}
		current = current->next;
	}
	return (1);
}

void	ft_indexer(t_clist *stack)
{
	t_clist	*current;
	t_clist	*iter;
	int		n;

	current = stack->next;
	while (current->is_head == NULL)
	{
		n = 1;
		iter = stack->next;
		while (iter->is_head == NULL)
		{
			if (current->data > iter->data)
				n++;
			iter = iter->next;
		}
		current->index = n;
		current = current->next;
	}
}

void	ft_positioner(t_clist *stack)
{
	t_clist	*current;
	int		n;

	current = stack->next;
	n = 1;
	while (current->is_head == NULL)
	{
		current->position = n++;
		current = current->next;
	}
}

void	ft_stack_update(t_clist *stack)
{
	if (stack->next->index == 0)
		ft_indexer(stack);
	ft_positioner(stack);
	ft_listhead_act(stack);
}

void	ft_free_stack(t_clist *stack, int total_elements)
{
	t_clist	*current;
	t_lhead	*head;

	head = stack->is_head;
	free(head);
	while (total_elements-- > 0)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
