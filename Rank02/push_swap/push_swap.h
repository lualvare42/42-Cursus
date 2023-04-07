/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:26:00 by lualvare          #+#    #+#             */
/*   Updated: 2023/04/05 10:17:08 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ch_list/ch_list.h"
# include "libft/ft_printf/ft_printf.h"

int		ft_input_check(int argc, char **s);
int		ft_blank_check(char *s);
t_clist	*ft_stack_a_gen(int *input, int num_qty);
void	ft_stack_swap(t_clist *stack);
void	ft_stack_rotate(t_clist *stack, int is_rr);
void	ft_stack_reverse(t_clist *stack, int is_rrr);
void	ft_push(t_clist *donor, t_clist *receptor);
int		ft_stack_is_ordered(t_clist *stack);
void	ft_stack_update(t_clist *stack);
void	ft_indexer(t_clist *stack);
void	ft_positioner(t_clist *stack);
void	ft_algorithm(t_clist *stack_a, t_clist *stack_b);
int		ft_cost(t_clist *stack_a, t_clist *stack_b, int n);
int		ft_next_a(t_clist *stack_a, int index_b, int n);
int		ft_moves_b(t_clist *stack_b, int position_in_b);
int		ft_index_find(t_clist *stack, int position);
int		ft_position_find(t_clist *stack, int index, int total_elements);
void	ft_moves(t_clist *stack_a, t_clist *stack_b, int position_in_b, int n);
void	ft_simultaneous(t_clist *stack_a, t_clist *stack_b, int direction);
int		*ft_input_read(char **s, int total_elements);
int		ft_num_qty(int argc, char **s);
void	ft_free_stack(t_clist *stack, int total_elements);
int		ft_prev_a(t_clist *stack_a, int index_b, int n);
int		ft_sandwich(t_clist *stack_a, int index_b);
int		ft_make_sandwich(t_clist *stack_a, int index_b);
void	ft_push_it_now(t_clist *stack_a, t_clist *stack_b);
int		ft_data_find(t_clist *stack, int position);
int		ft_moves_a(t_clist *stack_a, int index_b, int n, int data_b);
void	ft_push_small(t_clist *stack_a, t_clist *stack_b, int total_elements);
int		ft_to_top(t_clist *stack, int position);
int		ft_push_now_moves_a(t_clist *stack_a, int data_b);
int		ft_moves_a_compare(int next, int prev, int push_now, int sandwich);

#endif