/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:26 by lualvare          #+#    #+#             */
/*   Updated: 2022/12/15 16:51:58 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;
	t_list	*null_finder;

	node = lst;
	null_finder = lst;
	while (null_finder != NULL)
	{
		if (node != null_finder)
			node = node->next;
		null_finder = null_finder->next;
	}
	return (node);
}
