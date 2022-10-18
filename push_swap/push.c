/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:15:17 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/17 14:44:09 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack)
{
	t_node	*node;

	if (stack->a_size == 0)
		return ;
	node = stack->a_top;
	if (stack->a_size > 1)
	{
		stack->a_top = stack->a_top->next;
		stack->a_top->prev = 0;
	}
	if (stack->b_size == 0)
	{
		node->next = 0;
		stack->b_top = node;
		stack->b_bottom = node;
	}
	else
	{
		node->next = stack->b_top;
		stack->b_top->prev = node;
		stack->b_top = node;
	}
	stack->b_size += 1;
	stack->a_size -= 1;
	if (stack->a_size == 0)
	{
		stack->a_top = 0;
		stack->a_bottom = 0;
	}
	write(1, "pb\n", 3);
}

void	push_a(t_stack *stack)
{
	t_node	*node;

	if (stack->b_size == 0)
		return ;
	node = stack->b_top;
	if (stack->b_size > 1)
	{
		stack->b_top = stack->b_top->next;
		stack->b_top->prev = 0;
	}
	if (stack->a_size == 0)
	{
		node->next = 0;
		stack->a_top = node;
		stack->a_bottom = node;
	}
	else
	{
		node->next = stack->a_top;
		stack->a_top->prev = node;
		stack->a_top = node;
	}
	stack->a_size += 1;
	stack->b_size -= 1;
	if (stack->b_size == 0)
	{
		stack->b_top = 0;
		stack->b_bottom = 0;
	}
	write(1, "pa\n", 3);
}
