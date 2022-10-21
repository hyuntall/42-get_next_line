/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:09:53 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/21 15:36:53 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*lst;

	lst = (t_node *)malloc(sizeof(t_node));
	if (!lst)
		return (0);
	lst->n = value;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

int	is_unique_list(t_stack *stack, int target)
{
	t_node	node;

	node = *stack->at;
	while (node.next)
	{
		if (node.n == target)
			return (0);
		node = *node.next;
	}
	if (node.n == target)
		return (0);
	return (1);
}

void	first_insert(t_stack *stack, int num)
{
	stack->at = ft_lstnew(num);
	stack->ab = stack->at;
}

void	node_insert(t_stack *stack, int num)
{
	t_node	*new_node;

	if (!is_unique_list(stack, num))
		print_error(stack, "unique error");
	new_node = ft_lstnew(num);
	stack->ab->next = new_node;
	new_node->prev = stack->ab;
	stack->ab = stack->ab->next;
}

void	node_remove(t_node *node)
{
	t_node *temp;

	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}
