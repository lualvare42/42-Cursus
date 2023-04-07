/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:26:29 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/04 17:56:02 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief
	This is where it all begins. stack_a is created.
	- A special header node is assigned to stack_a as its first node.
	- Each integer is added to stack_a in order
	- stack_a->is_head->is_a = 1; Boolean that will help differentiate
	  stack_a from stack_b.
	- ft_stack_update adds relevant data about the stack_a to its header node
	- free(input) to free the memory allocated with malloc for the int array
 * 
 * @param input Array of integers fetched from the input of the program
 * @param num_qty Total amount of integers
 * @return t_clist* 
 */
t_clist	*ft_stack_a_gen(int *input, int num_qty)
{
	t_clist	*stack_a;
	int		n;

	n = 0;
	stack_a = ft_listhead(0);
	while (n < num_qty)
	{
		ft_c_listadd_back(&stack_a, ft_c_list_gen(input[n++], stack_a));
	}
	stack_a->is_head->is_a = 1;
	ft_stack_update(stack_a);
	free(input);
	return (stack_a);
}
