/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:52:18 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/21 19:09:07 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	node = stack->at;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
}

void	print_error(t_stack	*stack, char *str)
{
	clear_stack(stack);
	write(2, "Error\n", 6);
	write(1, str, ft_strlen(str));
	exit(1);
}
