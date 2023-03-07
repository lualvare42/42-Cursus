/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_practice copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lualvare <lualvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:55:30 by lualvare          #+#    #+#             */
/*   Updated: 2023/02/15 08:58:33 by lualvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				numbers;
	int				position;
	struct s_list	*next;
}					t_list;

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		n;
	int		k;

	current = lst;
	printf("the node position is %d and its value %d\n", current->position, current->numbers);
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		if (current != NULL)
		{
			k = current->numbers;
			printf("the node position is %d and its value %d\n", current->position, k);
		}
		n++;
	}
	return (n);
}

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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = ft_lstlast(*lst);
	if (node != NULL)
		node->next = new;
	else
		*lst = new;
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

 void	ft_index_adder(t_list *list)
{
	int		n;
	t_list	*aux;

	aux = list;
	n = 0;
	while (aux != NULL)
	{
		aux->position = n++;
		aux = aux->next;
	}	
}

int	main(int argc, char **argv)
{
	int		l[5] = {2, 4, 5, 6, 8};
	int		n;
	t_list	**list;

	n = 0;
	list = (t_list **) malloc(sizeof(t_list) * 5);
	if (list == NULL)
		return (0);
	*list = ft_node_gen(l[n++]);
	while (n < 5)
	{
		ft_lstadd_back(list, ft_node_gen(l[n++]));
		//printf("%d node %d\n", list->numbers, n);
	}
	ft_index_adder(*list);
	printf("the list has %d nodes", ft_lstsize(*list));
	return (0);
}
