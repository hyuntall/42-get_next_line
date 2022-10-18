/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:03:20 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/14 14:26:05 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int		first;
	int		second;

	first = stack->a_top->num;
	second = stack->a_top->next->num;
	stack->a_top->num = second;
	stack->a_top->next->num = first;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack)
{
	int		first;
	int		second;

	first = stack->b_top->num;
	second = stack->b_top->next->num;
	stack->b_top->num = second;
	stack->b_top->next->num = first;
	write(1, "sb\n", 3);
}

void	swap_all(t_stack *stack)
{
	int		first;
	int		second;

	first = stack->a_top->num;
	second = stack->a_top->next->num;
	stack->a_top->num = second;
	stack->a_top->next->num = first;
	first = stack->b_top->num;
	second = stack->b_top->next->num;
	stack->b_top->num = second;
	stack->b_top->next->num = first;
	write(1, "ss\n", 3);
}
