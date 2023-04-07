/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:22:04 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/04 17:50:15 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief 
 * @version
	04/04/2023:
		Previously calling ft_num_qty twice. Since n holds the result, n will
		be passed to ft_dup_inarray.
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	int		*input;
	int		n;
	t_clist	*stack_a;
	t_clist	*stack_b;

	if (argc == 1)
		return (0);
	if (ft_input_check(argc, argv) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	n = ft_num_qty(argc, argv);
	input = ft_input_read(argv, n);
	if (ft_dup_inarray(input, n) == 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_a = ft_stack_a_gen(input, n);
	stack_b = ft_listhead(0);
	ft_algorithm(stack_a, stack_b);
	return (0);
}
