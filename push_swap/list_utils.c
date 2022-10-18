/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:09:53 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/14 15:38:02 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*lst;

	lst = (t_node *)malloc(sizeof(t_node));
	if (!lst)
		return (0);
	lst->num = value;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

int	is_unique_list(t_stack *stack, int target)
{
	t_node	node;

	node = *stack->a_top;
	while (node.next)
	{
		if (node.num == target)
			return (0);
		node = *node.next;
	}
	if (node.num == target)
		return (0);
	return (1);
}

void	first_insert(t_stack *stack, int num)
{
	stack->a_top = ft_lstnew(num);
	stack->a_bottom = stack->a_top;
}

void	node_insert(t_stack *stack, int num)
{
	t_node	*new_node;

	if (!is_unique_list(stack, num))
		print_error(stack, "unique error");
	new_node = ft_lstnew(num);
	stack->a_bottom->next = new_node;
	new_node->prev = stack->a_bottom;
	stack->a_bottom = stack->a_bottom->next;
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
