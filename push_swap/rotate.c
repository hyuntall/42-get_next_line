/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:44:04 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/14 16:34:10 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack)
{
	t_node	*node;

	node = stack->a_top;
	stack->a_bottom->next = node;
	stack->a_bottom->next->prev = stack->a_bottom;
	stack->a_bottom = stack->a_bottom->next;
	stack->a_top = stack->a_top->next;
	stack->a_bottom->next = 0;
	stack->a_top->prev = 0;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	t_node	*node;

	node = stack->b_top;
	stack->b_bottom->next = node;
	stack->b_bottom->next->prev = stack->b_bottom;
	stack->b_bottom = stack->b_bottom->next;
	stack->b_top = stack->b_top->next;
	stack->b_bottom->next = 0;
	stack->b_top->prev = 0;
	write(1, "rb\n", 3);
}

void	rotate_all(t_stack *stack)
{
	t_node	*node;

	node = stack->a_top;
	stack->a_bottom->next = node;
	stack->a_bottom->next->prev = stack->a_bottom;
	stack->a_bottom = stack->a_bottom->next;
	stack->a_top = stack->a_top->next;
	stack->a_bottom->next = 0;
	stack->a_top->prev = 0;
	node = stack->b_top;
	stack->b_bottom->next = node;
	stack->b_bottom->next->prev = stack->b_bottom;
	stack->b_bottom = stack->b_bottom->next;
	stack->b_top = stack->b_top->next;
	stack->b_bottom->next = 0;
	stack->b_top->prev = 0;
	write(1, "rr\n", 3);
}