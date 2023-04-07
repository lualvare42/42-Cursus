/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:04:12 by lualvare          #+#    #+#             */
/*   Updated: 2023/03/27 19:14:07 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CH_LIST_H
# define CH_LIST_H
# include "../libft.h"

typedef struct header
{
	int				max;
	int				min;
	int				max_position;
	int				min_position;
	int				n_elements;
	int				half;
	int				is_a;
}					t_lhead;

typedef struct c_list
{
	int				data;
	int				index;
	int				position;
	struct header	*is_head;
	struct c_list	*next;
	struct c_list	*prev;	
}					t_clist;

t_clist	*ft_listhead(int n);
t_clist	*ft_c_listlast(t_clist *list);
void	ft_c_listadd_back(t_clist **list, t_clist *new);
t_clist	*ft_c_list_gen(int value, t_clist *list);
void	ft_circular_check(t_clist *list);
void	ft_listhead_act(t_clist *list);
int		ft_c_listsize(t_clist *list);
int		ft_c_listsize(t_clist *list);
void	ft_circular_check(t_clist *list);
void	ft_c_listadd_front(t_clist **list, t_clist *new);

#endif