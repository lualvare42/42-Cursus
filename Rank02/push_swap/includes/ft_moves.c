/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:59:43 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/05 10:52:10 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief 
	This set of functions set up stack_a && stack_b, so as to sort them properly
	to push nodes from stack_b.
 * 
 * @ft_moves:
	This function sorts stack_a && stack_b according to the given position 
	of the node in stack_b to be pushed.
		@param moves_two
			moves_two tells whether stack_a && stack_b can be rotated or 
			reverse rotated at the same time (rr or rrr).
			- 0, if moves_a && moves_b have different signs.
			- > 0, if both moves_a && moves_b are positive (rr)
			- < 0, if both moves_a && moves_b are negative (rrr)
 * @ft_mover:
	Rotates or Reverse Rotates a stack a given amount of times (moves).
	Only one stack is moved at a time.
		@param moves
			moves indicates the amount of times a stack is to be rotated
			or reverse rotated.
			- > 0, if stack should be rotated (ra or rb)
			- < 0, if stack should be reverse rotated (rra or rrb)
 * @ft_mover_two:
	Rotates or Reverse Rotates both stacks a given amount of times (moves_two).
		@param moves_two
			moves_two indicates the amount of times both stacks are to be rotated
			or reverse rotated.
			- > 0, if stacks should be rotated (rr)
			- < 0, if stacks should be reverse rotated (rrr)
 * @ft_moves_updater:
	Updates moves_a && moves_b if moves_two != 0.
 */

void	ft_mover(t_clist *stack, int moves)
{
	while (moves < 0)
	{
		ft_stack_reverse(stack, 0);
		moves++;
	}
	while (moves > 0)
	{
		ft_stack_rotate(stack, 0);
		moves--;
	}
}

void	ft_mover_two(t_clist *stack_a, t_clist *stack_b, int moves_two)
{
	while (moves_two < 0)
	{
		ft_simultaneous(stack_a, stack_b, moves_two);
		moves_two++;
	}
	while (moves_two > 0)
	{
		ft_simultaneous(stack_a, stack_b, moves_two);
		moves_two--;
	}
}

void	ft_moves_updater(int *moves_a, int *moves_b, int moves_two)
{
	*moves_a = *moves_a - moves_two;
	*moves_b = *moves_b - moves_two;
}

void	ft_moves(t_clist *stack_a, t_clist *stack_b, int position_in_b, int n)
{
	int	moves_b;
	int	data_b;
	int	index_b;
	int	moves_a;
	int	moves_two;

	moves_b = ft_to_top(stack_b, position_in_b);
	data_b = ft_data_find(stack_b, position_in_b);
	index_b = ft_index_find(stack_b, position_in_b);
	moves_a = ft_moves_a(stack_a, index_b, n, data_b);
	moves_two = 0;
	if ((moves_a * moves_b > 0))
	{
		moves_two = ft_abs_less(moves_a, moves_b);
		ft_moves_updater(&moves_a, &moves_b, moves_two);
	}
	if (moves_two != 0)
		ft_mover_two(stack_a, stack_b, moves_two);
	if (moves_a != 0)
		ft_mover(stack_a, moves_a);
	if (moves_b != 0)
		ft_mover(stack_b, moves_b);
}
