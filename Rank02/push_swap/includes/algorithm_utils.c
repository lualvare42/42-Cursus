/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:42:25 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/05 10:28:01 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @ft_to_top:
	Calculates the cost of moving a node to the top of its stack.
		@return
			- positive if the stack should be moved with rotate.
			- negative if the stack should be moved with reverse rotate.
   @ft_push_small:
	Pushes every node from stack_a that is less than stack->is_head->half.
	Rotates the stack if the current node is not less than half, and there 
	are still nodes less than half in the stack.
		
 * @brief 
 	These functions help validate information about a specific node given its
	position or index in the stack.
 * 
 * @ft_position_find: 
 	Finds the position of a node in the stack given its index.
		@return
			- position of the node if found (1 <= position <= n_elements)
			- 0 if the index is not found in the stack.
 * @ft_index_find:
	Finds the index of a node in the stack given its position.
		@return
			- index of the node if found (1 <= index <= n_elements)
			- 0 if the position is not found in the stack.
 * @ft_data_find:
	Finds the data of a node in the stack given its position.
		@return
			- data of the node if found (INT_MIN <= data <= INT_MAX)
			- 0 if the position is not found in the stack.
 */

int	ft_index_find(t_clist *stack, int position)
{
	t_clist	*current;

	current = stack->next;
	while (current->is_head == NULL)
	{
		if (current->position == position)
			return (current->index);
		current = current->next;
	}
	return (0);
}

int	ft_position_find(t_clist *stack, int index, int total_elements)
{
	t_clist	*current;

	if (index > total_elements)
		index = 1;
	if (index < 1)
		index = total_elements;
	current = stack->next;
	while (current->is_head == NULL)
	{
		if (current->index == index)
			return (current->position);
		current = current->next;
	}
	return (0);
}

int	ft_data_find(t_clist *stack, int position)
{
	t_clist	*current;

	current = stack->next;
	while (current->is_head == NULL)
	{
		if (current->position == position)
			return (current->data);
		current = current->next;
	}
	return (0);
}

int	ft_to_top(t_clist *stack, int position)
{
	int	moves;

	moves = 0;
	while (position > 1)
	{
		if (position <= stack->is_head->half)
		{
			position--;
			moves++;
		}
		else
		{
			position++;
			moves--;
		}
		if (position > stack->is_head->n_elements)
			position = 1;
	}
	return (moves);
}

void	ft_push_small(t_clist *stack_a, t_clist *stack_b, int total_elements)
{
	t_clist	*current;
	int		half;

	half = stack_a->is_head->half;
	while (half < stack_a->is_head->n_elements)
	{	
		if (stack_a->next->index < half)
			ft_push(stack_a, stack_b);
		else
			ft_stack_rotate(stack_a, 0);
	}
}
