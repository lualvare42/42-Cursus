/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:15:38 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/07 11:25:15 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief 
	This set of functions comprise the algorithm followed by the push_swap program
	to sort a stack of number.
 * 
 * @ft_algorithm:
	This function dictates the execution of either of the two algorithms, according
	to the amount of numbers on the stack.
 * @ft_sort_three:
	This function sorts a stack that has three nodes.
 * @ft_sort_many:
	This function sorts a stack that has more than three nodes.
 * @ft_stack_a_order:
	After all nodes in stack_a are linked by index, this function finds
 	where the first index is and puts it on top of the stack.
 */

void	ft_sort_three(t_clist *stack_a, int n)
{
	t_lhead	*head_info;

	head_info = stack_a->is_head;
	while (ft_stack_is_ordered(stack_a) == 0)
	{
		if (head_info->max_position == 1)
			ft_stack_rotate(stack_a, 0);
		else if (head_info->max_position == n)
			ft_stack_swap(stack_a);
		else
			ft_stack_reverse(stack_a, 0);
	}
}

void	ft_stack_a_order(t_clist *stack_a, int n)
{
	int	position;

	position = ft_position_find(stack_a, 1, n);
	while (position > 1)
	{
		if (position <= stack_a->is_head->half)
		{
			ft_stack_rotate(stack_a, 0);
			position--;
		}
		else
		{
			ft_stack_reverse(stack_a, 0);
			position++;
		}
		if (position > stack_a->is_head->n_elements)
			position = 1;
	}
}

void	ft_sort_many(t_clist *stack_a, t_clist *stack_b, int n)
{
	t_lhead	*head_info_a;
	t_lhead	*head_info_b;

	head_info_a = stack_a->is_head;
	head_info_b = stack_b->is_head;
	ft_push_small(stack_a, stack_b, n);
	while (head_info_a->n_elements > 3)
	{	
		ft_push(stack_a, stack_b);
	}
	ft_sort_three(stack_a, stack_a->is_head->n_elements);
	while (head_info_b->n_elements != 0)
	{
		if (head_info_b->n_elements != 0)
		{
			ft_moves(stack_a, stack_b, ft_cost(stack_a, stack_b, n), n);
			ft_push(stack_b, stack_a);
		}
	}
	while (ft_stack_is_ordered(stack_a) == 0)
	{
		ft_stack_a_order(stack_a, n);
	}
}

void	ft_algorithm(t_clist *stack_a, t_clist *stack_b)
{
	int	n;

	n = stack_a->is_head->n_elements;
	if (n <= 3)
	{
		ft_sort_three(stack_a, n);
		ft_free_stack(stack_a, n);
	}
	else
	{
		ft_sort_many(stack_a, stack_b, n);
		ft_free_stack(stack_a, n);
		ft_free_stack(stack_b, stack_b->is_head->n_elements);
	}
}
