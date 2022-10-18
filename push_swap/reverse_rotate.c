/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:34:50 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/14 17:24:04 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack)
{
	t_node	*node;

	node = stack->a_bottom;
	stack->a_top->prev = node;
	stack->a_top->prev->next = stack->a_top;
	stack->a_top = stack->a_top->prev;
	stack->a_bottom = stack->a_bottom->prev;
	stack->a_top->prev = 0;
	stack->a_bottom->next = 0;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack)
{
	t_node	*node;

	node = stack->b_bottom;
	stack->b_top->prev = node;
	stack->b_top->prev->next = stack->b_top;
	stack->b_top = stack->b_top->prev;
	stack->b_bottom = stack->b_bottom->prev;
	stack->b_top->prev = 0;
	stack->b_bottom->next = 0;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_all(t_stack *stack)
{
	t_node	*node;

	node = stack->a_bottom;
	stack->a_top->prev = node;
	stack->a_top->prev->next = stack->a_top;
	stack->a_top = stack->a_top->prev;
	stack->a_bottom = stack->a_bottom->prev;
	stack->a_top->prev = 0;
	stack->a_bottom->next = 0;
	node = stack->b_bottom;
	stack->b_top->prev = node;
	stack->b_top->prev->next = stack->b_top;
	stack->b_top = stack->b_top->prev;
	stack->b_bottom = stack->b_bottom->prev;
	stack->b_top->prev = 0;
	stack->b_bottom->next = 0;
	write(1, "rrr\n", 4);
}
