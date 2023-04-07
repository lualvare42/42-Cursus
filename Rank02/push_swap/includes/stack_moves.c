/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:26:29 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/05 11:26:29 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief
	This set of functions comprise the basic move mechanisms for the stacks.
 * 
 * @ft_stack_swap:
	Changes position of the first node to the second node and viceversa.
		@param is_a
			Identifies if the swapped stack is stack_a.
			- TRUE, 'sa' is printed.
			- FALSE, 'sb' is printed.
 * @ft_stack_rotate:
	Moves up every node in the stack (first node becomes last node).
		@param is_rr
			Identifies wheter both stacks should be rotated at the same time, 
			thus preventing 'ra' or 'rb' for being printed.
			- 1, ra nor rb should be printed.
			- 0, ra or rb should be printed.
 * @ft_stack_reverse:
 	Moves down every node in the stack (last node becomes first node).
		@param is_rrr
			Identifies wheter both stacks should be reverse rotated at the same 
			time, thus preventing 'rra' or 'rrb' for being printed.
			- 1, rra nor rrb should be printed.
			- 0, rra or rrb should be printed.
 * @ft_simultaneous:
	Moves up or down both stacks simultaneously.
		@param direction
			Identifies wheter the stack should be rotated or reversed.
			- > 0, stacks should be rotated and rr printed.
			- < 0, stacks should be reversed and rrr printed.
 * @ft_push:
	Pushes the first node in donor to receiver.
		@param is_a
			Identifies if the receiver is stack_a.
			- TRUE, 'pa' is printed.
			- FALSE, 'pb' is printed.
 */

void	ft_stack_swap(t_clist *stack)
{
	t_clist	*head;
	t_clist	*n1;
	t_clist	*n2;
	t_clist	*n3;

	head = stack;
	n1 = head->next;
	n2 = n1->next;
	n3 = n2->next;
	head->next = n2;
	n2->prev = head;
	n2->next = n1;
	n1->prev = n2;
	n1->next = n3;
	n3->prev = n1;
	ft_stack_update(stack);
	if (head->is_head->is_a)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ft_stack_rotate(t_clist *stack, int is_rr)
{
	t_clist	*head;
	t_clist	*n1;
	t_clist	*n2;
	t_clist	*last;

	head = stack;
	n1 = head->next;
	n2 = n1->next;
	last = ft_c_listlast(stack);
	head->next = n2;
	n2->prev = head;
	last->next = n1;
	n1->prev = last;
	n1->next = head;
	head->prev = n1;
	ft_stack_update(stack);
	while (is_rr != 1)
	{
		if (head->is_head->is_a)
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
		is_rr = 1;
	}
}

void	ft_stack_reverse(t_clist *stack, int is_rrr)
{
	t_clist	*head;
	t_clist	*n1;
	t_clist	*last;
	t_clist	*penultimate;

	head = stack;
	n1 = head->next;
	last = ft_c_listlast(stack);
	penultimate = last->prev;
	head->next = last;
	last->prev = head;
	last->next = n1;
	n1->prev = last;
	penultimate->next = head;
	head->prev = penultimate;
	ft_stack_update(stack);
	while (is_rrr != 1)
	{
		if (head->is_head->is_a)
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
		is_rrr = 1;
	}
}

void	ft_simultaneous(t_clist *stack_a, t_clist *stack_b, int direction)
{
	if (direction < 0)
	{
		ft_stack_reverse(stack_a, 1);
		ft_stack_reverse(stack_b, 1);
		ft_printf("rrr\n");
	}
	else
	{
		ft_stack_rotate(stack_a, 1);
		ft_stack_rotate(stack_b, 1);
		ft_printf("rr\n");
	}
}

void	ft_push(t_clist *donor, t_clist *receiver)
{
	t_clist	*n1_donor;
	t_clist	*n2_donor;

	n1_donor = donor->next;
	n2_donor = n1_donor->next;
	donor->next = n2_donor;
	n2_donor->prev = donor;
	ft_c_listadd_front(&receiver, n1_donor);
	ft_stack_update(donor);
	ft_stack_update(receiver);
	if (receiver->is_head->is_a)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
