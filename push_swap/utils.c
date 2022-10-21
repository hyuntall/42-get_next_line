/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:28:26 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/21 15:36:03 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sort(t_stack *stack)
{
	t_node	*node;

	node = stack->at;
	while (node->next)
	{
		if (node->n > node->next->n)
			return (0);
		node = node->next;
	}
	return (1);
}

void	print_stack(t_stack *stack)
{
	t_node	*a_node;
	t_node	*b_node;
	int		cnt;
	a_node = stack->at;
	b_node = stack->bt;
	cnt = 1;
	while (a_node || b_node)
	{
		if (a_node && b_node)
		{
			printf("%d: a: %-12d,b: %d\n", cnt, a_node->n, b_node->n);
			a_node = a_node->next;
			b_node = b_node->next;
		}
		else if (a_node)
		{
			printf("%d: a: %-12d,b: null\n", cnt, a_node->n);
			a_node = a_node->next;
		}
		else
		{
			printf("%d: a: %-12s,b: %d\n", cnt, "null", b_node->n);
			b_node = b_node->next;
		}
		cnt++;
	}
	printf("------------------------------\n");
}