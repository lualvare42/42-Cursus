/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_costs_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:35:51 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/05 07:44:27 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief
	This set of functions help determine the most cost efficient moves to make
	in stack_a.
 * @ft_sandwich: 
 	Tells whether the number in stack_b is between the first (greater than b) and 
	last number (less than b) in stack_a (we refer to this arrange as sandwich). 
	If so, the number in stack_b can be pushed to stack_a right away.
		@return (1) TRUE;
		@return (0) FALSE;
 * @ft_next_a:
	Calculates the cost of positioning the number with the next index to the
	number being evaluated in stack_b, on top of stack_a.
		@return Number of moves needed in a
			- Positive if ra is required.
			- Negative if rra is required.
			- INT_MAX if next index to b number is not in stack_a.
 * @ft_prev_a:
	Calculates the cost of positioning the number with the previous index to the
	number being evaluated in stack_b, at the bottom of stack_a.
		@return Number of moves needed in a
			- Positive if ra is required.
			- Negative if rra is required.
			- INT_MAX if next index to b number is not in stack_a.
 * @ft_push_now_moves_a:
	Calculates the cost of positioning the min number in stack_a on top, given 
	that the number being evaluated in stack_b is less than or greater than all 
	the numbers in stack_a.
		@return Number of moves needed in a
			- Positive if ra is required.
			- Negative if rra is required.
			- INT_MAX if next index to b number is not in stack_a.
 * @ft_make_sandwich:
	Calculates the cost of positioning a number that will make stack_a a sandwich
	to the number being evaluated in b, on top of stack_a.
		@return Number of moves needed in a
			- Positive if ra is required.
			- Negative if rra is required.
			- Not possible to make sandwich.
 */

int	ft_sandwich(t_clist *stack_a, int index_b)
{
	t_clist	*current;
	t_clist	*last;

	current = stack_a->next;
	last = stack_a->prev;
	if (index_b >= last->index && index_b <= current->index)
		return (1);
	return (0);
}

int	ft_next_a(t_clist *stack_a, int index_b, int n)
{
	int	position_in_a;
	int	moves_a;

	position_in_a = ft_position_find(stack_a, (index_b + 1), n);
	if (position_in_a == 0)
		return (2147483647);
	moves_a = 0;
	while (position_in_a > 1)
	{
		if (position_in_a <= stack_a->is_head->half)
		{
			position_in_a--;
			moves_a++;
		}
		else
		{
			position_in_a++;
			moves_a--;
		}
		if (position_in_a > stack_a->is_head->n_elements)
			position_in_a = 1;
	}
	return (moves_a);
}

int	ft_prev_a(t_clist *stack_a, int index_b, int n)
{
	int	position_in_a;
	int	moves_a;

	position_in_a = ft_position_find(stack_a, (index_b - 1), n);
	if (position_in_a == 0)
		return (2147483647);
	moves_a = 0;
	while (position_in_a < stack_a->is_head->n_elements)
	{
		if (position_in_a < stack_a->is_head->half)
		{
			position_in_a--;
			moves_a++;
		}
		else
		{
			position_in_a++;
			moves_a--;
		}
		if (position_in_a < 1)
			position_in_a = stack_a->is_head->n_elements;
	}
	return (moves_a);
}

int	ft_push_now_moves_a(t_clist *stack_a, int data_b)
{
	int		min_a;
	int		max_a;
	int		min_position;

	min_a = stack_a->is_head->min;
	min_position = stack_a->is_head->min_position;
	max_a = stack_a->is_head->max;
	if (data_b > max_a || data_b < min_a)
		return (ft_to_top(stack_a, min_position));
	return (2147483647);
}

int	ft_make_sandwich(t_clist *stack_a, int index_b)
{
	t_clist	*current;
	t_clist	*iter;

	current = stack_a->next;
	while (current->next->is_head == NULL)
	{
		iter = current->next;
		if (current->index <= index_b && index_b <= iter->index)
			return (ft_to_top(stack_a, iter->position));
		current = current->next;
	}
	return (2147483647);
}
