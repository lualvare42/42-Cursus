/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_costs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:59:43 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/05 09:50:47 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief 
	This set of functions help determine the most cost efficient way of pushing
	numbers from stack_b to stack_a.
 * 
 * @ft_cost:
	Locates the node position in stack_b that is the most cost efficient
	to push to stack_a.
		@return: Position in stack_b;
 * @ft_moves_cost:
	Calculates the cost of setting up stack_a && stack_b for pushing a given 
	node in stack_b.
		@return: Total number of moves needed to push node in stack_b to stack_a
			- INT_MAX if moves_a is INT_MAX
			- Greater between moves_a & moves_b if both have the same sign.
			- Sum of absolute values of moves_a & moves_b if they have different 
			  signs.
 * @ft_moves_a:
	Calculates the cost of setting up stack_a for a given node in stack_b.
		@return:
			- 0, if ft_sandwich is true.
			- else compare.
 * @ft_moves_a_compare:
	Compares the the cost of each criterion for setting up stack_a, 
	and returns the most cost efficient.
	next and prev are preferable over push_now & make_sandwich, as they
	allow for a neater way of sorting the stack.
 		@return
			The smallest value between next, prev, push_now, and sandwich.
 */

int	ft_moves_a_compare(int next, int prev, int push_now, int sandwich)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = ft_abs(next);
	b = ft_abs(prev);
	c = ft_abs(push_now);
	d = ft_abs(sandwich);
	if (a <= b && a <= c && a <= d)
		return (next);
	else if (b <= a && b <= c && b <= d)
		return (prev);
	else if (c <= a && c <= b && c <= d)
		return (push_now);
	else
		return (sandwich);
}

int	ft_moves_a(t_clist *stack_a, int index_b, int n, int data_b)
{
	int	next;
	int	prev;
	int	push_now;
	int	sandwich;
	int	compare;

	next = ft_next_a(stack_a, index_b, n);
	prev = ft_prev_a(stack_a, index_b, n);
	push_now = ft_push_now_moves_a(stack_a, data_b);
	sandwich = ft_make_sandwich(stack_a, index_b);
	compare = ft_moves_a_compare(next, prev, push_now, sandwich);
	if (ft_sandwich(stack_a, index_b) == 1)
		return (0);
	else
		return (compare);
}

int	ft_moves_cost(t_clist *stack_a, t_clist *stack_b, int position_in_b, int n)
{
	int	moves_b;
	int	data_b;
	int	index_b;
	int	moves_a;

	moves_b = ft_to_top(stack_b, position_in_b);
	data_b = ft_data_find(stack_b, position_in_b);
	index_b = ft_index_find(stack_b, position_in_b);
	moves_a = ft_moves_a(stack_a, index_b, n, data_b);
	if (moves_a == 2147483647)
		return (2147483647);
	else if (moves_a * moves_b >= 0)
		return (ft_abs_greater(moves_a, moves_b));
	else
		return (ft_abs(moves_a) + ft_abs(moves_b));
}

/**
 * @brief 
 	Returns the position in stack_b of the most cost efficient node 
 	to be pushed to stack_a;
	 29-03-2023 (Added lines 128-129):
 		Added condition if (moves <= 1), this will shorten the search since
 		The only posibilities for moves being equal or less than 1 are:
 			- Position 1 in b can be pa'd (moves = 0);
			- Position 2 in b rb & pa || rr & pa (moves = 1);
			- Position Last in b rrb & pa || rrr & pa (moves = 1);
		Thus, once moves <= 1 is TRUE ft_cost should stop.
 * @param i is given a seed of INT_MAX so it takes the number of moves needed for
 the first position
 * @param n is the total of stack_a and stack_b numbers
 * @return int 
 */
int	ft_cost(t_clist *stack_a, t_clist *stack_b, int n)
{
	t_clist	*current;
	int		moves;
	int		position;
	int		i;
	int		position_in_b;

	i = 2147483647;
	position_in_b = 1;
	current = stack_b->next;
	while (current->is_head == NULL)
	{
		moves = ft_moves_cost(stack_a, stack_b, position_in_b, n);
		if (moves < i)
		{
			position = current->position;
			i = moves;
		}
		if (moves <= 1)
			return (position);
		current = current->next;
		position_in_b++;
	}	
	return (position);
}
