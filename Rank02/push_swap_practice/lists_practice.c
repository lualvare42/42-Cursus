/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_practice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:55:30 by lualvare          #+#    #+#             */
/*   Updated: 2023/02/14 10:59:59 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				numbers;
	struct s_list	*next;
}					t_list;

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		n;

	current = lst;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}
	return (n);
}

t_list	*ft_node_gen(int value)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->numbers = value;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	int		l[5] = {2, 4, 5, 6, 8};
	int		n;
	t_list	**list;

	n = 0;
	list = (t_list **) malloc(sizeof(t_list) * 5);
	if (list == NULL)
		return (0);
	list[n] = ft_node_gen(l[n]);
	n++;
	while (n < 5)
	{
		list[n] = ft_node_gen(l[n]);
		//printf("%d node %d\n", list->numbers, n);
		n++;
	}
	printf("the list has %d nodes", ft_lstsize(*list));
	return (0);
}
